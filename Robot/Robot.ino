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
}

void loop() {

}
