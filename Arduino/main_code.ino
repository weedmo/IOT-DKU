#include <SoftwareSerial.h>
#include <Servo.h>

// 초음파 센서 변수
#define trig 12
#define echo 13
int dis = 0;

// 블루투스 및 값 보정 변수
SoftwareSerial btSerial = SoftwareSerial(9,10);
int receive = 0;
int count1 = 0;
int count2 = 0;
int height_tot = 0;
int height1 = 0;
int height2 = 0;

// 모터 변수
Servo servo1;
Servo servo2;

// 부저 변수
int speakerPin = 2;
int length = 28; // the number of notes
char notes[] = "GGAGcB GGAGdc GGxecBA yyedcC";
int beats[] = { 2,2,8,8,8,16,1,2,2,8,8,8,16,1,2,2,8,8,8,8,8,8,16,1,2,2,8,8};
int tempo = 150;

void setup() {
  // 입력 초기화
  Serial.begin(9600);
  btSerial.begin(9600);

  // 모터 변수 저장
  servo1.attach(8);
  servo2.attach(5);

  // 초음파 출력 입력
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // 부저
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  // 블루투스 연결이 되는지 안되는지 + 변수저장(receive)
  if (btSerial.available() > 0)
  {
    receive = btSerial.parseInt();
    Serial.println(receive);
  }

  // 받은 변수를 각 가중치와 합산 무게로 구분하기
  if (receive > 0)
  {
    count2 = (receive % 10) - 1;  // 2번 사료 가중치
    count1 = ((receive % 100 - count2) / 10) - 1; // 1번 사료 가중치
    height_tot = (receive / 100) - 10; // 총 사료 무게(g)

    Serial.print(count1);
    delay(1000);
    Serial.print(count2);
    delay(1000);
    Serial.println(height_tot);
    delay(1000);
  }

  dis = getDistance(); // 거리를 변수 dis로 받는다.
}

// 모터 제어 거리가 30cm 이내일 때 앱으로부터
// 받은 데이터에 맞게 1번 사료와 2번 사료를 적절하게 분배한다.
if (dis <= 30)
{
  sing();
  if (height_tot > 0)
  {
    servo2.write(-180);
    for (int i = 1; i <= count1; i++)
    {
      feed1();
    }
    for (int i = 1; i <= count2; i++)
    {
      feed2();
    }
    exit(0);
  }
}

// 첫번째 먹이를 주는 함수
void feed1()
{
  delay(1000);
  speed1_(90, 0);
  handle1();
  delay(1000);
  speed1(0, 90);
  handle3();
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo2.write(0);
}

// 두번째 먹이를 주는 함수
void feed2()
{
  delay(1000);
  speed1(90, 180);
  handle2();
  delay(1000);
  speed1_(180, 90);
  handle3();
  delay(1000);
  servo2.write(180);
  delay(1000);
  servo2.write(0);
}

// 거리를 받아오는 함수
float getDistance()
{
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // 거리값 저장
  float distance = pulseIn(echo, HIGH) * 17 / 1000;
  return distance;
}

// 모터1 속도제어 +
void speed1(int angle1, int angle2)
{
  for (angle1; angle1 <= angle2; angle1++)
  {
    servo1.write(angle1); // 속도를 서보모터에 적용
    delay(10); // 속도 변화 간격
  }
}

// 모터1 속도제어 -
void speed1_(int angle1, int angle2)
{
  for (angle1; angle1 >= angle2; angle1--)
  {
    servo1.write(angle1); // 속도를 서보모터에 적용
    delay(10); // 속도 변화 간격
  }
}

// 1번 사료 흔들기
void handle1()
{
  for (int i = 0; i <= 3; i++)
  {
    servo1.write(10);
    delay(15);
    servo1.write(0);
    delay(15);
  }
}

// 2번 사료 흔들기
void handle2()
{
  for (int i = 0; i <= 3; i++)
  {
    servo1.write(170);
    delay(15);
    servo1.write(180);
    delay(15);
  }
}

// 중간에서 흔들기
void handle3()
{
  for (int i = 0; i <= 6; i++)
  {
    servo1.write(95);
    delay(15);
    servo1.write(85);
    delay(15);
  }
}

// 노래 관련 함수들
void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration)
{
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C',
                   'D', 'E', 'F', 'G', 'A', 'B', 'x', 'y' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                  956, 834, 765, 593, 466, 346, 224, 655, 715 };
  int SPEE = 5;

  // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++)
  {
    if (names[i] == note)
    {
      int newduration = duration / SPEE;
      playTone(tones[i], newduration);
    }
  }
}

void sing()
{
  for (int i = 0; i < length; i++)
  {
    if (notes[i] == ' ')
    {
      delay(beats[i] * tempo); // rest
    }
    else
    {
      playNote(notes[i], beats[i] * tempo);
    }

    // pause between notes
    delay(tempo);
  }
}
