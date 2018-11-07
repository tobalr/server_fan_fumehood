const int PIN_BUTTON = 2;
const int PIN_PWM = 1;
const int SPEED_LOW = 220;
const int SPEED_HIGH = 0;
const int SECOND_IN_MS = 1000;
const int HIGH_CYCLE_LENGTH_MS = 10 * SECOND_IN_MS;

//setup
/*
Input voltage 12V

Fan has four wires
Black = GND
Red   = 12V
Yellow= TICK
Green = PWM Control (Full cycle => off, NO_CYCLE/OFF => off)

Fan is connected to power
ATTINY85 VIN is connecte to 12V, Green wire from fan is connected to PIN_PWM.
Push button creates connection between PIN_BUTTON and GND
*/

void setup() {                
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  pinMode(PIN_PWM, OUTPUT); 

  bootBlink();
}

void bootBlink(){
  for(int i = 0 ; i <= 5; i++){
    analogWrite(PIN_PWM,int(255 * (i % 2)));
    delay(50);
  }    
}

void loop() {
  int buttonPressed = digitalRead(PIN_BUTTON);
  if(buttonPressed == LOW){
      analogWrite(PIN_PWM, SPEED_HIGH);
      delay(HIGH_CYCLE_LENGTH_MS);
  }else{
      analogWrite(PIN_PWM, SPEED_LOW);
  }
}