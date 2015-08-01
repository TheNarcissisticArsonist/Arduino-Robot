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
    if(client.connected()) {
      {client.println("<!DOCTYPE html>");}
      {client.println("<html>");}
      {client.println("<body>");}
      {client.println("<p>Hello!</p>");}
      {client.println("<script type=\"text/javascript\">");}
      {client.println("alert(\"Hello!\");");}
      {client.println("</script>");}
      {client.println("</body>");}
      {client.println("</html>");}
    }
    client.stop();
  }
}
