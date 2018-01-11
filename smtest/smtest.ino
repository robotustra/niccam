/*
  11 Jan 2018.
  Stepped motor test. Just send the pulses to Enable, direction and pulse pins.
  Read 2 input pins and show the status on the output pins
*/

unsigned long currTime;
unsigned long timer;
byte incomingByte;

const int en_pin = 9;
const int dir_pin = 10;
const int pul_pin = 12;
const int alarm = 2;
const int puc = 3;
unsigned int i,j;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(en_pin, OUTPUT);
  digitalWrite(en_pin, LOW);
  pinMode(dir_pin, OUTPUT);
  digitalWrite(dir_pin, LOW);
  pinMode(pul_pin, OUTPUT);
  digitalWrite(pul_pin, LOW);

  pinMode(alarm, INPUT_PULLUP);
  pinMode(puc, INPUT_PULLUP);

  // Fast enough to get command and not to interfer the steppers move.
  Serial.begin(115200);
  //Serial.begin(38400);
  
}

void enable_motors(){
  digitalWrite(en_pin, HIGH);
}

void disable_motors(){
  digitalWrite(en_pin, LOW);
}


// the loop function runs over and over again forever
void loop() {
  currTime = millis();
  // This is a heartbeat, shows that emulator is alive.
  if(currTime > timer)
  {   
    // Sync pulse.      
      timer = currTime + 80;

  }
  // Read command and convert it into steps.
  if (Serial.available() > 0) 
  {
    incomingByte = Serial.read();
    if (incomingByte == '>') { ;; }
  }
  // Move motors (X,Y) (servos, they don't loose steps.)
  enable_motors();
  digitalWrite(dir_pin, HIGH);
  for (i = 0; i<4096; i++){
    digitalWrite(pul_pin, HIGH);
    delay (1);
    digitalWrite(pul_pin, LOW);
    delay (1);
  }
  digitalWrite(dir_pin, LOW);
  for (i = 0; i<4096; i++){
    digitalWrite(pul_pin, HIGH);
    delay (1);
    digitalWrite(pul_pin, LOW);
    delay (1);
  }
  disable_motors();
}

