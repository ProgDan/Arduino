//Programa : Demonstracao dos LEDs no Shield multifuncoes
//Autor : Daniel Arndt Alves 
// Adaptado do exemplo da biblioteca <MultiFuncShield.h>
 
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>
 
void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);    // Inicializa a biblioteca do shield multifuncoes
   
  MFS.writeLeds(LED_ALL, ON); // Acende todos os LEDs
  delay(2000);
   
  MFS.blinkLeds(LED_1 | LED_2, ON); // Pisca o LED1 e o LED2
  delay(2000);
  MFS.blinkLeds(LED_1 | LED_2, OFF); // Para de piscar
   
  MFS.blinkLeds(LED_3 | LED_4, ON); // Pisca o LED1 e o LED2
  delay(2000);
  MFS.blinkLeds(LED_3 | LED_4, OFF);// Para de piscar
  delay(2000);
   
  MFS.blinkLeds(LED_ALL, ON);// Pisca todos os LEDs
  delay(2000);
  MFS.blinkLeds(LED_ALL, OFF); // Para de piscar
 
  delay(2000);
  MFS.writeLeds(LED_ALL, OFF); // Desliga todos os LEDs   
}

void loop() {
}
