/*--------------------------
 * Este é o códiogo da mão biônica desenvolvida pela ESERO Portugal
 * A mão foi apresentada pela primeira vez, na 6ª Conferência dos Professores espaciais
 * Toda a informação que precisares pode ser encontrada em https://github.com/njrebelo/Bionichand-ESEROPortugal
 * 
 * Para informações extra contactar nj.rebelo@campus.fct.unl.pt
 * @NelsoRebelo
----------------------------*/

//Bibliotecas de Rádio
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // Pins CE e CSN usados na comunicacão rádio
const byte address[6] = "00001";//Cana de comunicação

const char finger[] = {A0,A1,A2,A3,A4}; // Portas usadas para a leitura das resistências
int m_angle0[100],m_angle1[100],m_angle2[100],m_angle3[100],m_angle4[100];//Matrizes para a configuração dos dedos
int min_angle[5],max_angle[5];//Matriz com os valores maximos e mínimos para cada dedo
int angle0,angle1,angle2,angle3,angle4; // Variáveis que vão enviar a informação

void setup() {
  Serial.begin(9600);//Iniciar porta série
  
  pinMode(finger[0], INPUT);//Declara os pins das resistências como de input
  pinMode(finger[1], INPUT);
  pinMode(finger[2], INPUT);
  pinMode(finger[3], INPUT);
  pinMode(finger[4], INPUT);
  
  radio.begin(); //Comandos para inicar os protocolos de rádio
  radio.openWritingPipe(address);//Declaração do canal de comunicação
  radio.setPALevel(RF24_PA_MIN);//Potência do Sinal (onde está MIN pode estar, LOW, HIGH ou MAX)
  radio.stopListening();//Para de ouvir, para poder comunicar

  /* configuração luva - leva sensivelmente 2 minutos*/
  Serial.println("Iniciando configuração");
  for(int i=0; i<100; i++){//Vamos fazer várias medições do valor das resistências, a pessoa deve abrir e fechar a mão repetidamente
    m_angle0[i]=analogRead(finger[0]);
    m_angle1[i]=analogRead(finger[1]);
    m_angle2[i]=analogRead(finger[2]);
    m_angle3[i]=analogRead(finger[3]);
    m_angle4[i]=analogRead(finger[4]);
    delay(1000);
    }
  min_angle[0]=getMin(m_angle0,100);//Cálculo do valor mínimo da resistência
  min_angle[1]=getMin(m_angle1,100);
  min_angle[2]=getMin(m_angle2,100);
  min_angle[3]=getMin(m_angle3,100);
  min_angle[4]=getMin(m_angle4,100);

  max_angle[0]=getMax(m_angle0,100);//Cálculo do valor máximo da resistência
  max_angle[1]=getMax(m_angle1,100);
  max_angle[2]=getMax(m_angle2,100);
  max_angle[3]=getMax(m_angle3,100);
  max_angle[4]=getMax(m_angle4,100);
  
}
void loop() {
  angle0=angle(0);//medições do ângulos
  angle1=angle(1);
  angle2=angle(2);
  angle3=angle(3);
  angle4=angle(4);
  
  const char text[] = {angle0, angle1, angle2, angle3, angle4};//Variável para enviar a informação
  radio.write(&text, sizeof(text));//Envio da informação
  
  Serial.print(text);//Porta ´serie da informação enviar
  Leituras();
  
  delay(500);  
}

void Leituras(){//Função para vermos o valor de cada ângulo
  Serial.print(angle0);
  Serial.print(",");
  Serial.print(angle1);
  Serial.print(",");
  Serial.print(angle2);
  Serial.print(",");
  Serial.print(angle3);
  Serial.print(",");
  Serial.println(angle4);

  return;
  }

int angle(int x){
  float flexADC = analogRead(finger[x]);
  float angle = map(flexADC, min_angle[x], max_angle[x], 0, 180);
  return angle;
  }


int getMin(int* array, int size)
{
  int minimum = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] < minimum) minimum = array[i];
  }
  return minimum;
}

int getMax(int* array, int size)
{
  int maximun = array[0];
  for (int i = 0; i < size; i++)
  {
    if (array[i] > maximun) maximun = array[i];
  }
  return maximun;
}
