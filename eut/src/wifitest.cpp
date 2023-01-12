#include "wifitest.h"
extern char summary[7][32];

void testWifi() {
  const char *ssid = "AOQTP";
  const char *password = "tw27477816";
  IPAddress myAp(192, 168, 0, 10);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);  // Set Wifi mode
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  int rssi = WiFi.RSSI();
  Serial.printf("RSSI: %i\n", rssi);

  bool ret = Ping.ping(myAp, 3);
  float avg_time_ms = Ping.averageTime();
  if(ret) {
    Serial.println("Ping Success");
    Serial.printf("Ping avg time: %f\n", avg_time_ms);

    Serial.println("Wifi test is OK");
    summary[WIFI][1] = '0';
  } else {
    Serial.println("Ping Error");

    Serial.println("Wifi test is failed");
    summary[WIFI][1] = '1';
  }
  
}
