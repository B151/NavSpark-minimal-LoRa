//LoRa.h
/*


Copyright of the author Stuart Robinson - 11/04/16

These programs may be used free of charge for personal, recreational and educational purposes only.

This program, or parts of it, may not be used for or in connection with any commercial purpose without
the explicit permission of the author Stuart Robinson.

The programs are supplied as is, it is up to individual to decide if the programs are suitable for the
intended purpose and free from errors.

*/



/*
**************************************************************************************************
Constant definitions
**************************************************************************************************
*/

//LoRa names for bandwidth settings
const byte lora_BW7_8 = 0;      //7.8khz
const byte lora_BW10_4 = 16;    //10.4khz
const byte lora_BW15_6 = 32;    //15.6khz
const byte lora_BW20_8 = 48;    //20.8khz
const byte lora_BW31_2 = 64;    //31.2khz
const byte lora_BW41_7 = 80;    //41.7khz
const byte lora_BW62_5 = 96;    //62.5khz
const byte lora_BW125 = 112;    //125khz
const byte lora_BW250 = 128;    //250khz
const byte lora_BW500 = 144;    //500khz

//Spreading Factors
const byte lora_SF6 = 6;
const byte lora_SF7 = 7;
const byte lora_SF8 = 8;
const byte lora_SF9 = 9;
const byte lora_SF10 = 10;
const byte lora_SF11 = 11;
const byte lora_SF12 = 12;

//LORA names for coding rate settings
const byte lora_CR4_5 = 2;	//4:5
const byte lora_CR4_6 = 4;	//4:6
const byte lora_CR4_7 = 6;	//4:7
const byte lora_CR4_8 = 8;	//4:8

//LORA Header Settings
const byte lora_Explicit    = 0;	//Use to set explicit header
const byte lora_Implicit    = 1;	//Use to set implicit header

//Misc definitions
const byte lora_Deviation = 0x52;       //direct mode deviation
const byte lora_LowDoptON = 0x08;       //value to turn low data rate optimisation on
const byte lora_LowDoptOFF = 0x00;      //value to turn low data rate optimisation off
const byte lora_PrintASC = 0;           //value to cause buffer print to appear as ASCII
const byte lora_PrintNum = 1;           //value to cause buffer print to appear as decimal numbers
const byte lora_PrintHEX = 2;           //value to cause buffer print to appear as hexadecimal numbers


//SX1278 Register names
const byte lora_RegFifo = 0x00;
const byte lora_WRegFifo = 0x80;
const byte lora_RegOpMode = 0x01;
const byte lora_RegFdevLsb = 0x05;
const byte lora_RegFrMsb = 0x06;
const byte lora_RegFrMid = 0x07;
const byte lora_RegFrLsb = 0x08;
const byte lora_RegPaConfig = 0x09;
const byte lora_RegOcp = 0x0B;
const byte lora_RegLna = 0x0C;
const byte lora_RegFifoAddrPtr = 0x0D;
const byte lora_RegFifoTxBaseAddr = 0x0E;
const byte lora_RegFifoRxBaseAddr = 0x0F;
const byte lora_RegFifoRxCurrentAddr = 0x10;
const byte lora_RegIrqFlagsMask = 0x11;
const byte lora_RegIrqFlags = 0x12;
const byte lora_RegRxNbBytes = 0x13;
const byte lora_RegRxHeaderCntValueMsb = 0x14;
const byte lora_RegRxHeaderCntValueLsb = 0x15;
const byte lora_RegRxPacketCntValueMsb = 0x16;
const byte lora_RegRxPacketCntValueLsb = 0x17;
const byte lora_RegPktSnrValue = 0x19;
const byte lora_RegPktRssiValue = 0x1A;
const byte lora_RegRssiValue = 0x1B;
const byte lora_RegFsiMSB = 0x1D;
const byte lora_RegFsiLSB = 0x1E;
const byte lora_RegModemConfig1 = 0x1D;
const byte lora_RegModemConfig2 = 0x1E;
const byte lora_RegSymbTimeoutLsb = 0x1F;
const byte lora_RegPreambleLsb = 0x21;
const byte lora_RegPayloadLength = 0x22;
const byte lora_RegFifoRxByteAddr = 0x25;
const byte lora_RegModemConfig3 = 0x26;
const byte lora_RegPacketConfig2 = 0x31;
const byte lora_TXdefaultpower = 10;
const byte lora_RegPllHop = 0x44;

