//Más proyectos en www.rogerbit.com
//Suscribete en http://www.youtube.com/user/carlosvolt?sub_confirmation=1
//Grupo en Facebook https://www.facebook.com/groups/RogerBit/

#include <SoftwareSerial.h>
SoftwareSerial  Sim900Serial(2, 3);
//Declaración de variables
int gas = A0;
int bGas=0;
 int i =0;

long numero=1234567890;//Calocar el número de telefono al que se quiere llamar
void setup()
{
pinMode(13, OUTPUT);
Sim900Serial.begin(19200);               // velocidad de transmisión SIM900   
  Serial.begin(19200);             // velocidad de transmisión del arduino
  delay(500);
}

void loop()
{
 
  bGas= analogRead(gas);//Lectura del sensor de gas
  Serial.println(bGas);//Se imprime ese valor en terminal serial
   //Si le variable bGas es mayor a 250 genera una llamada telefónica y activa u buzzer de advertencia por 20 segundos
   if(bGas>250){
   
Sim900Serial.print("ATD");Sim900Serial.print(numero);Sim900Serial.println(";");//Comando ATD para llamar a un número telefonico es importante el ";"
    
 Serial.println("Llamando...");//Se imprime la leyenda Llamando...
  while(i<=20){
  delay(1000);//Retardo de un segundo
  //Hace zonar un buzzer durante 20 segundos
 digitalWrite(13, HIGH);
   delay(150);
   digitalWrite(13, LOW); 
   i++;//Incrementamos i de a uno hasta que no se cumpla la condición
//Se lee y si impreime el valor de sensor en ese momento
  bGas= analogRead(gas);
  Serial.println(bGas);
 }
 //Corta la llamado después de un tiempo
 if(i>1){
  Sim900Serial.println("ATH");
Serial.println("Corte de llamada");
i=0;
  }  
   }
   delay(1000);
 
   } 
