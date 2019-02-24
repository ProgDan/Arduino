//Programa : Demonstracao do display de 7-segmentos no shield multifuncoes
//Autor : Daniel Arndt Alves
// Adaptado do exemplo da biblioteca <MultiFuncShield.h>
 
 
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
 
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
   
  MFS.write("ola"); // E possivel escrever algumas letras
  delay(2000);
  MFS.write(-123); // Pode-se escrever numeros de ate 4 digitos, ou 3 se tiver o sinal negativo
  delay(2000);
   
  MFS.blinkDisplay(DIGIT_1, ON); // Tambem e possivel piscar os digitos
  delay(500);
  MFS.blinkDisplay(DIGIT_2, ON);
  delay(500);
  MFS.blinkDisplay(DIGIT_1, OFF);
  delay(500);
  MFS.blinkDisplay(DIGIT_3, ON);
  delay(500);
   
  MFS.write(3.1415, 2);  // E escrever numeros com virgula. O 2 define o numero de casas depois da virgula
  delay(200);
   
  MFS.blinkDisplay(DIGIT_2, OFF);
  delay(500);
  MFS.blinkDisplay(DIGIT_4, ON);
  delay(500);
  MFS.blinkDisplay(DIGIT_3, OFF);
  delay(500);
  MFS.blinkDisplay(DIGIT_ALL, ON);
  delay(3000);
  MFS.blinkDisplay(DIGIT_ALL, OFF);
}

int contador=0; // definimos contador
boolean fim = false; // e um booleano para parar 

void loop() {
  if (contador < 9999)
  {
    MFS.write((int)contador); // Escreve variavel no display
    contador++;
  }
  else if (!fim)
  {
    fim = true; 
    MFS.write("cabo"); // Acabou a contagem
    MFS.blinkDisplay(DIGIT_ALL, ON);
  }
  delay(5);
}