byte  lora_RXStart;			//start of packet data in RXbuff
byte  lora_RXEnd;			//end of packet data in RXbuff
byte  lora_RXPacketType;		//type number of received packet
byte  lora_RXDestination;		//destination address of received packet
byte  lora_RXSource;			//source address of received packet
byte  lora_RXPacketL;			//length of packet received, includes source, destination and packet type
byte  lora_TXStart;			//start of packet data in TXbuff
byte  lora_TXEnd;			//end of packet data in TXbuff
byte  lora_TXPacketType;		//type number of transmitted packet
byte  lora_TXDestination;		//destination address of transmitted packet
byte  lora_TXSource;                    //source address of transmitted packet
byte  lora_TXPacketL;			//length of packet transmitted, includes source, destination and packet type
byte  lora_BackGroundRSSI;		//measured background noise level
byte  lora_PacketRSSI;			//RSSI of received packet
byte  lora_PacketSNR;			//signal to noise ratio of received packet
byte  lora_Flags;                       //system flags
byte  lora_Power;		        //power setting for mode

//Flags byte constants
const byte CRCError = 7;                //bit number for CRC error
const byte Preamble = 6;                //bit number for preamble detected
const byte TXTimeout = 1;               //bit number for TX timeout in LoRa
const byte RXTimeout = 0;               //bit number for RX timeout in LoRa

//Variables RX
char  lora_RXBUFF[128];			//buffer where received packets are stored
char  lora_TXBUFF[128];			//buffer for packet to send
unsigned int lora_RXpacketCount;        //count of packets received
unsigned int lora_TXpacketCount;        //count of packets sent


//select the LoRa modem parameters here
//Slow - 146bps
const byte slow_Bandwidth = lora_BW62_5;
const byte slow_SpreadFactor = lora_SF12;
const byte slow_CodeRate = lora_CR4_5;
const byte slow_RateOptimisation = lora_LowDoptON;
const byte slow_Power = 10;
//zinoo
const byte zinoo_Bandwidth = lora_BW125;
const byte zinoo_SpreadFactor = lora_SF10;
const byte zinoo_CodeRate = lora_CR4_8;
const byte zinoo_RateOptimisation = lora_LowDoptOFF;
const byte zinoo_Power = 10;

//medium - 1562bps
const byte medium_Bandwidth = lora_BW62_5;
const byte medium_SpreadFactor = lora_SF8;
const byte medium_CodeRate = lora_CR4_5;
const byte medium_RateOptimisation = lora_LowDoptOFF;
const byte medium_Power = 10;

//Fast - 12500bps
const byte fast_Bandwidth = lora_BW500;
const byte fast_SpreadFactor = lora_SF8;
const byte fast_CodeRate = lora_CR4_5;
const byte fast_RateOptimisation = lora_LowDoptOFF;
const byte fast_Power = 10;

//Command - 488bps
const byte command_Bandwidth = lora_BW62_5;
const byte command_SpreadFactor = lora_SF10;
const byte command_CodeRate = lora_CR4_5;
const byte command_RateOptimisation = lora_LowDoptON;
const byte command_Power = 5;



/*
**************************************************************************************************
Library Functions
**************************************************************************************************
*/

void lora_ResetDev()
{
  //resets the LoRa device
  digitalWrite(lora_PReset, LOW);	//take reset line low
  delay(5);
  digitalWrite(lora_PReset, HIGH);	//take it high
}


void lora_Write(byte lora_LReg, byte lora_LData)
{
  //write a byte to a LoRa register
  digitalWrite(lora_PNSS, LOW);		//set NSS low
  SPI.transfer(lora_LReg | 0x80);	//mask address for write
  SPI.transfer(lora_LData);		//write the byte
  digitalWrite(lora_PNSS, HIGH);	//set NSS high
}

byte lora_Read(byte lora_LReg)
{
  //read a byte from a LoRa register
  byte lora_LRegData;
  digitalWrite(lora_PNSS, LOW);		//set NSS low
  SPI.transfer(lora_LReg & 0x7F);	//mask address for read
  lora_LRegData = SPI.transfer(0);	//read the byte
  digitalWrite(lora_PNSS, HIGH);	//set NSS high
  return lora_LRegData;
}


void lora_SetFreq(float lora_LFreq, float lora_LOffset)
{
  //set the LoRa frequency
  lora_LFreq =  lora_LFreq + lora_LOffset;
  byte lora_LFMsb, lora_LFMid, lora_LFLsb;
  long lora_LLongFreq;
  lora_LLongFreq = ((lora_LFreq * 1000000) / 61.03515625);
  lora_LFMsb =  lora_LLongFreq >> 16;
  lora_LFMid = (lora_LLongFreq & 0x00FF00) >> 8;
  lora_LFLsb =  (lora_LLongFreq & 0x0000FF);
  lora_Write(lora_RegFrMsb, lora_LFMsb);
  lora_Write(lora_RegFrMid, lora_LFMid);
  lora_Write(lora_RegFrLsb, lora_LFLsb);
}


