int valor_limite= 500; //VALOR DONDE SE ACTIVA SENSOR
//int pin12 = 12; // ZUMBADOR
//int pin11 = 11; // LED DE ALARMA
//int pin9 = 10; // RELE DEL EXTRACTOR
//int pin8 = 9; // RELE DE VALVULA DE GAS

void setup() {
 
 Serial.begin(9600);
 pinMode (12,OUTPUT); //ZUMBADOR
 pinMode (11,OUTPUT); //LED DE ALARMA
 pinMode (10,OUTPUT); //RELE DE EXTRACTOR
 pinMode (9,OUTPUT); //RELE DE VALVULA DE GAS
 //Serial.println("PAUL RUDOLF MARCUS CAMARGO");
 Serial.println("CALIBRAR EL SENSOR");
}

void loop() {
 Serial.println(analogRead(A0));
 if (analogRead(A0) > valor_limite) {
  digitalWrite (12,1); //ENCIENDE ZUMBADOR
  delay (500); //AGUARDA
  digitalWrite(12, 0); //APAGA ZUMBADOR
  delay(500); //AGUARDA
  digitalWrite (11,1); //ENCIENDE LED DE ALARMA
  digitalWrite (10,1); //ENCIENDE EXTRACTOR
  digitalWrite (9,1); //APAGA VALVULA DE GAS
  //Serial.println("ALARMA DISPARADA!!!"); //MENSAJE EN PUERTO SERIAL
  // delay(2000); //TIEMPO DE DISPARO DE LA ALARMA
   
 }
 else{
  digitalWrite (12,0); //APAGA ZUMBADOR
  digitalWrite (11,0); //APAGA LED DE ALARMA
  digitalWrite (10,0); //APAGA EXTRACTOR
 // digitalWrite (11,0); //ENCIENDE VALVULA DE GAS
 //LA VALVULA DE GAS SE ENCIENDE RESETEANDO EL SISTEMA, 
 //DESPUES DE SOLUCIONAR EL PROBLEMA.
 }
 delay (1000);
}
