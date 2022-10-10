#include <SoftwareSerial.h>
#include <ArduinoJson.h>

//D6 = Rx & D5 = Tx
SoftwareSerial nodemcu(D6, D5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nodemcu.begin(9600);  
  while (!Serial) continue;
}

void loop() {
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.parseObject(nodemcu);

  if (data == JsonObject::invalid()) {
    //Serial.println("Invalid Json Object");
    jsonBuffer.clear();
    return;
  }
  Serial.println("JSON Object Recieved");
  Serial.print("Recieved Magnitude:  ");
  float magnitude = data["magnitude"];
  Serial.println(magnitude);
  Serial.print("Recieved atitude:  ");
  float latitude = data["latitude"];
  Serial.println(latitude);
    Serial.print("Recieved longitude:  ");
  float longitude = data["longitude"];
  Serial.println(longitude);
  Serial.println("-----------------------------------------");
}