byte lora_CheckDevice()
{
  //check there is a device out there, program a frequency setting registers and read back
  byte lora_Lvar1;
  lora_Write(lora_RegFrMid, 0xAA);
  lora_Lvar1 = lora_Read(lora_RegFrMid);	//read RegFrMid
  if (lora_Lvar1 != 0xAA )
  {
    return false;
  }
  else
  {
    return true;
  }
}


void lora_Setup()
{
  //initialise LoRa device registers and check its responding
  lora_ResetDev();				//clear all registers to default
  lora_Write(lora_RegOpMode, 0x08);		//RegOpMode, need to set to sleep mode before configure for LoRa mode
  lora_Write(lora_RegOcp, 0x2B);		//RegOcp
  lora_Write(lora_RegLna, 0x23);		//RegLna
  lora_Write(lora_RegSymbTimeoutLsb, 0xFF);	//RegSymbTimeoutLsb
  lora_Write(lora_RegPreambleLsb, 0xFF);	//RegPreambleLsb, default changed from 0x0c!!
  lora_Write(lora_RegFdevLsb, lora_Deviation);	//LSB of deviation, 5kHz
  if (!lora_CheckDevice())
  {
     sprintf(buf, "Lora NOT found\r\n");
   gnss_uart_putline(0, (U08*)buf, strlen(buf));
  }
}


byte lora_TXONDirect(byte lora_LTXPower)
{
  //turns on transmitter,in direct mode for FSK and audio  power level is from 2(dBm) to 17(dBm)
  lora_Write(lora_RegPaConfig, (lora_LTXPower + 0xEE));
  lora_Write(lora_RegOpMode, 0x0B);		//TX on direct mode, low frequency mode
}


void lora_TXOFF()
{
  //turns off transmitter
  lora_Write(lora_RegOpMode, 0x08);             //TX and RX to sleep, in direct mode
}


void lora_DirectSetup()
{
  //setup LoRa device for direct modulation mode
  lora_Write(lora_RegOpMode, 0x08);
  lora_Write(lora_RegPacketConfig2, 0x00);	//set continuous mode
}



void lora_SetModem(byte lora_LBW, byte lora_LSF, byte lora_LCR, byte lora_LHDR, byte lora_LLDROPT)
{
  lora_Write(lora_RegOpMode, 0x08);		 //RegOpMode, need to set to sleep mode before configure for LoRa mode
  lora_Write(lora_RegOpMode, 0x88);		 //goto LoRa mode
  lora_Write(lora_RegModemConfig1, (lora_LBW + lora_LCR + lora_LHDR));
  lora_Write(lora_RegModemConfig2, (lora_LSF * 16 + 7));
  lora_Write(lora_RegModemConfig3, lora_LLDROPT);
}



void init_LoRa()
{
  //setup as if from reset
  lora_Setup();
  lora_SetFreq(Frequency1, FreqOffset);
}


void init_LoRaFast()
{
  //setup for fast mode
  lora_SetModem(fast_Bandwidth, fast_SpreadFactor, fast_CodeRate, lora_Explicit, fast_RateOptimisation);	//setup the LoRa modem parameters
  lora_Power = fast_Power;
}


void init_LoRaMedium()
{
  //setup for medium mode
  lora_SetModem(medium_Bandwidth, medium_SpreadFactor, medium_CodeRate, lora_Explicit, medium_RateOptimisation);        //setup the LoRa modem parameters
  lora_Power = medium_Power;
}
void init_LoRaZinoo()
{
  //setup for medium mode
  lora_SetModem(zinoo_Bandwidth, zinoo_SpreadFactor, zinoo_CodeRate, lora_Explicit, zinoo_RateOptimisation);        //setup the LoRa modem parameters
  lora_Power = zinoo_Power;
}

void init_LoRaSlow()
{
  //setup for slow mode
  lora_SetModem(slow_Bandwidth, slow_SpreadFactor, slow_CodeRate, lora_Explicit, slow_RateOptimisation);	//setup the LoRa modem parameters
  lora_Power = slow_Power;
}



