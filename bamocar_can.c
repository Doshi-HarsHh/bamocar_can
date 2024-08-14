#include "bamocar_can.h"

void requestData(int Register, int time_var ){
  sendMsg.data[0]=0x3D;
  sendMsg.data[1]=Register;
  sendMsg.data[2]=time_var;
  mcp2515.sendMessage(&sendMsg);  
}
// void setData(){
  
// }
//complete all the required func
