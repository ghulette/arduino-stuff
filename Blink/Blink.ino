int ledPin    = 9;
int delayTime = 5;
int minVal    = 20;
int maxVal    = 255;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i = minVal; i < maxVal; i++) {
    analogWrite(ledPin,i);
    delay(delayTime);
  }
  for(int i = maxVal; i > minVal; i--) {
    analogWrite(ledPin,i);
    delay(delayTime);
  }
}

