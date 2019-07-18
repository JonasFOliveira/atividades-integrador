//Criação de variaveis globais
//LedInXXX é a variavel que consta o numero das portas de entrada
//LedOutXXX é a variavel que consta o numero das portas de saidas
//LedSinXXX é a variavel que consta o sinal das portas

int ledInLar = 2;
int ledOutLar = 5;
int ledInAzu = 3;
int ledOutAzu = 6;
int ledInRos = 4;
int ledOutRos = 7;
int ledSinLar, ledSinAzu, ledSinRos = 0;

void setup()
{
  //setando as entradas e saidas de informação
  pinMode(ledInLar, INPUT);
  pinMode(ledInAzu, INPUT);
  pinMode(ledInRos, INPUT);
  pinMode(ledOutLar, OUTPUT);
  pinMode(ledOutAzu, OUTPUT);
  pinMode(ledOutRos, OUTPUT);
}

void loop()
{
  //lendo e amarzenando os valores recebidos dos botões
  //var = digitalRead(porta);
  
  ledSinLar = digitalRead(ledInLar);
  ledSinAzu = digitalRead(ledInAzu);
  ledSinRos = digitalRead(ledInRos);
  	
  // testando qual botão está ligado para que possa ser enviado a informação para o arduino 2
	if (ledSinLar == 1) {
  		digitalWrite(ledOutLar, HIGH);
	}
	else if (ledSinAzu == 1) {
  		digitalWrite(ledOutAzu, HIGH);
	}
  	else if (ledSinRos == 1) {
  		digitalWrite(ledOutRos, HIGH);
	}
	else {
  		digitalWrite(ledOutLar, LOW);
        digitalWrite(ledOutAzu, LOW);
        digitalWrite(ledOutRos, LOW);
	}
  	
}