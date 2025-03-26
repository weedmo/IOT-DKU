#include <SoftwareSerial.h>

int randNumber1;
int randNumber2;

SoftwareSerial btSerial = SoftwareSerial(9, 10);

int receive = 0;

void setup() {
  Serial.begin(9600);
  btSerial.begin(9600);

  // 아날로그 입력 핀 0이 연결되지 않은 경우 랜덤 아날로그 노이즈로 인해 randomSeed() 호출이 생성
  randomSeed(analogRead(0));
}

void loop() {
  // 0 ~ 150 까지 난수 출력
  randNumber1 = random(150);
  Serial.println(randNumber1);
  btSerial.print("밥통 사료 양 : ");
  btSerial.println(randNumber1);
  delay(1000);
}
