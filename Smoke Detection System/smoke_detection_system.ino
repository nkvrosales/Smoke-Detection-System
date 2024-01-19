
//Change Blynk Authenticaation Details
#define BLYNK_TEMPLATE_ID "TMPLZ0xPIQLB"
#define BLYNK_TEMPLATE_NAME "Smoke Detection"
#define BLYNK_AUTH_TOKEN "lAA3jbpmWH5wWCDlnJECcXRZWBZpBGTx"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "admin";  // Enter your wifi name
char pass[] = "admin123";  // Enter your wifi password
int smokeA0 = A0;
int data = 0;
int sensorThres = 600;
int buzzer = 11;



BlynkTimer timer;

void sendSensor(){
 
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);


  if(data > 350)     // Change the Threshold value
  {
    
    Blynk.logEvent("smoke_alert","Smoke Detected!");
    tone.buzzer(1000);
  }
  else
  {
    noTone(buzzer);
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  //dht.begin();
  timer.setInterval(2500L, sendSensor);
}

void loop(){
  Blynk.run();
  timer.run();
}
