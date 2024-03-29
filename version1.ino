#define BOXSIZE 10 //box size (cm)
#define TRIG 9 //ultra - sending 
#define ECHO 8 //ultra - receiving 
#define BUZZ 4 //buzzer
#define DOOR 2 //magnetic door sensor 

int doorSensor = 0; 

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(DOOR, INPUT_PULLUP);
  
}

void loop() {
  //check the status of door 
  doorSensor = digitalRead(DOOR);
  boolean isClosed = false; 
  
  if(doorSensor!=LOW){ //door is opened
    while(digitalRead(DOOR) != LOW){
      //waiting for a door to close 
    } //door is closed

    //check the box 
    float duration, distance;
    
    digitalWrite(TRIG, HIGH); 
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW); 
    duration = pulseIn(ECHO, HIGH); 
    distance = ((float)(340 * duration) / 10000) / 2; 
    
    boolean hasSth = true;

    //ring the buzzer 
    while(hasSth){
      if (digitalRead(DOOR) != LOW) { // stops when door is opened again
        break;
      } 
      tone(BUZZ, 500, 100);
      delay(1000); 
      digitalWrite(TRIG, HIGH);
      delayMicroseconds(10);
      digitalWrite(TRIG, LOW); 
      duration = pulseIn(ECHO, HIGH);
      distance = ((float)(340 * duration) / 10000) / 2; 
      hasSth = distance < 10;
      delay(2);
    }
  }
}
