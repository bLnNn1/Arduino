
#include "DHT.h" //DHT Sensor library by AdaFruit

#define DHTPIN 8    
#define DHTTYPE DHT11   

DHT dht(9, DHT11);
int Gaz;
int FotoR = 2;
int buzzer = 4 ;
const int TouchPin=3;

void setup() {
  pinMode(TouchPin, INPUT);
  pinMode (buzzer, OUTPUT) ;
  pinMode(FotoR, INPUT);
  Serial.begin(9600);
  Serial.println(F("DHT11 a început măsurarea temperaturii și a umidității!"));

  dht.begin();
}

void loop() {
  Gaz = analogRead(A0);       // citeste input din pin analog 0 A0
  int sensorVal = digitalRead(TouchPin);
  int FotoRStare = digitalRead(FotoR);
    
    delay(2000);
    // Citire umiditate
    float h = dht.readHumidity();
    // Citeste temp in grade celsius     
    float t = dht.readTemperature();
    
    // Daca au esuat citirile, afiseaza mesajul
    if (isnan(h) || isnan(t)) {
      Serial.println(F("Am eșuat citirea de pe senzor!"));
      return;
    }
    // Daca e lumina (0) citeste  valorile
    if(FotoRStare==0){
      Serial.print(F("Umiditate: "));
      Serial.print(h);
      Serial.print(F("%  Temperatură: "));
      Serial.print(t);
      Serial.print(F("°C "));
      Serial.print("Calitate Aer = ");
      Serial.print(Gaz,DEC);
      Serial.print("PPM !");
      Serial.println();
      noTone(4);
    }
    // Daca temperatura < 25 de grade si senzorul touch nu e apasat
    if(t < 25 && FotoRStare == 0 && Gaz < 145){
      tone(4,1000,500);
    }
    // Daca temperatura < 25 de grade si senzorul touch e apasat
    else if (t < 25 && sensorVal == 1){
      noTone(4);
    }
    else if(Gaz > 500 && t < 25 && FotoRStare == 0){
      tone(4,2000,1000);
    }
    else if(Gaz > 500){
      tone(4,2000,1000);
    }
    else{
      noTone(4);
    }
    }
