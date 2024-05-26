void setup() {
  Serial.begin(9600);
}

void loop() {
  int ldr_value = analogRead(A0); // Read the analog value from the LDR sensor
  float ldr_percent = (ldr_value / 1023.0) * 100; // Convert the analog value to a percentage

  int temp_pin = analogRead(A1); // Read the analog value from the LM35 temperature sensor
  float temp = (temp_pin * 5.0 / 1023.0 - 0.5) * 100; // Convert the analog value to a temperature in Celsius

  Serial.print("DATA,MILLIS,");
  Serial.print(millis());
  Serial.print(",");
  Serial.print(temp);
  Serial.print(",");
  Serial.print(ldr_percent);
  Serial.println();

  delay(1000);
}
