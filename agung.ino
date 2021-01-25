#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
const int triggerPin = D2;
const int echo = D1;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "6-5vibeGtXWhXMrwrn2eP7rdL_8cd8hu";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "iphone";//your wifi name
char pass[] = "reset12345"; //your wifi password


void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(triggerPin, OUTPUT);
  pinMode(echo, INPUT);
  Blynk.begin(auth, ssid, pass);
  

  
}

void loop()
{
long duration;
int distance;
Blynk.run();
  timer.run();
  digitalWrite(triggerPin, LOW);  
  delayMicroseconds(500); 
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(500); 
  
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  int tinggi = 200 - distance;
  Blynk.virtualWrite(V1,tinggi);
  
Serial.println(distance);
Serial.println(tinggi);

  delay(1000);

}
