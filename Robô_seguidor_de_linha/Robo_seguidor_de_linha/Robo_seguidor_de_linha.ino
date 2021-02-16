// Projeto robo seguidor de linha
// Programa : Arduino Motor Shield - Controle motores DC
// Autor : Pabllo Lins
//Baseado no programa original de Michael McRoberts
//E baseado na postagem do site FILIPEFLOP
 
//quanto maior o valor, mais luz chega ao LDR (ligth dependent resistor), portanto está fora da linha escura
//quanto menor o valor, menos luz chega ao LDR (ligth dependent resistor), portanto está na linha escura

//SMotor Shield L293d Stepper Motor Dc E Servo

#include <AFMotor.h> // carrega a biblioteca do shield AFMotor

AF_DCMotor motor1E(1); // Define o motor1 ligado a conexao 1 como esquerdo
AF_DCMotor motor2D(4); // Define o motor2 ligado a conexao 4 como direito

int sensorLinhaDir = A1; //declara sensor RDL direito em uma variável inteira no pino A1
int sensorLinhaEsq = A0; //declara sensor RDL esquerdo em uma variável inteira no pino A0
int valorLinhaEsq = 0; //declara uma variável inteira para o valor do sensor esquerdo e atribue 0 ao seu valor 
int valorLinhaDir = 0; //declara uma variável inteira para o valor do sensor direito e atribue 0 ao seu valor  
int referencia = 200; //declara uma variável inteira para um valor de referência entre claro e escuro//130

   
void setup()
{
 pinMode(13, OUTPUT);              //diz que o pino 13 será uma saída LED vermelho
 pinMode(2, OUTPUT);              //diz que o pino 13 será uma saída
 digitalWrite(2, LOW); // LED verde acende  
 digitalWrite(13, LOW); // LED vermelho apaga
 motor1E.setSpeed(200); //Ajusta a velocidade de rotação do motor, podendo ser um valor entre 0 (mínimo) e 255 (máximo)
 motor2D.setSpeed(200); //Ajusta a velocidade de rotação do motor, podendo ser um valor entre 0 (mínimo) e 255 (máximo)        
}

void loop() 
{  
  valorLinhaEsq = analogRead(sensorLinhaEsq);    
  valorLinhaDir = analogRead(sensorLinhaDir);
  
  if((valorLinhaEsq < referencia)&&(valorLinhaDir < referencia)) //Se o valor lido nos LDR forem menor que a referência, está sobre a linha, move-se para frente
  {
   motor1E.run(BACKWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(FORWARD); // Aciona o motor 2 no sentido horario 
   digitalWrite(2, HIGH); // LED verde acende  
   digitalWrite(13, LOW); // LED vermelho apaga   
   analogRead(sensorLinhaDir);
   analogRead(sensorLinhaEsq);

  }

  if((valorLinhaEsq > referencia)&&(valorLinhaDir > referencia))//Se o valor lido nos LDR forem maior que a referência, está buscando a linha, move-se para frente
  {
   motor1E.run(BACKWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(FORWARD); // Aciona o motor 2 no sentido horario    
   digitalWrite(13, HIGH); // LED vermelho acende
   digitalWrite(2, LOW); // LED verde apaga
  analogRead(sensorLinhaDir);
  analogRead(sensorLinhaEsq);
  }
 
if((valorLinhaEsq > referencia)&&(valorLinhaDir < referencia)) //Se o valor lido nos LDR esquerdo for maior que a referência e o LDR direito for menor, move-se para direita)
  {     
  motor1E.run(FORWARD); // Aciona o motor 1 no sentido anti-horario  
  motor2D.run(FORWARD); // Aciona o motor 2 no sentido horario   
  digitalWrite(13, HIGH); // LED vermelho acende
  digitalWrite(2, LOW); // LED verde apaga
  analogRead(sensorLinhaDir);
  analogRead(sensorLinhaEsq);
  }
  
 if((valorLinhaEsq < referencia)&&(valorLinhaDir > referencia)) //Se o valor lido nos LDR esquerdo for menor que a referência e o LDR direito for maior, move-se para esquerda)
  {  
   motor1E.run(BACKWARD); // Aciona o motor 1 no sentido horario 
   motor2D.run(BACKWARD); // Desliga o motor 2 
   digitalWrite(13, HIGH); // LED vermelho acende
   digitalWrite(2, LOW); // LED verde apaga 
   analogRead(sensorLinhaDir);
   analogRead(sensorLinhaEsq);
  }

}
