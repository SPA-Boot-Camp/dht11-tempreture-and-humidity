#include <dht11.h>


#define dht_apin A0 // Analog Pin sensor is connected to
 
dht11 DHT11;

int fanPin = 1;
int led1 = 2;
int led2 = 3;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor

  pinMode(fanPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT11.read(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT11.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT11.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.

    if(DHT11.temperature > 35)
    {
        digitalWrite(fanPin, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
    }
    else
    {
      digitalWrite(fanPin, LOW);
      digitalWrite(led1, HIGH);
      Serial.begin("LED 1 ON");
      digitalWrite(led2, HIGH);
      Serial.begin("LED 2 HIGH");
      
    }
 
}// end loop(
