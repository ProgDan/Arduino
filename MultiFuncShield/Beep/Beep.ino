//Programa : Demonstração do buzzer no Shield multifuncoes
//Autor : Daniel Arndt Alves 
// Adaptado do exemplo da biblioteca <MultiFuncShield.h>
#include <TimerOne.h>
#include <Wire.h>
#include "MultiFuncShield.h"

void setup() {
  // Esse trecho de codigo so ira rodar uma vez
  Timer1.initialize();
  MFS.initialize(&Timer1);     // Inicializa a biblioteca do shield multifuncoes
   
  // A funcao "beep()" e feita em segundo plano e o arduino pode realizar outras tarefas enquanto roda
   
   
  // 4 bips curtos, repetindo 3 vezes
  MFS.beep(5,    // O bip dura 50 milisegundos
           5,    // Fica em silencio por mais 50 milisegundos
           4,    // Repetir o padrao definido acima por 4 vezes
           3,    // Repetir 4 vezes (Loop)
           50    // Delay de 500 milisegundos entre loops
           );
}

void loop() {

}
