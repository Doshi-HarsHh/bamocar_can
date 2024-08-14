#include "bamocar_can.h"
#include <SPI.h>
#include <mcp2515.h>

MCP2515 mcp2515(STD_CSPIN);

struct can_frame sendMsg;
sendMsg.can_id  = STD_TXID;
sendMsg.can_dlc = STD_RD_DLC;

struct can_frame recieveMsg;
recieveMsg.can_id = STD_RXID;

void setup(){
  while (!Serial);
  Serial.begin(115200);
  mcp2515.reset();
  mcp2515.setBitrate(STD_BAUD_RATE);
  mcp2515.setNormalMode();
  
  Serial.println("CAN Init Complete");

}
void CanReceive() {

  if (mcp2515.readMessage(&canMsg) == MCP2515::ERROR_OK) {
    if (canMsg.can_id == 0x181) {
      Serial.print(F("|RXID:"));
      
      Serial.print(canMsg.can_id, HEX); 
      Serial.print(F("|  |DLC: "));
      
      Serial.print(canMsg.can_dlc, HEX); 
      Serial.print(F("|  |DATA (HEX): "));
      
      for (int i = 0; i < canMsg.can_dlc; i++) {
        Serial.print(canMsg.data[i], HEX);
        Serial.print(" ");
      }

      
      if (canMsg.can_dlc > 0) {
        Serial.print(F("|  |DATA (DEC): "));
        uint32_t num = 0;
        for (int i = canMsg.can_dlc - 1; i >= 1; i--) {  // Start from byte 1
          num |= static_cast<uint32_t>(canMsg.data[i]) << ((i - 1) * 8);
        }
        Serial.print(num);
      }
      Serial.println("|");
    }
  }
}
