
int Led_pin = 9;
int Pot_pin = A0;

void setup() {
pinMode(Led_pin,OUTPUT);  
Serial.begin(9600);
}
void loop() {
int potValue = analogRead(Pot_pin);
int brightness = potValue/4 ;
analogWrite(Led_pin, brightness);
Serial.println(potValue);
delay(1000); // add a delay to avoid sending data too fast
}
