#include "bamocar_can.h"

void requestData(int Register, int interval )
{
  sendMsg.data[0]=0x3D;
  sendMsg.data[1]=Register;
  sendMsg.data[2]=interval;
  mcp2515.sendMessage(&sendMsg);  
}
void printMsg_serial(can_frame &recievedMsg){
   if (mcp2515.readMessage(&recievedMsg) == MCP2515::ERROR_OK) {
    if (recievedMsg.can_id == 0x181) {
      Serial.print(F("|RXID:"));
      
      Serial.print(recievedMsg.can_id, HEX); 
      Serial.print(F("|  |DLC: "));
      
      Serial.print(recievedMsg.can_dlc, HEX); 
      Serial.print(F("|  |DATA (HEX): "));
      
      for (int i = 0; i < recievedMsg.can_dlc; i++) {
        Serial.print(recievedMsg.data[i], HEX);
        Serial.print(" ");
      }
      if (recievedMsg.can_dlc > 0) {
        Serial.print(F("|  |DATA (DEC): "));
        uint32_t num = 0;
        for (int i = recievedMsg.can_dlc - 1; i >= 1; i--) {  // Start from byte 1
          num |= static_cast<uint32_t>(recievedMsg.data[i]) << ((i - 1) * 8);
        }
        Serial.print(num);
      }
      Serial.println("|");
    }
  } 
}

void setREG(uint8_t registerID, uint32_t value, can_frame &sendMsg) {
    msg.data[0] = registerID;

    if (decimalValue <= UINT16_MAX) {
        sendMsg.can_dlc = 4;
        sendMsg.data[1] = decimalValue & 0xFF;
        sendMsg.data[2] = (decimalValue >> 8) & 0xFF;
    } else {
        sendMsg.can_dlc = 6;
        sendMsg.data[1] = decimalValue & 0xFF;
        sendMsg.data[2] = (decimalValue >> 8) & 0xFF;
        sendMsg.data[3] = (decimalValue >> 16) & 0xFF;
        sendMsg.data[4] = (decimalValue >> 24) & 0xFF;
    }
}
int16_t getReceived16Bit(can_frame &recievedMsg) {
    int16_t returnValue;
    returnValue = recievedMsg.data[1];
    returnValue |= (recievedMsg.data[2] << 8);
    return returnValue;
}
int32_t getReceived32Bit(can_frame &recievedMsg) {
    int32_t returnValue;
    returnValue = recievedMsg.data[1];
    returnValue |= (recievedMsg.data[2] << 8);
    returnValue |= (recievedMsg.data[3] << 16);
    returnValue |= (recievedMsg.data[4] << 24);
    return returnValue;
}
bool requestCurrent(uint8_t interval) {
    bool success = true;
    if (!requestData(REG_I_ACTUAL, interval))
        success = false;

    if (!requestData(REG_I_DEVICE, interval))
        success = false;

    if (!requestData(REG_I_200PC, interval))
        success = false;

    return success;
}
bool requestTemp(uint8_t interval){
      bool success = true;
    if (!requestData(REG_TEMP_MOTOR, interval))
        success = false;

    if (!requestData(REG_TEMP_AIR, interval))
        success = false;

    if (!requestData(REG_TEMP_IGBT, interval))
        success = false;

    return success;
}

/*
requestAlldata()
if rxid==0x181 then,
Byte0 ==REGID
check if dlc==4 or dlc==6
if 4-->
  */
void requestAllreg(){
if(RXID==0x181){
  int64_t recievedata;
  uint8_t Register;
  recievedMsg.data[0] == Register;
  
}
}
