
int led_1 = 16;
int led_2 = 14;
int buttonPin = 12;
int buttonState = 0;
int state = 0;
int process = 0;

void setup() {
  //  pinMode(LED_BUILTIN, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  buttonState = digitalRead(buttonPin);
  //  Serial.println(buttonState);
  if (buttonState == 0) {
    if (process == 0) {
      if (state == 0) {
        state = 1;
      } else if (state == 1) {
        state = 2;
      } else {
        state = 0;
      }
      process = 1;
    }
  }
  
  Serial.print("State = ");
  Serial.println(state);
  Serial.print("Process = ");
  Serial.println(process);
  
  if (process == 1) {
    if (state == 1) {
      digitalWrite(led_1, HIGH);
      delay(3000);
      digitalWrite(led_2, HIGH);
    } else if (state == 2) {
      digitalWrite(led_2, LOW);
      delay(3000);
      digitalWrite(led_1, LOW);
    }
    process = 0;
  }
}
