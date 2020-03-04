const int ledPin = 5;
const int buttonPin = 15;

int buttonState = 0;
bool onAndOff = 0;
long _time = 0;
long debounce = 200;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  
  if (buttonState == HIGH && millis()-_time > debounce) {
    if (onAndOff == false) {
      onAndOff = true;
      digitalWrite(ledPin, HIGH);     
    } else {
      onAndOff = false;
      digitalWrite(ledPin, LOW);
    }
    _time = millis();
  }
}
