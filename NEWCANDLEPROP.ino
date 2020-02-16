

int mic1 = A1;
int led1 = 11;
int micstate1;
int ledstate1;

int mic2 = A2;
int led2 = 9;
int micstate2;
int ledstate2;

int mic3 = A3;
int led3 = 7;
int micstate3;
int ledstate3;

int mic4 = A4;
int led4 = 5;
int micstate4;
int ledstate4;

int magnet = 22;
int magnetstate;

int pwcount;
byte combination[] = "2413";
byte userInput[4];

int pwcountReset;

int propstate;

void setup() {

  pinMode (mic1, INPUT_PULLUP);
  pinMode (led1, OUTPUT);

  pinMode (mic2, INPUT_PULLUP);
  pinMode (led2, OUTPUT);

  pinMode (mic3, INPUT_PULLUP);
  pinMode (led3, OUTPUT);

  pinMode (mic4, INPUT_PULLUP);
  pinMode (led4, OUTPUT);

  pinMode (magnet, OUTPUT);

  digitalWrite (led1, HIGH);
  digitalWrite (led2, HIGH);
  digitalWrite (led3, HIGH);
  digitalWrite (led4, HIGH);
  digitalWrite (magnet, LOW);

  ledstate1 = 1;
  ledstate2 = 1;
  ledstate3 = 1;
  ledstate4 = 1;

  propstate = 1;

  Serial.begin(115200);

  delay(1000);
}

void loop() {

  micstate1 = analogRead(mic1);
  micstate2 = analogRead(mic2);
  micstate3 = analogRead(mic3);
  micstate4 = analogRead(mic4);

  magnetstate = digitalRead(magnet);



  Serial.print("  M1 = ");
  Serial.println(micstate1);
  Serial.print("                            M2 = ");
  Serial.println(micstate2);
  Serial.print("                                                      M3 = ");
  Serial.println(micstate3);
  Serial.print("                                                                                M4 = ");
  Serial.println(micstate4);
  Serial.print("               LED1 = ");
  Serial.println(ledstate1);
  Serial.print("                                        LED2 = ");
  Serial.println(ledstate2);
  Serial.print("                                                                  LED3 = ");
  Serial.println(ledstate3);
  Serial.print("                                                                                            LED4 = ");
  Serial.println(ledstate4);

  Serial.print("                                                                                                           Password Count = ");
  Serial.println(pwcount);

  Serial.print("                                                                                                                                     Propstate = ");
  Serial.println(propstate);

  if (micstate1 < 75 && ledstate1 == 1) {

    digitalWrite(led1, LOW);
    ledstate1 = 0;
    userInput[pwcount] = '1';
    pwcount++;
    // delay(10);
    Serial.print('1');

  }

  if (micstate2 < 90 && ledstate2 == 1) {

    digitalWrite(led2, LOW);
    ledstate2 = 0;
    userInput[pwcount] = '2';
    pwcount++;
    //delay(10);
    Serial.print('2');

  }

  if (micstate3 > 50 && ledstate3 == 1) {

    digitalWrite(led3, LOW);
    ledstate3 = 0;
    userInput[pwcount] = '3';
    pwcount++;
    // delay(10);
    Serial.print('3');

  }

  if (micstate4 < 95 && ledstate4 == 1) {

    digitalWrite(led4, LOW);
    ledstate4 = 0;
    userInput[pwcount] = '4';
    pwcount++;
    // delay(10);
    Serial.print('4');

  }

  if (micstate1 > 120 && propstate == 0) {

    pwcountReset++;

  }

  if (pwcountReset > 15 && propstate == 0) {

    candleReset();
    digitalWrite(magnet, LOW);
    propstate = 1;
    pwcountReset = 0;
    delay(1000);
  }


  for (byte n = 0; n <= 4; n++) {

    if (userInput[n] == combination[n] && pwcount >= 4) {
      digitalWrite(magnet, HIGH);
      Serial.println("UNLOCKED");
      propstate = 0;
      Serial.print("Propstate = ");
      Serial.println(propstate);
      pwcount = 0;

    }
    else {
      if (userInput[n] != combination[n] && pwcount >= 4) {
        digitalWrite(magnet, LOW);
        Serial.println(" - WRONG PASSWORD");
        candleReset();
        pwcount = 0;
        n = 0;
      }
    }
    return;
  }

}

void candleReset() {

  delay(1000);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(250);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  delay(250);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(250);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  ledstate1 = 1;
  ledstate2 = 1;
  ledstate3 = 1;
  ledstate4 = 1;

}





















/*

  R.I.P. NEWCANDLEPROP  1.0

  laid to rest by grant bloom 7/10/2019 6:17pm smh

  int c1 = 11;
  int state1 = 0;
  int c2 = 10;
  int state2 = 0;
  int c3 = 9;
  int state3 = 0;
  int c4 = 8;
  int state4 = 0;

  int mag = 7;
  int stateMag = 0;

  int power = 12;

  void setup() {

  pinMode (c1, INPUT);
  pinMode (c2, INPUT);
  pinMode (c3, INPUT);
  pinMode (c4, INPUT);
  pinMode (mag, INPUT);
  pinMode (power, OUTPUT);

  digitalWrite (power, HIGH);

  Serial.begin(9600);

  }

  void loop() {

  state1 = digitalRead(c1);
  state2 = digitalRead(c2);
  state3 = digitalRead(c3);
  state4 = digitalRead(c4);

  if (state1 == 0 && state2 == 0 && state3 == 0 && state4 == 0 && mag > 0){

  digitalWrite(power, LOW);
  delay(1000);
  digitalWrite(power, HIGH);
  delay(50);


  }

  else {
  digitalWrite(power, HIGH);

  }

  Serial.print("Candle 1 = ");
  Serial.println(state1);

  Serial.print("                Candle 2 = ");
  Serial.println(state2);

  Serial.print("                                Candle 3 = ");
  Serial.println(state3);

  Serial.print("                                                Candle 4 = ");
  Serial.println(state4);

  Serial.print("                                                                Power = ");
  Serial.println(power);
  }

*/
