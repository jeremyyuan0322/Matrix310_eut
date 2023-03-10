#include "wifitest.h"

extern char summary[7][32];
void testWifi() {
  const char *ssid = "AOQTP";
  const char *password = "tw27477816";
  // bool wifiOK = false;
  setWifiLed(HIGH);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);  // Set Wifi mode


  WiFi.begin(ssid, password);

  for (int i = 0; i < 3; i++) {
    unsigned long startTime = millis();
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
      if (WiFi.status() == WL_CONNECTED) {
        break;
        break;
      }
      if (millis() - startTime > 3000) {
        break;
      }
    }
  }
  if(WiFi.status() != WL_CONNECTED)
  {
    testWifiFail();
    return;
  }

  setWifiLed(LOW);
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("WiFi RSSI: ");
  Serial.println(WiFi.RSSI());
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);

  wifiServerConnect();
}

void wifiServerConnect() {
  IPAddress myServer(192, 168, 0, 10);
  Serial.print("connecting to ");
  Serial.println(myServer);
  Serial.println();

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  unsigned int clientTimeout = 5000;
  if (!client.connect(myServer, httpPort, clientTimeout)) {
    Serial.println("connection failed");
    testWifiFail();
    return;
  }

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
      testWifiFail();
      return;
    }
  }
  Serial.println();
  Serial.println("closing connection");

  if (url.compareTo(clientReturn) == 0) {
    Serial.println("Wifi test is OK");
    summary[WIFI][1] = '0';
  } else {
    testWifiFail();
  }
}
void testWifiFail() {
  Serial.println("Wifi test is failed");
  summary[WIFI][1] = '1';
}
