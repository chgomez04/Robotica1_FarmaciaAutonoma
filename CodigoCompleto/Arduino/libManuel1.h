// Libreria que contiene todas las funciones a ejecutarse
// para elcontrol del Brazo  robótico

//Se crean los objetos del tipo Servo, (los servomotores)
Servo myservo0;
Servo myservo1;
Servo myservo2;
Servo myservo3;



//Inicio de posición de los motores (Estado inicial del Robot HOME)
int pos0 = 85;
int setpoint0 =85;

int pos1 = 0;
int setpoint1 = 0;

int pos2 = 30;
int setpoint2 = 30;

int pos3 = 52;
int setpoint3 =52;


boolean var=false;
int veces=0;


String myArray[10]; //Se crea un arreglo con tamaño para 10 posiciones
int n=0;


//===================================== FUNCIONES DE CONTROL PARA LOS SERVOMOTORES =============================================

//Control Servomotor 0-(Articulación BASE)
void fservo0(){
  //delay(5);
  if (pos0 != setpoint0){ //Se pregunta por la posición en que está el servomotor 0, se compara con el setpoint(variable enviada desde python)
    if (pos0<setpoint0){  //Si pos0 es menor a setpoint0
      pos0+=1;     //Se incrementa en 1 hasta que pos0 y setpoint0 sean iguales
      //pos0+=5; //Tal vez así aumenta la velocidad
    }
    if (pos0>setpoint0){ //Si pos0 es mayor a setpoint1
      pos0-=1;    //Se decrementa en 1 hasta que pos0 y setpoint0 sean iguales
      //pos0-=5;
    }
    myservo0.write(pos0);   //Se escribe el valor o ángulo de pos0 en el servomotor
  }
  //Serial.println("mot0: " + String(pos0));
}
Ticker ticservo0( fservo0,15);  //Ticker estará ejecutando la función fservo1 cada 15 milisegundos


//Control Servomotor 1 y servomotor-(Articulación HOMBRO)
void fservo1(){
  //delay(5);
  if (pos1 != setpoint1){
    if (pos1<setpoint1){
      pos1+=1;
    }
    if (pos1>setpoint1){
      pos1-=1;
    }
    myservo1.write(pos1);
  }
  //Serial.println("mot1: " + String(pos1));
}
Ticker ticservo1( fservo1,15);

void fservo2(){
  //delay(5);
  if (pos2 != setpoint2){
    if (pos2<setpoint2){
      pos2+=1;
    }
    if (pos2>setpoint2){
      pos2-=1;
    }
    myservo2.write(pos2);
  }
  //Serial.println("mot2: " + String(pos2));
}
Ticker ticservo2( fservo2,15);

void fservo3(){
  //delay(5);
  if (pos3 != setpoint3){
    if (pos3<setpoint3){
      pos3+=1;
    }
    if (pos3>setpoint3){
      pos3-=1;
    }
    myservo3.write(pos3);
  }
  //Serial.println("mot3: " + String(pos3));
}
Ticker ticservo3( fservo3,15);



//Funcion encargada de mover todos los motores, asigna el valor(value) al setpoint de cada motor
//Recibe un valor completo que viene desde el serial de python, lo separa(lo divide) y lo asigna cada valor extraido al setpoint de cada motor
void mov_all_motors(String value){  
    int val;
    int pos;
    pos = value.indexOf(','); //retorna el índice en el que se puede encontrar una ',', ó retorna -1 si ',' no esta presente.
    String m0 = value.substring(0,pos); //extrae caracteres desde 0 (indiceA) hasta pos(indiceB) sin incluirlo
    val = m0.toInt(); //Convierte value(un string) en un número entero
    //val = map(val, -90, 90, 0, 180); //Se mapea el valor del servo motor pasando de -90 a 90 s valores positivos entre 0 y 180
    if(setpoint0 != val)  setpoint0 = val; //Se asigna el valor al setpoint0 
    
    
    value = value.substring(pos+1);
    pos = value.indexOf(','); 
    String m1 = value.substring(0,pos);
    val = m1.toInt();
    //val = map(val, 0, 180, 0, 180);
    if(setpoint1 != val)  setpoint1 = val;
    
    /*value = value.substring(pos+1);
    pos = value.indexOf(',');
    String m3 = value.substring(0,pos);
    val = m3.toInt();
    val = map(val, 40, -80, 0, 120);
    if(setpoint3 != val)  setpoint3 = val;*/

    value = value.substring(pos+1);
    pos = value.indexOf(',');
    String m2 = value.substring(0,pos);
    val = m2.toInt();
    //val = map(val, -90, 90, 0, 180);
    if(setpoint2 != val)  setpoint2 = val;

    value = value.substring(pos+1);
    pos = value.indexOf(',');
    String m3 = value.substring(0,pos);
    val = m3.toInt();
    //val = map(val, -90, 90, 0, 180);
    if(setpoint3 != val)  setpoint3 = val;

}

