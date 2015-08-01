#include <SPI.h>
#include <WiFi.h>

char ssid[] = "secretNetworkName";
char pass[] = "secretPassword";
int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  Serial.begin(9600);

  status = WiFi.begin(ssid, pass);
  if(status != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    while(true);
  }
  Serial.println("Connected to WiFi.");

  server.begin();
  IPAddress myIP = WiFi.localIP();
  Serial.print("IP: "); Serial.println(myIP);
}

void loop() {
  WiFiClient client = server.available();
  if(client) {
    String cont = "";
    boolean done = false;
    while(client.available() && !done) {
      char c = client.read();
      Serial.write(c);
      cont += c;
      if(cont == "KEY DOWN w") {
        Serial.write("w");
        done = true;
      }
      if(cont == "KEY DOWN a") {
        Serial.write("a");
        done = true;
      }
      if(cont == "KEY DOWN s") {
        Serial.write("s");
        done = true;
      }
      if(cont == "KEY DOWN d") {
        Serial.write("d");
        done = true;
      }

      if(cont == "KEY UP w") {
        Serial.write("!w");
        done = true;
      }
      if(cont == "KEY UP a") {
        Serial.write("!a");
        done = true;
      }
      if(cont == "KEY UP s") {
        Serial.write("!s");
        done = true;
      }
      if(cont == "KEY UP d") {
        Serial.write("!d");
        done = true;
      }
    }
  }
}
