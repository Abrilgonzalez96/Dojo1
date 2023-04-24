// C++ code
//
#define Led_Red1 13
#define Led_Red2 12
#define Led_Red3 11
#define Led_Yellow1 10
#define Led_Yellow2 9
#define Led_Yellow3 8
#define Led_Green1 7
#define Led_Green2 6
#define Led_Green3 5
#define Buzzer 4

void prendeYApagaLed(int led1, int led2, int led3, int tiempo,int tiempo_Sumar, int cant_sonar, int tiempo_Low_Buzzer, int tiempo_High_Buzzer, int volumen);
void power_buzzer(int cant_sonar, int tiempo_High, int tiempo_Low, int volumen, int led1, int led2, int led3);
void juego_luces(int led1, int led2, int led3, int tiempo, int cant_Repe);

void setup(){
  pinMode(Led_Red1, OUTPUT);
  pinMode(Led_Red2, OUTPUT);
  pinMode(Led_Red3, OUTPUT);
  pinMode(Led_Yellow1, OUTPUT);
  pinMode(Led_Yellow2, OUTPUT);
  pinMode(Led_Yellow3, OUTPUT);
  pinMode(Led_Green1, OUTPUT);
  pinMode(Led_Green2, OUTPUT);
  pinMode(Led_Green3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
}


void loop(){
  
  prendeYApagaLed(Led_Red1, Led_Red2, Led_Red3, 0, 0, 15, 1000, 1000, 100);
  prendeYApagaLed(Led_Yellow1, Led_Yellow2, Led_Yellow3, 0, 0, 2, 2000, 500, 1000);
  prendeYApagaLed(Led_Green1, Led_Green2, Led_Green3, 19000, 20000, 0, 0, 0, 0);
}		
  
void prendeYApagaLed(int led1, int led2, int led3, int tiempo,int tiempo_Sumar, int cant_sonar, int tiempo_Low_Buzzer, int tiempo_High_Buzzer, int volumen){
 //Recibe tres led del mismo color, para generar la secuencia de luces que realiza un semaforo
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  if(led1 == 13 or led1 == 10){
  	power_buzzer(cant_sonar, tiempo_High_Buzzer, tiempo_Low_Buzzer, volumen, led1, led2, led3);//Solo las led rojas y amarillas emiten sonido
  }
  delay(tiempo);
  delay(tiempo_Sumar);
  if (led1 == 7){
    juego_luces(led1, led2, led3, 2000, 3); //Se manda por parametro las led verdes para producir el juego de luces
    
  }
   digitalWrite(led1, LOW);
   digitalWrite(led2, LOW);
   digitalWrite(led3, LOW);
   delay(500); 
}

void power_buzzer(int cant_sonar, int tiempo_High, int tiempo_Low, int volumen, int led1, int led2, int led3){
  //Emite sonido para ayudar a los no videntes saber en que color esta el semaforo
  for (int i = 0; i < cant_sonar; i++) {
  	tone(Buzzer, volumen);
    if (i > (cant_sonar - 4) and led1 != 10){
    	juego_luces(led1, led2, led3 , tiempo_High, 1); //Se manda por parametro las led rojas para que cuando este emitiendo los ultimos sonidos haga el juego de luces antes de cambiar de color
    } else {
      delay(tiempo_High);
    }
  	noTone(Buzzer);
    delay(tiempo_Low);
  }
}

void juego_luces(int led1, int led2, int led3, int tiempo, int cant_Repe){
  //Juego de luces que avisa cuando esta por cambiar de color
  for (int i = 0; i < cant_Repe; i++){
  	digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  	delay(500);
  	digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  	delay(tiempo - 500);
    
  }
}



