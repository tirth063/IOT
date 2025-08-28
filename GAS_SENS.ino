// Define pin connections
const int gasSensorPin = A1;    // MQ-135 analog output to Arduino A1
const int buzzerPin = 12;       // Piezo buzzer to Arduino digital pin 12
const int threshold = 350;      // Threshold value for buzzer activation

void setup() {
  pinMode(gasSensorPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);   
  Serial.begin(9600);           // For reading values in serial monitor (optional)
}

void loop() {
  int gasValue = analogRead(gasSensorPin); // Read analog value
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  if (gasValue > threshold) {
    tone(buzzerPin, 1000);  // Turn buzzer ON
  } else {
    noTone(buzzerPin);   // Turn buzzer OFF
  }

  delay(500); // Small delay for stability
}
