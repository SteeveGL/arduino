
int led = 5;           // the PWM pin the LED is attached to
int brightness = 125;    // how bright the LED is
int brightness_last = 125;
int fadeAmount = 5;    // how many points to fade the LED by

int btnPower = 9;
int btnUp = 8;
int btnDown = 7;

bool btnPowerReleased = 1;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btnPower, INPUT);
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led, brightness);

  if (digitalRead(btnPower) == LOW && btnPowerReleased == 1) {
    btnPowerReleased = 0;
    Power();
  } else if (digitalRead(btnPower) == HIGH) {
    btnPowerReleased = 1;
  }

  if (digitalRead(btnUp) == LOW) {
    Up();
  }

  if (digitalRead(btnDown) == LOW) {
    Down();
  }
  
  delay(30);
}

void Up() {
  if (brightness < 255) {
    brightness = brightness + fadeAmount;
  }
  
  delay(30);
  Serial.println("Up");
  Serial.println(brightness);
}

void Down() {
  if (brightness > 5) {
    brightness = brightness - fadeAmount;
  }
  
  delay(30);
  Serial.println("Down");
  Serial.println(brightness);
}

void Power() {
  if (brightness > 0) {
    brightness_last = brightness;
    brightness = 0;
  } else {
    brightness = brightness_last;
  }
  
  delay(100);
  Serial.println("Power");
  Serial.println(brightness);
}
