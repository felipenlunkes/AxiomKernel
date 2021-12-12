/*

 Início do Axiom OS para ATMega328
 
 Copyright © 2013-2014 Felipe Miguel Nery Lunkes
 
 Interface gráfica em desenvolvimento
 
 */
/*

 */

#include <LiquidCrystal.h>



#include <Axiom.h>


Axiom AxiomKernel(13);  // Cria um objeto classe Axiom para ser usada dentro da classe principal
static volatile char iniciar;
static volatile const char AUTOR='Felipe Miguel Nery Lunkes';
static volatile const char SO='Axiom SO';
static volatile char string;
static volatile int numero1, numero2, total;
Axiom::registradores REGS; // Cria um objeto de registradores em forma de vetor
static volatile char PLATAFORMA='ATMEL ATMega328';
static volatile char SISVER='0.1.1';
static unsigned int valor;
static volatile char Linguagem='C\C++';
static volatile char verID='0.1.1';
LiquidCrystal lcd(9, 8, 5, 4, 3, 2);




void setup(){

  prepassembly(0);
  registradores();  // Seta alguns registradores
  portas();         // Configura as portas e os pinos usados pelo sistema.
  configurar();     // Configura o início do sistema.
  promptdecomando(); // Inicia o interpretador de comandos

}

void loop(){

  AxiomKernel.ledcomdelay(12,1000,1);
  AxiomKernel.ledcomdelay(12,1000,0);
  AxiomKernel.ledcomdelay(13,1000,1);
  AxiomKernel.ledcomdelay(13,1000,0);

}



void configurar(){



  AxiomKernel.ledcomdelay(13,600,1);
  desligarled(13);
  Serial.println("AxiomDetect versao 0.1.1 - Detectando Hardware...");
  Serial.println("");
  Serial.println("Iniciando o Axiom OS 8-Bit...");
  AxiomKernel.ledcomdelay(13,500,1);
  Serial.println("");
  Serial.println("Copyright (C) 2013-2014 Felipe Miguel Nery Lunkes");
  Serial.println("");
  AxiomKernel.ledcomdelay(13,1000,0);
  Serial.println("Inciando o Sistema..."); 
  Serial.println("");
  Serial.println("");
  Serial.println("Insira '4' para uma lista de comandos disponiveis...");
  Serial.println("");
  Serial.println("");
  Serial.println("Insira o comando desejado com a ajuda do Terminal...");
  Serial.println("");

}

void promptdecomando(){

  string=Serial.read();

  interpretar(string);

  promptdecomando();

}

