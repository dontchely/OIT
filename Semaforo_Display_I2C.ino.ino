#include <Wire.h>
#include <LiquidCrystal_I2C.h> 

int R_verm = 7;   //LED vermelho
int G_vde = 5;   //LED verde
int B_amar = 6; //LED amarelo

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inicialização do display LCD 

 // essa função acende o LED e retornar a cor como texto.

String mudaCorLED(bool vermelho = false, bool verde = false, bool amarelo = false) {
  
    // Primeiro, apaga todos os LEDs
    digitalWrite(R_verm, LOW);
    digitalWrite(G_vde, LOW);
    digitalWrite(B_amar, LOW);

    // Depois, acende o LED da cor selecionada
    if (vermelho) {
      
        digitalWrite(R_verm, HIGH);
        return "Vermelho";
    } else if (verde) {
      
        digitalWrite(G_vde, HIGH);
        return "Verde";
    } else if (amarelo) {
      
        digitalWrite(B_amar, HIGH);
        return "Amarelo";
    }
    return "";
}

void setup() {
  
    // pinos em forma de saida
    
    pinMode(R_verm, OUTPUT);
    pinMode(G_vde, OUTPUT);
    pinMode(B_amar, OUTPUT);
    lcd.init();         // inicializando LCD
    lcd.backlight();    // luz de fundo do LCD
}

void loop() {
  
    String corAtual;

    // Verdadeiro, Falso, falso =  vermelho. 
    corAtual = mudaCorLED(true, false, false);
    lcd.clear();
    lcd.setCursor(0, 0); // Move o cursor para o início
    lcd.print("Cor: ");
    lcd.print(corAtual); // Exibe "Cor: Vermelho"
    delay(2000);         

    //Falso, Verdadeiro, Falso =  verde.
    corAtual = mudaCorLED(false, true, false);
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print("Cor: ");
    lcd.print(corAtual); // Exibe "Cor: Verde"
    delay(3000);         

     // Falso, Falso, Verdadeiro =  Amarelo.
    corAtual = mudaCorLED(false, false, true);
    lcd.clear();  
    lcd.setCursor(0, 0);
    lcd.print("Cor: ");
    lcd.print(corAtual); // Exibe "Cor: Amarelo"
    delay(1000);         
}
