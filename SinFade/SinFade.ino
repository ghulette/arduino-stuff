int potPin = 0;
int ledPin = 9;

#define MIN_DELAY (5)
#define MAX_DELAY (25)

#define NUM_VALS (100)
float values[NUM_VALS]; // Values 0.0 to 1.0

int delayTime;

void setDelay() {
  int potVal = analogRead(potPin);
  float potDval = (float)potVal / 1024.0;
  delayTime = potDval * (float)(MAX_DELAY - MIN_DELAY) + MIN_DELAY;
}

void setup() {
  pinMode(ledPin, OUTPUT);
  delayTime = 5;
  double inc = 2.0 * PI / (double)NUM_VALS;
  for(int i=0; i < NUM_VALS; i++) {
    double x = -PI + (i * inc);
    values[i] = ((sin(x) / 2.0) + 0.5);
  }
}

void loop() {
  for(int i=0; i < NUM_VALS; i++) {
    double v = values[i];
    int d = (int)(v * 250.0 + 5.0);
    analogWrite(ledPin,d);
    setDelay();
    delay(delayTime);
  }
}

