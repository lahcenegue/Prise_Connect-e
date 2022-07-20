// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLWkdIfCY3"
#define BLYNK_DEVICE_NAME "nodemcu"
#define BLYNK_AUTH_TOKEN "RtVHnQjxsi1B5fdZDFti3JihcAYcKyGP"

// ESP8266 Analog Pin ADC0 = A0 
#define analogPin A0                

#define BLYNK_PRINT Serial


// Include Emon Library
#include <EmonLib.h> 


#include <Wire.h> 

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Idoom 4G_BDF13";
char pass[] = "URD2021@at";


#define ADC_INPUT 0                 /* Variable to store Output of ADC */

// Create an instance
EnergyMonitor emon1;


BlynkTimer timer;


void setup() {
  Serial.begin(115200);                      /* Initialize serial communication at 115200 */
  Blynk.begin(auth, ssid, pass);

  //calibration 
  emon1.current(ADC_INPUT, 39);           
  timer.setInterval(250L, AnalogPinRead);
}


void AnalogPinRead() {

  //calculate irms (5588 fixed valeur)
  double Irms = emon1.calcIrms(5588); 
  
  Serial.print("sensor = ");  
  Serial.println(Irms);  
  Blynk.virtualWrite(V2, Irms);  
}


void loop() {
  Blynk.run();
  timer.run();
}