void init_LoRaCommand()
{
  //setup for command mode
  lora_SetModem(command_Bandwidth, command_SpreadFactor, command_CodeRate, lora_Explicit, command_RateOptimisation);	//setup the LoRa modem parameters
  lora_Power = command_Power;
}



/*
**************************************************************************************************
Library Functions RX
**************************************************************************************************
*/

/*byte lora_RXBuffPrint(byte lora_LPrint)
{
  //print contents of RX buffer as ASCII,decimal or HEX
  byte i, j;
  Serial.write(lora_RXPacketType);
  Serial.write(lora_RXDestination);
  Serial.write(lora_RXSource);

  for (byte i = lora_RXStart; i <= lora_RXEnd; i++)
  {
    if (lora_LPrint == 0)
    {
      Serial.write(lora_RXBUFF[i]);
    }

    if (lora_LPrint == 1)
    {
      Serial.print(lora_RXBUFF[i]);
      Serial.print(F(" "));
    }

    if (lora_LPrint == 2)
    {
      j = lora_RXBUFF[i];
      Serial.print(j, HEX);
      Serial.print(F(" "));
    }
  }
}

*/


void lora_RXOFF()
{
  //turn receiver off
  lora_Write(lora_RegOpMode, 0x89);                         //TX and RX to sleep, in direct mode
}


/*void lora_RXPKTInfo()
{
  //print the information for packet last received
  byte lora_Lvar1;
  char lora_LChar;

  Serial.print(F("SNR,"));
  if (lora_PacketSNR > 127)
  {
    lora_Lvar1 =  (255 - lora_PacketSNR) / 4;
    lora_LChar = '-';
  }
  else
  {
    lora_Lvar1 = lora_PacketSNR / 4;
    lora_LChar = '+';
  }

  Serial.print(lora_LChar);
  Serial.print(lora_Lvar1);
  Serial.print(F("dB"));

  lora_Lvar1 = 137 - lora_PacketRSSI;
  Serial.print(F(",RSSI,-"));
  Serial.print(lora_Lvar1);
  Serial.print(F("dB"));
  Serial.print(F(",LEN,"));
  Serial.print(lora_RXPacketL);
  Serial.print(F(",Type,"));
  Serial.write(lora_RXPacketType);
}

*/

void lora_ReadPacket()
{
  //read packet into the buffer
  byte lora_Lvar1;
  byte lora_LRegData;
  lora_RXpacketCount++;

  lora_RXPacketL = lora_Read(lora_RegRxNbBytes);
  lora_PacketRSSI = lora_Read(lora_RegPktRssiValue);
  lora_PacketSNR = lora_Read(lora_RegPktSnrValue);
  lora_Write(lora_RegFifoAddrPtr, 0);  	                 //set RX FIFO ptr

  digitalWrite(lora_PNSS, LOW);		                 //start the burst read
  SPI.transfer(lora_RegFifo);			         //address for burst read

  lora_RXPacketType = SPI.transfer(0);
  lora_RXDestination = SPI.transfer(0);
  lora_RXSource = SPI.transfer(0);

  lora_RXStart = 0;
  lora_RXEnd = lora_RXPacketL - 4;

  for (lora_Lvar1 = lora_RXStart; lora_Lvar1 <= lora_RXEnd; lora_Lvar1++)
  {
    lora_LRegData = SPI.transfer(0);
    lora_RXBUFF[lora_Lvar1] = lora_LRegData;
  }
  digitalWrite(lora_PNSS, HIGH);		           //finish, turn off LoRa device
}





void lora_RXONLoRa()
{
  //puts LoRa device into listen mode and receives packet exits with packet in array lora_RXBUFF[]
  byte lora_Lvar1, lora_LRegData, lora_LLoop;
  long lora_Lvar2;
  lora_RXPacketL = 0;
  lora_RXPacketType = 0;
  lora_RXDestination = 0;
  lora_RXSource = 0;
  lora_RXStart = 0;
  lora_RXEnd = 0;
  lora_Write(lora_RegOpMode, 0x09);
  lora_Write(lora_RegFifoRxBaseAddr, 0x00);
  lora_Write(lora_RegFifoAddrPtr, 0x00);
  lora_Write(lora_RegIrqFlagsMask, 0x9F);                //only allow rxdone and crc error
  lora_Write(lora_RegIrqFlags, 0xFF);
  lora_Write(lora_RegOpMode, 0x8D);
  lora_BackGroundRSSI = lora_Read(lora_RegRssiValue);    //get the background noise level
}


byte lora_readRXready()
{
  //return the contents of the IRQ flags register
  byte lora_LRegData;
  lora_LRegData = lora_Read(lora_RegIrqFlags);
  return lora_LRegData;
}


