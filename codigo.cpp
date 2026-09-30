// autor: Michel
// data: 29/09/2026

// Este programa controla um servo motor com base no valor de um potenciômetro

// incluindo a biblioteca Servo.h para controlar o servo motor

#include "Servo.h"

Servo servo; // criando um objeto servo da classe Servo 
int POT = A0; // definindo o pino do potenciômetro 
int SERVO = 3; // definindo o pino do servo motor, usar um pino PWM (3, 5, 6, 9, 10 ou 11)
int valorPot; // variável para armazenar o valor lido do potenciômetro 
int valorMotor = 0; // variável para armazenar o valor mapeado para o servo motor

// função setup() é chamada uma vez quando o programa inicia
void setup()
{
  servo.attach(SERVO); // anexando o pino do servo motor ao objeto servo
  Serial.begin(9600); // inicializando a comunicação serial a 9600 bps
}

// função loop() é chamada repetidamente enquanto o programa estiver em execução
void loop()
{
	valorPot = analogRead(POT); // lendo o valor do potenciômetro (0 a 1023)
  	valorMotor = map(valorPot,0,1023,0,180); // mapeando o valor do potenciômetro para o intervalo de 0 a 180 graus do servo motor
  	servo.write(valorMotor); // enviando o valor mapeado para o servo motor
  	Serial.print("Valor do potenciometro: ");
  	Serial.println(valorMotor);  // imprimindo o valor do potenciômetro mapeado no monitor serial
  	delay (20); // adicionando um pequeno atraso para estabilizar a leitura do potenciômetro
}