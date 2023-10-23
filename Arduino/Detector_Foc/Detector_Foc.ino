
int led = 12;
int buzzer = 6;
int pinFoc = 5;
int Foc = HIGH; // HIGH ADICA 1 INSEAMNA FARA FOC


void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(pinFoc,INPUT); // INPUT PENTRU CA CITIM DE LA EL DATELE
  Serial.begin(9600); // COMUNICARE SERIALA

}

void loop() {
  Foc = digitalRead(pinFoc); // CITESTE STAREA SENZORULUI 0 SAU 1
  if (Foc == LOW){  // DACA DETECTEZ FOC/ LOW ADICA 0 
      Serial.println("FOC FOC FOC!");
      tone(buzzer, 2500); // BUZZER-UL SUNA LA FRECVENTA DE 1000hz
      digitalWrite(led,HIGH); //APRINDE LED
}
  else{
    Serial.println("Nu detectez foc");
    digitalWrite(led,LOW);  //STINGE LED
    noTone(buzzer); // OPRESTE BUZZER
  }
}