void ejecuta_ciclo(){   //Mediante ticker va ir cambiando el setpoint para ir ejecutando la secuencia del brazo robótico
    mov_all_motors(myArray[n]);
    n+=1;
    if (n>=veces)
    {
      n=0;
      var= false;
    }
}
Ticker ticmovposicion( ejecuta_ciclo,3000);

//Funcion para pausar el ciclo
void detener_motores(){
  pos0=myservo0.read();  //Aquí se leen la posición de los servomotores
  pos1=myservo1.read();
  pos2=myservo2.read();
  pos3=myservo3.read();
  
  setpoint0=pos0;   //Estas posiciones se deben mantener para estando en pausa
  setpoint1=pos1;
  setpoint2=pos2;
  setpoint3=pos3;
}

void fnActuadores(String cad){   // Cada valor que venga desde python tendrá una etiqueta 
  String label;
  String value;
  int pos;
  cad.trim(); //Elimina los espacios en blanco(todos los caracteres sin contenido "espacio, tabulación, etc.") en ambos extremos del string
  cad.toLowerCase();  //Este método devuelve el valor de la cadena convertida a minúsculas. No afecta al valor de la cadena en sí misma.
  pos = cad.indexOf(':'); //retorna el índice en el que se puede encontrar un ':', ó retorna -1 si ':' no esta presente.
  label= cad.substring(0,pos); //extrae caracteres desde 0 (indiceA) hasta pos(indiceB) sin incluirlo
  value= cad.substring(pos+1); //Como se omite el indiceB, substring extrae caracteres hasta el final de la cadena.
  Serial.println(label);
  
  if (label.equals("mot0")){     //Con cada if se identifica cuál etiqueta o label es
    int val=value.toInt();  //Convierte value(un string) en un número entero
    //val = map(val, -90, 90, 0, 180);
    //val = map(val, -90, 90, 0, 180);
    if(setpoint0 != val)  setpoint0 = val;
  }
  if (label.equals("mot1")){
    int val=value.toInt();
    //val = map(val, 40, -80, 0, 180);
    //val = map(val, -90, 90, 0, 180);
    if(setpoint1 != val)  setpoint1 = val;
  }
  /*if (label.equals("mot3")){
    int val=value.toInt(); 
    val = map(val, -90, 90, 0, 180);
    if(setpoint3 != val)  setpoint3 = val;
  }*/
   if (label.equals("mot2")){
    int val=value.toInt();
    //val = map(val, 90, 0, 0, 90);
    //val = map(val, -90, 90, 0, 180);
    if(setpoint2 != val)  setpoint2 = val;
  }
  if (label.equals("mot3")){
    int val=value.toInt();
    //val = map(val, 90, 0, 0, 90);
    //val = map(val, -90, 90, 0, 180);
    if(setpoint3 != val)  setpoint3 = val;
  }

  // Para el control del brazo robótico para iniciar, pausar,finalizar,etc. el ciclo de trabajo
  if (label.equals("mot")){
    mov_all_motors(value);
  }
  if (label.equals("to")){
    myArray[n]=value;  //Guarda en el arreglo las posiciones que se van a ir recibiendo cada vez que se indique desde python que se va a agregar la posición a la secuencia de trabajo
    n+=1;
  }
  if (label.equals("delete")){ //Elimina la secuencia de trabajo
    n=0;
    for (int i=0;i<20;i++){
      myArray[i]="";
    }
  }
  if (label.equals("run")){ //Inicia la secuencia de trabajo
    n=0;
    var=true;
    veces = value.toInt();
  }
  if (label.equals("stop")){ //Finaliza la secuencia de trabajo
    var=false;
    mov_all_motors(value);
  }
  if (label.equals("pause")){ //Pausa la secuencia de trabajo
    var=false;
    detener_motores();
  }
  if (label.equals("continue")){ ////Continua la secuencia de trabajo
    var=true;
  }
}
