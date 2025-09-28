#define button 2
#define fanPin 8

int fanState = LOW;         // 0 = ปิด, 1 = เปิด
int lastButtonState = HIGH;

void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(fanPin, OUTPUT);        
  digitalWrite(fanPin, fanState);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(button);

  // ตรวจจับการกดปุ่ม (จาก HIGH → LOW)
  if (buttonState == LOW && lastButtonState == HIGH) {
    fanState = !fanState;
    digitalWrite(fanPin, fanState);

    if (fanState == HIGH) {
      Serial.println("FAN ON");
    } else {
      Serial.println("FAN OFF");
    }

    delay(200);
  }

  lastButtonState = buttonState;
}
