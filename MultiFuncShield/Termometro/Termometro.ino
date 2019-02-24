/* 
  Programa de teste do DS18B20 no Shield Multi-função
  Arduino UNO - Shield Multi-função para Arduino
  Daniel Arndt Alves
  Não remova o jumper J1 e verifique como inserir o DS18B20 no soquete
  Blog Eletrogate - http://blog.eletrogate.com/guia-completo-do-shield-multi-funcoes-para-arduino
*/
 
#include <MultiFuncShield.h>                           // Biblioteca Multifunction shield
#include <OneWire.h>                                   // Biblioteca OneWire
#include <DallasTemperature.h>                         // Biblioteca do sensor DS18B20
 
 
#define ONE_WIRE_BUS A4                                // pino de dados DS18B20 = A4 do Arduino 
OneWire oneWire(ONE_WIRE_BUS);                         // criando a instancia do sensor
DallasTemperature sensors(&oneWire);
 
void setup() {
  sensors.begin();                                     // inicializando o sensor 
  MFS.initialize(&Timer1);                             // inicializa a biblioteca Multi função
}

void loop() {
  sensors.requestTemperatures();                       // envia o camando para o sensor 
  float tempCentigrade = sensors.getTempCByIndex(0);   // lê a temperatura no DS18B20 
  MFS.write(tempCentigrade, 1);                        // mostra a temperatura no display(1 casa decimal) 
  delay(200);                                          // atraso de 200 milisegundos 
}
