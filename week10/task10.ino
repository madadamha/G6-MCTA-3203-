#include <ModbusRTU.h>

ModbusRTU mb;

const int BUTTON_PIN = 2;  // Pin where the button is connected

bool cbRead(Modbus::ResultCode event, uint16_t transactionId, void* data) {
  return true;
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Button pin as input with internal pull-up
  
  mb.begin(&Serial, 9600);
  mb.slave(1); // Slave ID
  
  mb.addHreg(1000); // Register for button state
}

void loop() {
  mb.task();
  
  int buttonState = digitalRead(BUTTON_PIN);
  mb.Hreg(1000, buttonState);
  
  delay(100);
}
