//Programa : Contador utilizando botoes no shieldmultifuncoes
//Autor : Daniel Arndt Alves
 
#include <TimerOne.h>
#include <Wire.h>
#include "MultiFuncShield.h"
 
void setup() {
 Timer1.initialize();
  MFS.initialize(&Timer1);    // inicializa a biblioteca
}

int valor = 0; // Valor do contador

void loop() {
  byte botao = MFS.getButton(); // Recebe o Byte da função MFS.getButton();
   
  if(botao){ // Se for pressionado algum botao
     
    if(botao == BUTTON_1_PRESSED ){ // Se o botao pressionado for o 1, diminui em 1 o valor
      valor = valor -1;
    }
    else if(botao == BUTTON_2_PRESSED ){ // Se o botao pressionado for o 2, aumenta 10 no valor
      valor = valor + 10;
    }
    else if(botao == BUTTON_3_PRESSED ){ // Se o botao pressionado for o 3, aumenta em 1 o valor
      valor = valor + 1;
    }
   
  }
  MFS.write((int) valor); // Mostra os valores no display de 7 segmentos, independentemente do botao apertado
}
