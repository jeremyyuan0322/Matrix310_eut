#include <sys/_types.h>
#include "eth.h"
extern char summary[7][32];

void testEth() {
  // the MAC (Media access control) address for the device (array of 6 bytes). this is the Ethernet hardware address of your Matrix310.
  byte mac[] = { 0x98, 0xf4, 0xab, 0x17, 0x24, 0xc4 };//98:f4:ab:17:24:c4
  Ethernet.init(LAN_CS);
  // start the Ethernet connection:
  Serial.println("Initialize Ethernet with DHCP:");
  //Matrix310 tries connecting the internet with DHCP
  unsigned long connectTimeout = 1000;
  if (Ethernet.begin(mac, connectTimeout) == 0) {
    //Fail to use DHCP
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
      testEthFail();
      return;
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
      testEthFail();
      return;
    }
    else {
      testEthFail();
      return;
    }
  } 
  else {  //Matrix310 already connect to the internet
    Serial.print("  DHCP assigned IP ");
    Serial.println(Ethernet.localIP());
  }
  // give the Ethernet shield a second to initialize:
  delay(1000);

  ethServerConnect();
}

void ethServerConnect() {
  IPAddress myServer(192, 168, 0, 10);
  Serial.print("connecting to ");
  Serial.println(myServer);
  Serial.println();

  // Use EthernetClient class to create TCP connections
  EthernetClient client;
  const int httpPort = 80;
  // client.setConnectionTimeout(5000);
  unsigned long connectTimeout = millis();
  while (1) {
    if (client.connect(myServer, httpPort)) {
      break;
    }
    if (millis() - connectTimeout > 3000) {
      Serial.println("Connect Timeout !");
      testEthFail();
      return;
    }
  }
  // if (!client.connect(myServer, httpPort)) {
  //   Serial.println("connection failed");
  //   testEthFail();
  //   return;
  // }

  // We now create a URI for the request
  String url = "OK";

  Serial.print("Requesting msg: ");
  Serial.println(url);

  // This will send the request to the server
  client.print("url");

  // Read all the lines of the reply from server and print them to Serial
  unsigned long timeout = millis();
  String clientReturn;
  while (1) {
    if (client.available()) {
      clientReturn = client.readString();
      Serial.printf("Msg: %s\n", clientReturn);
      break;
    }
    if (millis() - timeout > 3000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      testEthFail();
      return;
    }
  }
  Serial.println();
  Serial.println("closing connection");

  if (url.compareTo(clientReturn) == 0) {
    Serial.println("Ethernet test is OK");
    summary[ETH][1] = '0';
  } else {
    testEthFail();
  }
}

void testEthFail(){
  Serial.println("Ethernet test is failed");
  summary[ETH][1] = '1';
}