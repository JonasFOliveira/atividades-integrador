//incluir biblioteca LiquidCrystal para o LCD
#include <LiquidCrystal.h>

//Criação de variaveis globais
//LedOutXXX é a variavel que consta o numero das portas
//LedSinXXX é a variavel que consta o sinal das portas
int ledInLar = 5;
int ledInAzu = 6;
int ledInRos = 7;
int ledSinLar = 0;
int ledSinAzu = 0;
int ledSinRos = 0;

//Setando as entradas do LCD nas portas digitais do arduino
//OBS.: só está sendo usado 4 bits para construir 1 byte
LiquidCrystal lcd(8,9,10,11,12,13);

void setup()
{
  //setando as entradas de informação enviada do arduino 1
 
  pinMode(ledInLar, INPUT);
  pinMode(ledInAzu, INPUT);
  pinMode(ledInRos, INPUT);
   
  //.begin seta o tamanho do lcd (largura, altura)
  lcd.begin(16,2);
  
 }

void loop()
{
  //lendo e amarzenando os valores recebidos do arduino 1
  //var = digitalRead(porta);
  ledSinLar = digitalRead(ledInLar);
  ledSinAzu = digitalRead(ledInAzu);
  ledSinRos = digitalRead(ledInRos);

  //Testando e exibindo qual botão foi pressionado
  //só pode apertar um por vez, se não ele fica aguardando informação
  if(ledSinLar == 1 && ledSinAzu == 0 && ledSinRos == 0){
   //.clear() limpa a tela do LCD
    lcd.clear();
   //.rint("informação") imprime a informação na tela do LCD
    lcd.print("laranja");
    delay(50);
    
    }else if(ledSinLar == 0 && ledSinAzu == 1 && ledSinRos == 0){
    lcd.clear();
    lcd.print("azul");
    delay(50);
    
    }else if(ledSinLar == 0 && ledSinAzu == 0 && ledSinRos == 1){
    lcd.clear();
    lcd.print("branco");
    delay(50);
    
    }else {
      lcd.clear();
      lcd.print("Aguardando...");
 	//.setCursor(X,Y) posiciona o cursos na coluna X e linha Y
      lcd.setCursor(0, 1);
	  lcd.print("PRESS A BUTTON");
      delay(50);
    }
}
