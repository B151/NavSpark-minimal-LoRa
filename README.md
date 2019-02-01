# NavSpark-minimal-LoRa
minimal LoRa tracker with NavSpark mini and LoRa RFM95
upload newest NavSpark mini firmware
http://navspark.mybigcommerce.com/content/STI_02.01.05-01.07.27_NavSpark-mini_CRC_5053_115200_20150818.zip 

 Then edit GNSS.cpp 
Local\Arduino15\packages\navspark\hardware\navspark\1.0.4\cores\arduino
```
  init_mode.nmea_interval.gga_t = 0;
  init_mode.nmea_interval.gll_t = 0;
  init_mode.nmea_interval.gsa_t = 0;
  init_mode.nmea_interval.gsv_t = 0;
  init_mode.nmea_interval.rmc_t = 0;
  init_mode.nmea_interval.vtg_t = 0;
  init_mode.nmea_interval.zda_t = 0;
```
