 /* SENSOR DE GAS CON RELE Y PILOTOS */
int pinSensor = A0; //Pin Sensor
int Rele1 = 3; //Pin Relé
int Rele2 = 8; //Pin Relé
int LED1 = 4; //Pin led alarma
int LED2 = 12; //Pin led encendido
int buzzer = 2; //Pin Buzzer
int var = 0;
int ValDesarm = 22; //Variáble para detectar la cantidad de gas 
int valor = 0;
  
void setup()
{
 Serial.begin(9600); //Inicia puerto Serial en 9600 baud
 pinMode(Rele1, OUTPUT);
 pinMode(Rele2, OUTPUT);
  pinMode(LED1, OUTPUT);
 pinMode(buzzer, OUTPUT);
  pinMode(LED2, OUTPUT);
 Serial.println("PAUL RUDOLF MARCUS CAMARGO");
}
  
void loop()
{
 valor = analogRead(pinSensor); //Hace la lectura de la entrada del sensor
 valor = map(valor, 0, 1023, 0, 100); //Hace la conversion de la variable a porcentaje
 Serial.println(valor); //Escribe el valor en el puerto serial
 if (valor>=ValDesarm){ //Condicion, se valor continuar mayor que ValDesarm :
 digitalWrite(Rele1, HIGH); //Enciende relé para solenóide
 digitalWrite(Rele2, HIGH); //Enciende relé para estractor de aire
 digitalWrite(LED1, HIGH); //Enciende led1 para avisar alarma
 digitalWrite(buzzer, HIGH); //Dispara alarme de fuga de gas
 
 Serial.println("Alarme disparada!!!"); //Presenta mensage en el  puerto serial
 delay(2000); //Tiempo de disparo de la  alarma
 digitalWrite(buzzer, LOW); //desconeccion de la  alarma
 delay(500); //Aguarda
 }
 else{
 //Caso contrário permane con el rele desconectado
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, HIGH);
 delay (1000);
 digitalWrite(LED2, LOW); //Enciende led2 para mostrar funcionamiento
 digitalWrite(Rele2,LOW); //Enciende Rele2 para activar estractor de aire

 }
 delay(1000);
 }


