/* 
  Programa de teste do POT do Shield Multi-função
  Arduino UNO - Shield Multi-função para Arduino
  Daniel Arndt Alves
  Baseado em http://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/
  Blog Eletrogate - http://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
*/
 
#include <TimerOne.h>                     // Bibliotec TimerOne 
#include <Wire.h>                         // Biblioteca Wire 
#include <MultiFuncShield.h>              // Biblioteca Multifunction shield

void setup() {
  Timer1.initialize();                    // inicializa o Timer 1
  MFS.initialize(&Timer1);                // initializa a biblioteca Multi função
}

void loop() {
  MFS.write(analogRead(POT_PIN));         // le a tensão no Potenciometro 
                                          // e mostra no display 
  delay(100);                             // atraso de 100 milisegundos 
}
