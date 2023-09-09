#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
Servo servo1;
#define sensor A0

const int motionPin = 16;  // Motion sensor output pin
const int motorPin = 4;   // Motor control pin

// Variables
int motionState = 0;      // Variable to store motion sensor state

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "DHT.h"
/************************* WiFi Access Point *******************************/
#define WLAN_SSID       "Drill Press Cafe"
#define WLAN_PASS       "passiton"
/************************* Adafruit.io Setup *******************************/
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "Aditya25"
#define AIO_KEY         "aio_FJQU29NIJ8mhS5ofAp6tiGNv4Wam"
/************************* DHT11 Setup *************************************/
/************ Global State (you don't need to change this!) ****************/
// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds *************************************/
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>

Adafruit_MQTT_Publish temperature = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/temp");
Adafruit_MQTT_Publish humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/hum");
/*************************** Sketch Code **********************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();
#define DHTPIN 5 //D1
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
float humidity;
float temperature;
void rotateClockwise() {
    servo1.write(0);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);     // Stop motor
}

// Function to rotate the motor anticlockwise for 180 degrees
void rotateAntiClockwise() {
   servo1.write(180);
  delay(1000);
  servo1.write(90);
  delay(1000);
  servo1.write(0);
  delay(1000);     // Stop motor
}

void setup()
{
  Serial.begin(115200);
  Serial.println(F("DHTxx test!"));

  //begin dht communication
  dht.begin();
 // Serial.println(F("Adafruit MQTT demo"));
  // Connect to WiFi access point.
  Serial.println(); 
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
  pinMode(motionPin, INPUT);
  pinMode(motorPin, OUTPUT);
  servo1.attach(motorPin);  
}

uint32_t x=0;

void loop() 
{
   if (motionState == LOW ) 
  {
    // Object is not moving
    rotateClockwise();    
    // Move motor clockwise for 180 degrees
    int value = analogRead(sensor);
  int sh = map(value, 1024, 0, 0, 100);
  
  
  //humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // check if dht giving values or not, if not print error message on screen


  //print the values on screen
Serial.print(F("Soil Humidity: "));
  Serial.print(sh);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));

  Serial.println("");
  delay(1000);
  MQTT_connect();

  temperature.publish(t);
  humidity.publish(sh);
  
    
  delay(5000);
     
    // Object is moving
    rotateAntiClockwise(); 
}}
// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect()
 {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
