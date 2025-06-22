
#define BLYNK_TEMPLATE_ID           "TMPL6UM9dBtwl"
#define BLYNK_TEMPLATE_NAME         "Quickstart Template"
#define BLYNK_AUTH_TOKEN            "4VmiZZcF74Rr4RUaKTctXO0neSybn3xn"


#define BLYNK_PRINT Serial


#include "PMS.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 PMS pms(Serial);
 PMS::DATA data;



char auth[] = "4VmiZZcF74Rr4RUaKTctXO0neSybn3xn";              
char ssid[] = "Seec";
char pass[] = "See10ccc"; 

int PM25;


void setup()
{
  Serial.begin(9600);   
  Blynk.begin(auth, ssid, pass);
}

void loop()
  {
   Blynk.run();

    
     if (pms.read(data)){

    int pm1 = data.PM_AE_UG_1_0 - 25.5;
    int pm25 = data.PM_AE_UG_2_5 - 31.5;
    int pm10 = data.PM_AE_UG_10_0 - 30.5;
    
    Blynk.virtualWrite(V1,pm1);
    Blynk.virtualWrite(V2,pm25);
    Blynk.virtualWrite(V3,pm10);
  }

 }

  