/*void lora_PrintLinkBudget()
{
  //print link budget for last received packet
  byte lora_Lvar1;
  char lora_LChar;
  if (lora_PacketSNR > 127)
  {
    lora_Lvar1 =  (255 - lora_PacketSNR) / 4;
    lora_LChar = '-';
  }
  else
  {
    lora_Lvar1 = lora_PacketSNR / 4;
    lora_LChar = '+';
  }

  Serial.print(lora_LChar);
  Serial.print(lora_Lvar1);
  Serial.print(F("dB"));

  lora_Lvar1 = 137 - lora_PacketRSSI;
  Serial.print(F(",-"));
  Serial.print(lora_Lvar1);
  Serial.print(F("dB"));
}
*/




/*
**************************************************************************************************
Library Functions TX
**************************************************************************************************
*/

/*byte lora_TXBuffPrint(byte lora_LPrint)
{
  //print contents of TX buffer as ASCII,decimal or HEX
  byte i, j;
  Serial.write(lora_TXPacketType);
  Serial.write(lora_TXDestination);
  Serial.write(lora_TXSource);

  for (byte i = lora_TXStart; i <= lora_TXEnd; i++)
  {
    if (lora_LPrint == 0)
    {
      Serial.write(lora_TXBUFF[i]);
    }

    if (lora_LPrint == 1)
    {
      Serial.print(lora_TXBUFF[i]);
      Serial.print(F(" "));
    }

    if (lora_LPrint == 2)
    {
      j = lora_TXBUFF[i];
      Serial.print(j, HEX);
      Serial.print(F(" "));
    }
  }
}

*/
void lora_TXONLoRa(byte lora_LTXPower)
{
  //turns on LoRa transmitter, Sends packet, power level is from 2 to 17
  lora_Write(lora_RegPaConfig, (lora_LTXPower + 0xEE));				//set TX power
  lora_Write(lora_RegOpMode, 0x8B);						//transmit on in direct low frequency mode
}


void lora_Send(byte lora_LTXStart, byte lora_LTXEnd, char lora_LTXPacketType, char lora_LTXDestination, char lora_LTXSource, long lora_LTXTimeout, byte lora_LTXPower)
{
  //send contents of buffer as LoRa packet
  int i;
  byte lora_LRegData;
  byte lora_LTXPacketL;
  lora_TXpacketCount++;
  lora_Write(lora_RegOpMode, 0x09);
  lora_Write(lora_RegIrqFlags, 0xFF);
  lora_Write(lora_RegIrqFlagsMask, 0xF7);
  lora_Write(lora_RegFifoTxBaseAddr, 0x00);
  lora_Write(lora_RegFifoAddrPtr, 0x00);  		//start burst read

  digitalWrite(lora_PNSS, LOW);				//set NSS low
  SPI.transfer(lora_WRegFifo);				//address for burst write
  SPI.transfer(lora_LTXPacketType);			//write the packet type
  SPI.transfer(lora_LTXDestination);			//destination node
  //SPI.transfer(lora_LTXSource);				//source node
  SPI.transfer(0xFF);        //source node
  lora_LTXPacketL = 3;					//we have added 3 header bytes

  for (i = lora_LTXStart;  i <= lora_LTXEnd; i++)
  {
    lora_LTXPacketL++;

    if (lora_LTXPacketL > 253)				//check for overlong packet here
    {                                                   
      lora_LTXPacketL--;				//remove increment to packet length
      break;
    }
    lora_LRegData = lora_TXBUFF[i];
    SPI.transfer(lora_LRegData);
    lora_TXPacketL =  lora_LTXPacketL;			//length of packet sent, includes source, destination and packet type.
  }

  digitalWrite(lora_PNSS, HIGH);			//finish the burst write
  lora_Write(lora_RegPayloadLength, lora_LTXPacketL);   
  lora_LTXTimeout = lora_LTXTimeout * 945;		//convert seconds to mS, delay in TX done loop is 1ms

  lora_TXONLoRa(lora_LTXPower);

  do
  {
    delay(1);
    lora_LTXTimeout--;
    lora_LRegData = lora_Read(lora_RegIrqFlags);
  }
  while (lora_LTXTimeout > 0 && lora_LRegData == 0) ;	//use a timeout counter, just in case the TX sent flag is missed

  lora_TXOFF();

  if (lora_LTXTimeout == 0)
  {
    bitSet(lora_Flags, TXTimeout);
  }
  else
  {
    bitClear(lora_Flags, TXTimeout);
  }
}


