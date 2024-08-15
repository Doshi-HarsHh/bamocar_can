#include "bamocar_can.h"

void setup(){
  while (!Serial);
  Serial.begin(115200);
  mcp2515.reset();
  mcp2515.setBitrate(STD_BAUD_RATE);
  mcp2515.setNormalMode();
  Serial.println("CAN Init Complete");

}
void loop(){
  //Yet to add
}
