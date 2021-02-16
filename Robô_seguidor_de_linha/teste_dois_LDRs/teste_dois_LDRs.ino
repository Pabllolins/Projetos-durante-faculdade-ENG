/************************************\
|   Código Elaborado por RoboCore    |
| Sinta-se livre para usar ou editar |
|    SEMPRE cite a fonte do código   |
|          www.RoboCore.net          |
\************************************/

//quanto menor o valor, maior é a captação de luz no sensor

int sensor0 = A0;
int sensor1 = A1;

int valorSensor0 = 0;  
int valorSensor1 = 0;

void setup() 
{
    Serial.begin(9600);
}

void loop() 
{
  valorSensor0 = analogRead(sensor0);    
  valorSensor1 = analogRead(sensor1); 
  Serial.print("\n\n\nSensor0: ");
  Serial.print(valorSensor0);
  
  Serial.print("\nSensor1: ");
  Serial.print(valorSensor1);
  
  delay(250);
}
