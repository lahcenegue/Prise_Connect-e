
#define BLYNK_TEMPLATE_ID           "TMPLpTMTeHqd"
#define BLYNK_DEVICE_NAME           "Courant"
#define BLYNK_AUTH_TOKEN            "DQrsk21VXPVuM99w0NurSi9c-4ASXbO3"

#define BLYNK_PRINT Serial

#include <EmonLib.h> 
#include <Wire.h> 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Idoom 4G_BDF13";
char pass[] = "URD2021@at";


#define ADC_INPUT 34


EnergyMonitor emon1;
BlynkTimer timer;


void setup() {
  Serial.begin(115200); 
  Blynk.begin(auth, ssid, pass);  
  emon1.current(ADC_INPUT, 6.66); 
  timer.setInterval(250L, AnalogPinRead);
}


void AnalogPinRead() {
  double Irms = emon1.calcIrms(5588); 
  Serial.print("sensor = ");  
  Serial.println(Irms);  
  Blynk.virtualWrite(V1, Irms);  
}


void loop() {
  Blynk.run();
  timer.run();
}
