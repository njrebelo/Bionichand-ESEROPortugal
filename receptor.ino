/*--------------------------
 * Este é o códiog da mão biônica desenvolvida pela ESERO Portugal
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

//Bibliotecas dos servos
#include <Servo.h>

RF24 radio(7, 8); // Pins CE e CSN usados na comunicacão rádio
const byte address[6] = "00001";//Cana de comunicação
char text[5] = ""; //Variável onde guardamos os dados

//Declaração dos servos a serem usados
Servo myservo0;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;


int val1,val2,val3,val4,val5;//constantes que recebem os valores da luva


void setup() {
  Serial.begin(9600); //Abertura da comunicação de Série
  
  radio.begin(); //Iniciação do Módulo de Rádio
  radio.openReadingPipe(0, address); //declaração do canal de comunicação
  radio.setPALevel(RF24_PA_MIN); //Potência do Sinal (onde está MIN pode estar, LOW, HIGH ou MAX)
  radio.startListening(); //Declaração do Rádio como receptor
  
  myservo0.attach(6); //Declara que o servo 0 "ouve o pin D6
  myservo1.attach(5); //Declara que o servo 1 "ouve o pin D5
  myservo2.attach(4); //Declara que o servo 2 "ouve o pin D4
  myservo3.attach(3); //Declara que o servo 3 "ouve o pin D3
  myservo4.attach(2); //Declara que o servo 4 "ouve o pin D2
}


void ValoresRecebidos(){
  Serial.println(text);
  
  return;
  }

  
void AngulosRecebidos(){
  Serial.print(val1);
  Serial.print(",");
  Serial.print(val2);
  Serial.print(",");
  Serial.print(val3);
  Serial.print(",");
  Serial.print(val4);
  Serial.print(",");
  Serial.print(val5);

  return;
  }
  

void loop() {
  if (radio.available()) {  //Esta condição determina que só prosseguimos o lopp se existir alguma comunicação
    radio.read(&text, sizeof(text));//O sensor de RF recebe o sinal e guarda-o na variável text, 5 caracteres em ASCII
    
    val1=atoi(text[0]);//Conversãlo de ASCII para inteiro
    val1=atoi(text[1]);
    val1=atoi(text[2]);
    val1=atoi(text[3]);
    val1=atoi(text[4]);

    ValoresRecebidos();
    AngulosRecebidos();
       
    myservo0.write(text[0]);             
    delay(15);
    myservo1.write(text[1]);              
    delay(15);   
    myservo2.write(text[2]);              
    delay(15);   
    myservo3.write(text[3]);              
    delay(15);   
    myservo4.write(text[4]); 
  }
  if (!radio.available()) {
    Serial.println("O módulo de rádio não está a funcionar");
    }
}


void ValoresRecebidos(){
  Serial.println(text);
  
  return;
  }

  
void AngulosRecebidos(){
  Serial.print(val1);
  Serial.print(",");
  Serial.print(val2);
  Serial.print(",");
  Serial.print(val3);
  Serial.print(",");
  Serial.print(val4);
  Serial.print(",");
  Serial.print(val5);

  return;
  }
  

void loop() {
  if (radio.available()) {  //Esta condição determina que só prosseguimos o lopp se existir alguma comunicação
    radio.read(&text, sizeof(text));//O sensor de RF recebe o sinal e guarda-o na variável text, 5 caracteres em ASCII
    
    val1=atoi(text[0]);//Conversãlo de ASCII para inteiro
    val1=atoi(text[1]);
    val1=atoi(text[2]);
    val1=atoi(text[3]);
    val1=atoi(text[4]);

    ValoresRecebidos();
    AngulosRecebidos();
       
    myservo0.write(text[0]);             
    delay(15);
    myservo1.write(text[1]);              
    delay(15);   
    myservo2.write(text[2]);              
    delay(15);   
    myservo3.write(text[3]);              
    delay(15);   
    myservo4.write(text[4]); 
  }
  if (!radio.available()) {
    Serial.println("O módulo de rádio não está a funcionar");
    }
}
