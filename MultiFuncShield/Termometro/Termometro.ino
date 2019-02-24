/* 
  Programa de teste do DS18B20 no Shield Multi-função
  Arduino UNO - Shield Multi-função para Arduino
  Daniel Arndt Alves
  Não remova o jumper J1 e verifique como inserir o DS18B20 no soquete
  Blog Eletrogate - http://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
*/
 
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
 
 
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);  // initialize multi-function shield library
  
  // Initialize using a low pass filter.
  // Choose either: SMOOTHING_NONE, SMOOTHING_MODERATE or SMOOTHING_STRONG
  MFS.initLM35(SMOOTHING_MODERATE);
}

void loop() {
  int tempCentigrade = MFS.getLM35Data(); // get centigrade in 1/10 of degree.
  MFS.write((float)tempCentigrade / 100, 1);  // display temp to 1 decimal place.
  delay(100);
}
