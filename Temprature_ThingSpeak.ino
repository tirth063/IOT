#include <OneWire.h>
#include <DallasTemperature.h>
#include <ThingSpeak.h>
#include <ESP8266WiFi.h>
#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int status = WL_IDLE_STATUS; 
WiFiClient  client;

unsigned long myChannelNumber = 2630247;
const char * myWriteAPIKey = "LL0QMC1Q8W1PZAWH";

// WiFi credentials
const char* ssid = "mcacomplab";
const char* password = "wifii386";

void setup(void)
{
  Serial.begin(115200);
  //pinMode(ONE_WIRE_BUS, INPUT);
  // Connect to Wi-Fi
 ThingSpeak.begin(client);
 WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println(".");
  }
  Serial.println("Connected to WiFi");

  // Initialize Dallas sensor
  sensors.begin();
}
void loop(void)
{ 
  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));  
  double val = sensors.getTempCByIndex(0);
  int x = ThingSpeak.writeField(myChannelNumber, 1, int(val), myWriteAPIKey);
  Serial.println("Problem updating channel. HTTP error code " + String(x));
  
  delay(15000);
    
}
