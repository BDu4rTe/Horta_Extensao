bool leituraAnterior;
int luminosidade;
int umidade;

void setup() {
  
  //Higrometro
  pinMode(A1, INPUT);
  
  //LDR
  pinMode(A0, INPUT);

  //Solenoid
  pinMode(3, OUTPUT);
  
  //LEDs
  pinMode(7, OUTPUT);  //vermelho
  pinMode(6, OUTPUT);  //azul
  pinMode(5, OUTPUT);  //verde
}

void loop() {
  luminosidade = analogRead(A0);
  umidade = analogRead(A1);

   if (luminosidade <= 200 && umidade >= 801){
     //Sol fote luminosidade 0 - 200 e solo seco 801 - 1023 
     digitalWrite(7, HIGH);  
     digitalWrite(5, LOW);   
  } if (luminosidade >= 201 && luminosidade <= 800){
     if (umidade >= 501 && umidade <= 800) { 
     //Sol moderado 201 - 800 e solo normal 501 - 800
     digitalWrite(7, LOW);   
     digitalWrite(5, HIGH);  }
  }   
  if (luminosidade >= 201 && luminosidade <= 800) {
      if (umidade >= 801){ 
         //Sol moderado 201 - 800 e solo seco 801 - 1023
         digitalWrite(5, LOW);   
         digitalWrite(6, HIGH);
         while (umidade >= 650 ) {
            digitalWrite(3, HIGH);   
            delay(500);
            digitalWrite(3, LOW);   

            delay(10000);          
            }
         digitalWrite(6, LOW);
         digitalWrite(5, HIGH); 
      }
    }
   
};
