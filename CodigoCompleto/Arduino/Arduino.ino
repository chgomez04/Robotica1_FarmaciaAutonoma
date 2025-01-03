/*Código en arduino que controla un brazo robótico de 5 GDL
  PROYECTO FINAL DE ROBÓTICA 1
  9no Semestre
  Diciembre-2021
*/

#include <Servo.h> //libreria para utilizar los servomotores
#include <Ticker.h> //Libreria que permite llamar(ejecutar) funciones de forma repetida cada cierto periodo de tiempo
#include "libManuel1.h" //libreria para que almacena las funciones

String cadena;
void setup() {
Serial.begin(9600);
delay(30);
pinMode(13 , OUTPUT);

// lcd.begin(16, 2);
// lcd.print("Iniciando sensores...");

//Se inicializa los pines que van a controlar los servomotores
 myservo0.attach(3);  //Servo 0 - Base
 myservo1.attach(5); //Servo 1 - Hombro(Derecho)
 myservo2.attach(6); //Servo 2 - Codo
 myservo3.attach(9); //Servo 3 - Muñeca

 
 
//Se inicializan las funciones que se ejecutarán en ticker
 ticservo0.start();
 ticservo1.start();
 ticservo2.start();
 ticservo3.start();
 
 ticmovposicion.start();
 
 myservo0.write(pos0);
 myservo1.write(pos1);
 myservo2.write(pos2);
 myservo3.write(pos3);

 delay(700);

}
void loop() {
  //Aquí se estarán actualizando con Ticker las funciones para los servomotores
  
 
  ticservo0.update();
  ticservo1.update();
  ticservo2.update();
  ticservo3.update();
 
  //Lectura para el Serial
  if(Serial.available()){
    cadena="";
    cadena= Serial.readString();
    fnActuadores(cadena); //Si hay algo en el serial se ejecuta la funcion fnActuadores
    
    }
  if (var==true){
    ticmovposicion.update(); //Sirve para ejecutar la secuencia del brazo robótico
  }
}
