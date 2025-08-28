int RED = 13;
int GRE 12;
int YEW 11;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GRE, OUTPUT);
  pinMode(YEW, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int Svalue = analogRead(A0);
  Serial.print("Value is = ");
  Serial.println(Svalue);

  if (Svalue < 100) {
    digitalWrite(RED, HIGH); // Turn ON LED on pin 13
    digitalWrite(GRE, LOW); 
    digitalWrite(YEW, LOW); 
  } else if (Svalue < 200) {
    digitalWrite(RED, LOW);
    digitalWrite(GRE, HIGH); // Turn ON LED on pin 12
    digitalWrite(YEW, LOW);
  } else {
    digitalWrite(RED, LOW);
    digitalWrite(GRE, LOW); 
    digitalWrite(YEW, HIGH); // Turn ON LED on pin 11
  }

  delay(100);
}
