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
    while(client.available()) {
      char c = client.read();
      Serial.write(c);
      cont += c;
      if(cont == "GET /") {
        {client.println("<!DOCTYPE html>");}
        {client.println("<html>");}
        {client.println("<body>");}
        {client.println("<p>Hello!</p>");}
        {client.println("<script type=\"text/javascript\">");}
        {client.println("document.addEventListener(\"keydown\", function() {");}
        {client.println("xmlHTTP = new XMLHttpRequest();");}
        {client.println("xmlHTTP.open(\"GET\", String(event.which), true);");}
        {client.println("xmlHTTP.send();");}
        {client.println("});");}
        {client.println("</script>");}
        {client.println("</body>");}
        {client.println("</html>");}
        client.stop();
      }
    }
    client.stop();
  }
}
