
// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID           "TMPLq7LC233B"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "Xkp5FRk5LgDtdbAjJ89R1msFHnJWUide"


// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PNH3032";
char pass[] = "2711196928051975230601";

const int trigPin1 = D3;
const int echoPin1 = D2;
#define redled D4
int duration1,distance1;
int count=0;

void ICACHE_RAM_ATTR ISRoutine();

WidgetLCD lcd(V1);
WidgetLCD lcd1(V2);
WidgetLCD lcd2(V4);
WidgetLCD lcd3(V5);
WidgetLCD lcd4(V6);

void setup()
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(A0, INPUT);
  digitalWrite(A0, OUTPUT);
  pinMode(redled, OUTPUT);
  digitalWrite(redled, LOW);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  int float1=analogRead(A0);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1 * 0.034 / 2;
  Serial.print("Float Sensor");
  Serial.println(float1);
  Serial.print("Ultra Sonic");
  Serial.println(distance1);
  //lcd.print(0,0,"Hello");
   Blynk.virtualWrite(V4,LOW);
   Blynk.virtualWrite(V5,LOW);
   Blynk.virtualWrite(V1,distance1);
   Blynk.virtualWrite(V2,float1);
   if(distance1 < 10)
   {
    Blynk.notify("Blockage Alert!");
    Blynk.virtualWrite(V4,HIGH);
    Blynk.virtualWrite(V6,"play");
   }
   if(float1 < 7)
   {
    Blynk.notify("Overflow Alert !");
    Blynk.virtualWrite(V5,HIGH);
   }
   delay(100);
   Blynk.run();
}
