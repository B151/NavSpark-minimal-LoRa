//Tracker_Definitions.h

/*
**************************************************************************************************

*******************************************************************************************************
*/

#ifndef TIMESLOT
#define TIMESLOT 1                 // Transmit offset in seconds ex1 1, ex2 3, ex3 6
#endif

#ifndef TOTAL_SLOTS
#define TOTAL_SLOTS 12              // Transmit period in seconds 
#endif

#ifdef navspark_mini
#define lora_DIO0 5                     //pin connected to DIO0 on LoRa device
#define PLED1 0                        //pin number for Navspark LED 
#define lora_PReset 3                  //pin where LoRa device reset line is connected
#define lora_PNSS 4                    //pin number where the NSS line for the LoRa device is connected



#endif



  
#define lora_DIO0 5                     //pin connected to DIO0 on LoRa device
#define PLED1 0                         //pin number for LED on Tracker
#define lora_PReset 3                   //pin where LoRa device reset line is connected
#define lora_PNSS 4                    //pin number where the NSS line for the LoRa device is connected





#define SwitchOn 1
#define DontSwitch 0
#define Leave0ff 0
#define LeaveOn 1
#define Strip 1
#define NoStrip 0

const char ACK = 'A';
const char LinkReport = 'B';
const char bLinkReport = 'b';          //binary style link report
const char ClearToSend = 'C';
const char ClearToSendCommand = 'c';
const char Error = 'E';                      
const char NoFix = 'F';
const char NoGPS = 'G';
const char GLONASSDetected = 'g';
const char IsLost = 'H';                 //packet to notify of lost status (Help)
const char LongPayload = '$';
const char Memory = 'M';
const char NACK = 'N';
const char NACKCommand = 'n';
const char PowerUp = 'P';            
const char Repeated = 'R';
const char ShortPayload = 'S';
const char Test = 'T';
const char Wakeup = 'W';
const char ResetTracker = 'X';
const char Config1 = 'Y';
const char Config0 = 'Z';
const char WritePacketEEPROM = '0';  //Write bytes to EEPROM 
const char Bind = '#';
const char LMLPayload = 0xff;             //short LML payload; lat,lon,alt !!!was '8'
const char LMLPayload_Repeated = '9';    //short LML payload that has been repeated


const char Broadcast = 0xff;          //broadcast address '*'
const char PacketStart = '$';        //command packets have a payload of at least one byte, so put this at start
const int inter_Packet_delay = 500; 

//default_config byte settings, defined as chars so they appear as ASCII in received packets
const char GPSFix = '0';             //flag bit number to indicate GPS fix
const char GLONASSisoutput = '1';    //flag bit number to indicate GLONASS found
const char FSKRTTYEnable = '2';      //bit num to set in config byte to enable FSK RTTY
const char CheckFence = '3';         //bit number to control whether fence is checked 0 = NoCheck
const char ShortPayloadEnable = '4'; //bit number to control short payload
const char RepeatEnable = '5';       //bit number to control short payload
const char AddressStrip = '6';       //bit number to control Address part of payload, 1 to strip, 0 to allow
const char GPSPowerSave = '7';       //bit when set enables GPS power save.

const byte wait_command = 2;         //base time in seconds to wait for command

const byte runmA = 4;                //used by HAB program  
const byte GPSmA = 27;               //used by HAB program, Ublox MAX8Q 
const byte RXmA = 11;                //used by HAB program
const byte TXmA = 40;                //used by HAB program, 10dBm  
const int GPSShutdownTimemS = 1900;  //Software backup mode takes around 1.9secs to power down
const byte SleepmA = 1;              //approx current in sleep, GPS consumes circa 500uA




