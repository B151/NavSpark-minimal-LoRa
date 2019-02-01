#define programname "navsparkmini_minimal_lora_tracker "
#define programversion "V0.1"
#define dateproduced "12102018"


//#define LoRaTracker_Locator1                         //specify PCB type
#define navspark_mini
/*
 
*/
char buf[32];
#include <sti_gnss_lib.h>
#include <GNSS.h>
#include <Arduino.h>
#include "wiring_digital.h" 
#include <SPI.h>



#define Timeout

#define Frequency1 434.250                   //main frequency
#define FreqOffset 0.0                       //adjustment for frequency in Mhz, assumed at room temp
#define TXPower 10                           //transmit power in dBm, 10 = 10dBm = 10mW
#define ThisNode 0xFF                         //Node number as ASCII character for this device

#define Output_len_max 126                   //max length of outgoing packet


#include "Tracker_Definitions.h"
#include "LoRa.h"







//Program Variables
unsigned int packet_counter = 0;


//unsigned int GPSFixes = 0;                   //count of number of valid GPS Fixes
//unsigned long int GPSErrors = 0;             //to be able to check if GPS Still working


int led_cycle_time = -1, led_on_time = -1;
long int last_cycle;

void change_led(int ct, int ot)
{
  if ((ct != led_cycle_time) || (ot != led_on_time))
    last_cycle = int((double)millis() / ct) * ct;
  led_cycle_time = ct;
  led_on_time = ot;
}
////////////////////////////////////////////////////////////////////////////
void setup()
{ 
  GnssConf.setNavMode(STGNSS_NAV_MODE_BALLOON);
  GnssConf.init();
   
    int len = sprintf(buf, "Navspark LoRa tracker, %s\r\n",programversion);
    gnss_uart_putline(0, (U08*)buf, len); 
   
   /*  The allowed values are listed below.
STGNSS_NAV_MODE_AUTO (default)
STGNSS_NAV_MODE_PEDESTRIAN
STGNSS_NAV_MODE_CAR
STGNSS_NAV_MODE_MARINE
STGNSS_NAV_MODE_BALLOON  _ height?
STGNSS_NAV_MODE_AIRBORNE*/

 pinMode(PLED1, OUTPUT);        //setup pin for PCB LED
 pinMode(lora_PReset, OUTPUT);
 pinMode(lora_PNSS, OUTPUT);
 digitalWrite(lora_PNSS, HIGH);
  change_led(2000, 100);
 //led_FlashStart();

  SPI.begin();
  init_LoRa();                //do the initial LoRa Setup



}

/////////////////////////////////////////////////////////////////////////////


void loop()
{
long int now = millis();
  while (now - last_cycle >= led_cycle_time)
    last_cycle += led_cycle_time;

  if (now - last_cycle < led_on_time)
    digitalWrite(PLED1, HIGH);
  else
    digitalWrite(PLED1, LOW);
 
}
/////////////////////////////////////////////////////////////////////////////
void task_called_after_GNSS_update(void)
{
  GnssInfo.update();
  //if (!GnssInfo.isUpdated())

  // we are lost. send help with OOK or something..
  //  return;
  // LED flash if GNSS is in lock
 if (GnssInfo.fixMode()>1)
  {
change_led(500,250); // cycle_time, on_time
    }

        if (timeslot_go()) {
             SendLocation(GnssInfo.location.latitude(), GnssInfo.location.longitude(), GnssInfo.altitude.meters());
  packet_counter++;
}
// uncomment for GNSS test
// int len = sprintf(buf, "GPS, %6f,%6f,%6f\r\n",GnssInfo.location.latitude(),GnssInfo.location.longitude(),GnssInfo.altitude.meters());
 int len = sprintf(buf, "Fixmode, %d\r\n",GnssInfo.fixMode());
 gnss_uart_putline(0, (U08*)buf, len); 

          // time in format 12:23:45PM
          int sizeOfString = GnssInfo.time.formatString(buf);
          gnss_uart_putline(0, (U08*)buf, sizeOfString); 

}

//////////////////////////////////////////////////////////////////////////////
bool timeslot_go() {
    static uint8_t last_second = 0xFF;

    // Is it still the same second as previously?
    if ( GnssInfo.time.second() == last_second) return false;
    
    last_second =  GnssInfo.time.second();

    return (( GnssInfo.time.second() % TOTAL_SLOTS) == TIMESLOT);
}

void PrintPayload(byte lCount)
{
  //print the received payload to serial monitor
  int i;

  for (i = 0; i <= lCount; i++)
  {
   // Serial1.write(lora_TXBUFF[i]);
      int len = sprintf(buf,"%c",lora_TXBUFF[i]);
      gnss_uart_putline(0, (U08*)buf, len); 
  }
  // new line
  int len = sprintf(buf, "\r\n");
  gnss_uart_putline(0, (U08*)buf, len); 
}



/*void led_FlashStart()
{
  //flash LED to show tracker is alive
  byte i;

  for (i = 0; i <= 5; i++)
  {
    digitalWrite(PLED1, HIGH);
    delay(100);
    digitalWrite(PLED1, LOW);
    delay(100);
  }
}
void led_Flash()
{
  //flash LED to show tracker is alive
 
    digitalWrite(PLED1, HIGH);
    delay(500);
    digitalWrite(PLED1, LOW);
  
}
*/

void setup_LoRa_for_Data()
{
  //set uop the appropriate LoRa modem settings
  init_LoRaZinoo();
}


//////////////////////////////////////////////////////////////////////////
//Packet transmits
//////////////////////////////////////////////////////////////////////////


/*void SendisLost()
{
  //send an IsLost packet to notify RX that tracker is lost
  GPSErrors = 0;
  setup_LoRa_for_Data();
  lora_TXBUFF[0] = 0;
  lora_Send(0, 0, IsLost, '*', ThisNode, 10, TXPower);	         //send a lost mode message
}
*/
void SendLocation(float Tlat, float Tlng, float Talt)
{
  //send the current GPS location as LoRa
  int Count;

  GPSErrors = 0;
  char LatString[12], LonString[12], AltString[10];
  dtostrf(Tlat, 7, 5, LatString);
  dtostrf(Tlng, 7, 5, LonString);
  dtostrf(Talt, 0, 0, AltString);
  snprintf(lora_TXBUFF,
           Output_len_max,
           "$Nav1,%d,%02d:%02d:%02d,%s,%s,%s"
           ,packet_counter,
           GnssInfo.time.hour(),
           GnssInfo.time.minute(),
           GnssInfo.time.second(),
           LatString,
           LonString,
           AltString
          );
  Count = strlen(lora_TXBUFF);  //how long is the array ?

PrintPayload(Count);

  setup_LoRa_for_Data();
  lora_Send(0, Count, LMLPayload, Broadcast, ThisNode, 10, TXPower);   //send the packet, data is in TXbuff from lora_TXStart to lora_TXEnd
  //lora_Send(byte lora_LTXStart, byte lora_LTXEnd, char lora_LTXPacketType, char lora_LTXDestination, char lora_LTXSource, long lora_LTXTimeout, byte lora_LTXPower)

  //Serial.println();
}


////////////////////////////////////////////////////////////////////////
//dtostrf

char *dtostrf (float val, signed char width, unsigned char prec, char *sout) {
  char fmt[20];
  sprintf(fmt, "%%%d.%df", width, prec);
  sprintf(sout, fmt, val);
  return sout;
}


