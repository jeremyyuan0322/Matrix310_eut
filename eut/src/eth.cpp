#include "eth.h"
extern char summary[7][32];
void testEth() {
  // the MAC (Media access control) address for the device (array of 6 bytes). this is the Ethernet hardware address of your Matrix310.
  byte mac[] = { 0x98, 0xf4, 0xab, 0x17, 0x24, 0xc4 };//98:f4:ab:17:24:c4
  // the IP address of the device (array of 4 bytes)
  IPAddress ip(0, 0, 0, 0);
  IPAddress myserver(192, 168, 1, 1);
  
  Ethernet.init(LAN_CS);
  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  //Matrix310 tries connecting the internet with DHCP
  if (Ethernet.begin(mac) == 0) {
    //Fail to use DHCP
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      while (true) {
        delay(1);  // do nothing, no point running without Ethernet hardware
      }
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
    }
    // try to configure using IP address instead of DHCP:
    Ethernet.begin(mac, ip);
  } else {  //Matrix310 already connect to the internet
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);

  //Ping
  bool ret = Ping.ping(myserver, 3);
  float avg_time_ms = Ping.averageTime();
  if(ret) {
    Serial.println("Ping Success");
    Serial.printf("Ping avg time: %f\n", avg_time_ms);

    Serial.println("Wifi test is OK");
    summary[ETH][1] = '0';
  } else {
    Serial.println("Ping Error");
    Serial.println("Wifi test is failed");
    summary[ETH][1] = '1';
  }
}