int IRSensor = 8;
int isObstical = HIGH;
void setup() {
  pinMode(IRSensor, INPUT);
  Serial.begin(9600); 
  Serial.println("Serial Working");
}

void loop() {
   isObstical = digitalRead(IRSensor); // Set the GPIO as Input
  if (isObstical == Low) // Check if the pin high or not
  {
    Serial.println("Motion Detected!");
  }
  else  {
    Serial.println("Motion Ended!");
  }

delay(2000);
}
