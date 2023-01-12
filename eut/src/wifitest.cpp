#include "wifitest.h"
extern char summary[7][32];

void testWifi() {
  const char *ssid = "AOQTP";
  const char *password = "tw27477816";
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);  // Set Wifi mode
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  bool ret = Ping.ping(ip);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  int rssi = WiFi.RSSI();
  Serial.printf("RSSI: %i\n", rssi);
  if (rssi < -40) {
    Serial.println("Wifi test is OK");
    summary[WIFI][1] = '0';
  }
  else {
    Serial.println("Wifi test is failed");
    summary[WIFI][1] = '1';
  }
  
}
