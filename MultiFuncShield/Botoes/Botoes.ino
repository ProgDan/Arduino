/* 
  Programa de teste dos Botões do Shield Multi-função
  Arduino UNO - Shield Multi-função para Arduino
  Daniel Arndt Alves
  Baseado em http://www.cohesivecomputing.co.uk/hackatronics/arduino-multi-function-shield/part-1/
  Blog Eletrogate - http://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
*/
 
#include <TimerOne.h>                     // Biblioteca TimerOne 
#include <Wire.h>                         // Biblioteca Wire 
#include <MultiFuncShield.h>              // Biblioteca Multifunction shield
 
void setup() {
  Serial.begin(9600);                              // monitor serial 9600 Bps 
  Timer1.initialize();                             // inicializa o Timer 1
  MFS.initialize(&Timer1);                         // initializa a biblioteca Multi função
  Serial.println("Pressione um ou mais Botoes");   // imprime mensagem
}

void loop() {
  byte btn = MFS.getButton();                            // lendo os botões
 
  if (btn)                                               // se botão pressionado 
  {
    byte buttonNumber = btn & B00111111;                 // comparando os bits das portas analógicas
    byte buttonAction = btn & B11000000;  
 
    Serial.print("BOTAO_");                              // imprime mensagem
    Serial.write(buttonNumber + '0');                    // imprime número do botão 
    Serial.print("_");                                   // imprime traço
 
    if (buttonAction == BUTTON_PRESSED_IND)              // compara a ação do botão 
    {
      Serial.println("PRESSIONADO");                     // imprime mensagem
    }
    else if (buttonAction == BUTTON_SHORT_RELEASE_IND)   // compara a ação do botão
    {
      Serial.println("SOLTA RAPIDO");                    // imprime mensagem
    }
    else if (buttonAction == BUTTON_LONG_PRESSED_IND)    // compara a ação do botão
    {
      Serial.println("PRESSIONADO LONGO");               // imprime mensagem
    }
    else if (buttonAction == BUTTON_LONG_RELEASE_IND)    // compara a ação do botão
    {
      Serial.println("SOLTA LONGO");                     // imprime mensagem
    }
  }
}
