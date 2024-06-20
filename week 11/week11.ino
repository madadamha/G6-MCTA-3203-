const int analogPin = A0; 
int sensorValue; 
float filteredValue = 0.0; 
float alpha = 0.1; // Adjust this value for filter strength 
 
void setup() { 
  Serial.begin(9600); 
} 
 
void loop() { 
  // Read analog data from the sensor 
  sensorValue = analogRead(analogPin); 
 
  // Apply low-pass filter 
  filteredValue = alpha * sensorValue + (1 - alpha) * filteredValue; 
 
  // Print the results 
  Serial.print("Original:"); 
  Serial.print(sensorValue);
 // Serial.print(","); 
  Serial.print("\tFiltered:"); 
  Serial.println(filteredValue); 
 
  delay(100); // Adjust the delay based on your sampling rate 
}