void interpretar(char comando){

  if (comando == '1'){

    ligarled(13);
    Serial.println("---*---*---*---*---*---*---*---*---*---*---*---*---*---");
    Serial.println("");
    Serial.println("Axiom SO 8-Bit");
    Serial.println("");
    Serial.println("Copyright (C) 2013-2014 Felipe Miguel Nery Lunkes");
    Serial.println("Todos os direitos reservados.");
    Serial.println("");
    Serial.println("Projeto iniciado em 11/10/2013.");
    Serial.println("");
    Serial.println("Dados desta versao do Software:");
    Serial.println("- Versao do sistema: 0.1.1");
    Serial.println("- Revisao do sistema: 13A");
    Serial.println("- Compilacao do sistema: 013.2014.05.29.22.31.rA.Kernel");
    Serial.println("- Data e hora de lancamento desta versao: 29/02/2014 22:31 BRA");
    Serial.println("");
    Serial.println("Dados da Firmware:");
    Serial.println("- Revisao da Firmare instalada (BOOT): 12B");
    Serial.println("- Lancamento: 29/02/2014 00:06 BRA");
    Serial.println("");
    AxiomKernel.ledcomdelay(12,1000,1);
    AxiomKernel.ledcomdelay(13,500,1);
    AxiomKernel.ledcomdelay(13,500,0);
    AxiomKernel.ledcomdelay(12,1000,0);
    promptdecomando();
  }

  if (comando == '2'){


    ligarled(13);
    ligarled(12);
    promptdecomando();

  }

  if (comando == '3'){

    desligarled(12);
    desligarled(13);
    promptdecomando();

  }

  if (comando == '4'){

    AxiomKernel.espaco();
    Serial.println("Use os comandos a seguir no Terminal do Axiom OS:");
    AxiomKernel.espaco();
    Serial.println("1 - Exibe a versao do Software.");
    Serial.println("2 - Liga o Led de status do sistema.");
    Serial.println("3 - Desliga o Led de status do sistema.");
    Serial.println("4 - Exibe essa ajuda.");
    Serial.println("5 - Finaliza o sistema e desliga os componentes.");
    Serial.println("6 - Inicia a calculadora basica do Axiom OS.");
    AxiomKernel.espaco();
    promptdecomando();
  }

  if (comando == '5'){

    AxiomKernel.espaco();
 
    Serial.println("");
    Serial.println("Ok. Voce deseja desligar o sistema.");
    Serial.println("");
    Serial.println("");
    Serial.println("Ate a proxima!");
    AxiomKernel.ledcomdelay(12,1000,1);
    AxiomKernel.ledcomdelay(12,1000,0);
    AxiomKernel.ledcomdelay(13,500,1);
    AxiomKernel.ledcomdelay(13,600,0);
    AxiomKernel.ledcomdelay(13,1000,1);
    asm volatile ("nop\t");
    AxiomKernel.espaco();
    Serial.println("O sistema pode ser desligado com seguranca.");
    AxiomKernel.espaco();
    loopfinal();


  }

  if (comando == '6'){

    Serial.setTimeout(1500);
    Serial.println("");
    
    Serial.println("Por favor, insira o primeiro numero."); 
  
    numero1=Serial.parseInt();
   

    Serial.println("Agora, insira o segundo numero.");
   
    numero2=Serial.parseInt();
  
    Serial.println("");
    total=numero1+numero2;
    Serial.print("Soma: ");
    Serial.print(total);
    Serial.println("");
    Serial.print("Subtracao do primeiro pelo segundo: ");
    total=numero1-numero2;
    Serial.print(total);
    Serial.println("");
    Serial.print("Subtracao do segundo pelo primeiro: ");
    total=numero2-numero1;
    Serial.print(total);
    Serial.println("");
    Serial.print("Multiplicacao: ");
    total=numero1*numero2;
    Serial.print(total);
    Serial.println("");

    if (numero1 == 0 | numero2 == 0){
    
      Serial.println("Impossivel realizar divisao por zero.");
      Serial.println(""); 
promptdecomando();
    } 
    else {

      if (numero1 > numero2){

        total=numero1/numero2;

      } 
      else {

        total=numero2/numero1;

      }

      Serial.print("Divisao: ");

      Serial.print(total);
      Serial.println(""); 


    }

promptdecomando();

  }



}



void ligarled(int ledaligar){

  digitalWrite(ledaligar, HIGH);

}

void desligarled(int ledadesligar){

  digitalWrite(ledadesligar, LOW);

}

void loopfinal(){

  int loopeterno=0;

  AxiomKernel.espaco();
  Serial.println("Voce ja pode desligar o sistema.");
  AxiomKernel.espaco();

  while (loopeterno == 0){

    AxiomKernel.ledcomdelay(13,1000,1);
    AxiomKernel.ledcomdelay(12,1000,0);
    AxiomKernel.ledcomdelay(13,1000,0);
    AxiomKernel.ledcomdelay(12,1000,1);
    AxiomKernel.ledcomdelay(13,1000,1);
    AxiomKernel.ledcomdelay(12,1000,0);
    AxiomKernel.ledcomdelay(13,1000,0);
    AxiomKernel.ledcomdelay(12,1000,1);

  }

  for (;;);
  AxiomKernel.nadaAFazer();

}

// Inicio da Interface Gráfica


/*

 void iniciar_interface(){
 
 lcd.begin(16, 2); 
 
 lcd.clear();                 //limpa o display do LCD.     
 lcd.print("Iniciando... ");         //imprime a string no display do LCD.
 delay(2000);                 
 
 lcd.setCursor(0,1);          //posiciona o cursor na coluna 0 linha 1 do LCD.
 lcd.print("Axiom SO");    //imprime a string no display do LCD.
 delay(2000);    
 
 lcd.clear();
 lcd.print("Iniciando");
 lcd.setCursor(0,1);
 lcd.print("Sistema...");
 delay(4000); 
 
 lcd.clear();
 lcd.print("");
 delay(1000);
 
 //Rolando o display para a esquerda 12 vezes
 for (int i = 0; i < 12; i++) {
 lcd.scrollDisplayLeft();
 delay(600);
 }
 
 delay(1000);
 
 }
 
 */
 


void portas(){

  AxiomKernel.iniciarSerial(9600);
  AxiomKernel.definirPino(12,0);
  AxiomKernel.definirPino(13,0);


}

void registradores(){

  REGS.r[1]=1;
  REGS.proposito[1]='BASE';
  REGS.r[2]=1;
  REGS.proposito[2]='INDEX';
  asm volatile ("mov 1, r1\t");
  asm volatile ("mov 10, r2\n\t");

}

void prepassembly(int stc){

  if ( stc == 0) {


    asm volatile ("clc"::);

  } 
  if ( stc == 1 ) {



  }

}




