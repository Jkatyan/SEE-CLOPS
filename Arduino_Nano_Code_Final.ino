#define buttonPin 2
#define red 4
#define green 5
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
   buttonState = 0;
   digitalWrite(red, LOW);
   digitalWrite(green, HIGH);
   while (true){
    digitalWrite(red, LOW);
   digitalWrite(green, HIGH);
   }
  } else {
    // turn LED off:
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  }
}
