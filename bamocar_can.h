#ifndef Bamocar_can_h
#define Bamocar_can_h


#define STD_TXID 0x201  // ID MC will listen to
#define STD_RXID 0x181  // ID MC will MC respond to
#define STD_BAUD_RATE   100000    //Standard Baudrate

// Control Registers
#define REG_ENABLE        0x51    //Disable or Enable transmission
#define REG_REQUEST       0x3D    //Transmission request

// Data Registers
#define REG_STATUS        0x40    //Status of device
#define REG_READY         0xE2    //State of the device

#define REG_N_ACTUAL      0x30    //RPM actual
#define REG_N_CMD         0x31    //RPM command
#define REG_N_MAX         0xC8    //(SPEED_RPMMAX) Maximum rotation speed in turns per minute (Servo)

#define REG_I_ACTUAL      0x20    //Current actual
#define REG_I_DEVICE      0xC6    //Current device
#define REG_I_200PC       0xD9    //Current 200 PC

#define REG_TORQUE        0x90    //Torque reference

#define REG_RAMP_ACC      0x35    //Ramp Acceleration command
#define REG_RAMP_DEC      0xED    //Ramp Deceleration command

#define REG_TEMP_MOTOR    0x49    //Active motor temperature
#define REG_TEMP_IGBT     0x4A    //Active output stage temperature
#define REG_TEMP_AIR      0x4B    //Air temperature in the servo

#define REG_HARD_ENABLED  0xE8    //Hard Enabled State

// Request interval Pre-settings
#define INTVL_IMMEDIATE   0x00    //Get data once
#define INTVL_SUSPEND     0xFF    //Suspend ongoing loops 
#define INTVL_10MS        0xA0    //Recieve data in intervals of 10ms
#define INTVL_100MS       0x64    //Recieve data in intervals of 100ms
#define INTVL_200MS       0xC8    //Recieve data in intervals of 200ms
#define INTVL_250MS       0xFA    //Recieve data in intervals of 250ms

//All function prototypes
void readSpeed(bool data_in_loop);
void readAllTemp(bool data_in_loop);
void readCurrent(bool data_in_loop);
void readVdc_bus(bool data_in_loop);
void readTorqueref(bool data_in_loop);




