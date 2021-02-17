//Ano: 2018
//Disciplina: Sistemas micro controlados
// Plataforma robotica controlado por Bluetooth
// Co-Autor : Pabllo Lins
/*
 * Shields: HC-05, L293d Stepper Motor Dc E Servo
 * 2 motores DC para controle das rodas
 * Arduino UNO R3
 */


//Armazena o caracter recebido
//conectar RX do módulo no TX do Arduino
//conectar TX do módulo no RX do Arduino

#include "SoftwareSerial.h"

SoftwareSerial bluetooth(2, 13); // RX | TX

#include <AFMotor.h> // carrega a biblioteca do shield AFMotor

AF_DCMotor motor1E(1); // Define o motor1 ligado a conexao 1 como esquerdo
AF_DCMotor motor2D(4); // Define o motor2 ligado a conexao 4 como direito

char buf;
int incomingByte;
 
void setup()
{
 motor1E.setSpeed(250); //Ajusta a velocidade de rotação do motor, podendo ser um valor entre 0 (mínimo) e 255 (máximo)
 motor2D.setSpeed(250); //Ajusta a velocidade de rotação do motor, podendo ser um valor entre 0 (mínimo) e 255 (máximo)  
 //Initialize the software serial
  bluetooth.begin(9600);
}
 
void loop()
{
   if (bluetooth.available() > 0)
  //while(Serial.available() > 0)
  {
     incomingByte = bluetooth.read();
    //buf = Serial.read();

    if (incomingByte == 'F')
    //FRENTE
  {
   motor1E.run(BACKWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(FORWARD); // Aciona o motor 2 no sentido horario  
  }
  
    if (incomingByte == 'T')
    //TRAS
  {
   motor1E.run(FORWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(BACKWARD); // Aciona o motor 2 no sentido horario  
  }
  
    if (incomingByte == 'E')
     //ESQUERDA
  {     
  motor1E.run(FORWARD); // Aciona o motor 1 no sentido anti-horario  
  motor2D.run(FORWARD); // Aciona o motor 2 no sentido horario   
  }
    if (incomingByte == 'D')
    //DIREITA
  {  
   motor1E.run(BACKWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(BACKWARD); // Desliga o motor 2 
  }

  if (incomingByte == '0')
    //ESQUERDA
  {  
   motor1E.run(RELEASE); // Aciona o motor 1 no sentido horario 
   motor2D.run(RELEASE); // Desliga o motor 2 
  }
  }
}
