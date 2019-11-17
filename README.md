# Bionichand ESEROPortugal
O nosso objetivo foi o de desenvoler uma mão bionica suportada pela tecnologia arduino. O utilizador usa uma luva bionnica que recolhe informação sobre a mão do utiliador. A mão bionica, uma protese impressa em 3D, recebe esta informação por radio-frequencias, e replica o movimento da mão do utilizador.


O nosso esforço exprime-se em criar esta e outras ferramentas educacionais. A ideia é poder tradabalhar as mais diversas aptidoes desde um nível elevados na aquisição de dados, tratamento de dados e aplicações com inteligência artificial, até niveis mais simples, como usar a luva para controlar uma janela, sintetizar voz ou controlar uma cadeira de rodas.

Na sua utilização fundamental, as escolas vão poder receber a luva e a mão a desempenhar as suas funções básicas. Desde que as ligações elétricas estejam bem feitas, danificar a mão ou a luva, é quase impossível. Por isso a nossa primeira sugestão é a de deixarem os vossos alunos explorarem

### Sensores
> Arduino Nano - 2 uni -  [PTRobotics](https://www.ptrobotics.com/plataformaarduino-e-modelos-alternativos-equivalentes/5458-iteaduino-mini-nano-v30-atmega328-board-for-arduino-ide-arduino-compatible.html?search_query=nano&results=41)

> Sensor de Flexão - 5 uni - [PTRobotics](https://www.ptrobotics.com/sensores-forca-vibracao-e-pressao/1060-flex-sensor-22.html?search_query=forca&results=21)

> Transmissor - 1 uni - [PTRobotics](https://www.ptrobotics.com/nordic-nrf24/5476-1100-meter-long-distance-nrf24l01palna-wireless-module-with-antenna.html?search_query=NRF24L01&results=23)

> Receptor - 1 uni - [PTRobotics](https://www.ptrobotics.com/nordic-nrf24/5965-nrf24l01-rf-board.html?search_query=NRF24L01&results=23)

> Adaptador - 1 uni - [PTRobotics](https://www.ptrobotics.com/nordic-nrf24/6081-socket-adapter-for-8pin-nrf24l01-wireless-transceivers.html?search_query=NRF24L01&results=23)

> Servos - 1 uni - [PTRobotics](https://www.ptrobotics.com/servo/2398-standard-analogue-servo-bms-410c.html?search_query=servo&results=174)


Podem usar outro forncedor, e podem também utilizar outros sensores, este é só o nosso exemplo.

### Luva
Esta é a nossa luva
![alt text](https://i.imgur.com/lRJcfVv.jpg)


Basicamente, temos um divisor de tensão em cada dedo. Usamos duas resistências, uma fixa, e uma variável ( o nosso flexo sensor), e elas são dispostas desta maneira.
![alt text](https://bildr.org/blog/wp-content/uploads/2012/11/flex-sensor-arduino.png)

### Modelo 3D
Para a modelação 3D baseamo-nos no projeto [InMoov](http://inmoov.fr/hand-and-forarm/), um projeto internacional para a modelação do corpo humano
Nesse link podem encontrar o modelo 3D que usamos, e instruções para a sua impressão.
Esta é a nossa mão.
![alt text](https://i.imgur.com/PUOArFu.jpg)


Ela consiste basicamente em 5 servos controlados pelo arduino nano.
![alt text](https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwjYocHXufLlAhUi5uAKHdW4DZ8QjRx6BAgBEAQ&url=https%3A%2F%2Fwww.arduino.cc%2Fen%2Ftutorial%2Fsweep&psig=AOvVaw3xnnfvbHxXo93djRDLfqau&ust=1574121495719473)


## Empréstimo
O empréstimo do equipamento deverá ficar disponível apartir de Janeiro de 2020 na página da [ESERO Portugal](https://www.esero.pt/454/emprestimos/)
Para mais informações podem entrar em contacto connosco [aqui](https://www.esero.pt/280/contactos/)
