
const int sensorPino = 2;     // Pino de entrada do sensor magnético

#include <Wire.h> //Biblioteca para uso do protocolo I2C;
#include <Adafruit_GFX.h> //Biblioteca para manipulação gráfica no display;
#include <Adafruit_SH1106.h> //Biblioteca para operação do driver de controle do display;

#include <Fonts/FreeMono9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeSansBoldOblique9pt7b.h> //Fonte para alteração do texto;
#include <Fonts/FreeMonoOblique9pt7b.h> //Fonte para alteração do texto;

#define OLED_RESET -1 //Em displays que não possuem pino RESET, é dado o valor -1;


Adafruit_SH1106 display(OLED_RESET); //Declaração da tela com o nome "display";

void setup() {

  pinMode(sensorPino, INPUT);  // Configura o pino do sensor como entrada
  Serial.begin(9600);
  display.begin(SH1106_SWITCHCAPVCC, 0x3C); //Inicialização do display com a biblioteca e endereço de hardware do display;
  

}

void loop() {

  display.clearDisplay(); //Comando para limpar a tela;
  display.setFont(&FreeMonoOblique9pt7b); //Comando para definir a fonte que será utilizada;
  display.setTextColor(WHITE); //Comando para definir a cor do texto;
  display.setTextSize(1); //Comando para definir tamanho od

  display.setCursor(-2, 16); //Definição de onde o texto será escrito. Lembre se que: linha, coluna;
  

 // int valorSensor = analogRead(pinoSensor);
  {
  int estadoSensor = digitalRead(sensorPino);  // Lê o estado do sensor

  if (estadoSensor == LOW) {  // Se o sensor detecta campo magnético
    
    
  } else {
    display.print("Campo magnéticodete ctado!"); 
  }

  delay(100);  // Aguarda um pouco antes de ler novamente
}

  display.display(); //informações na tela;
}
