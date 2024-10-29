// C++ code
//
#define R_verme 6     // vermelho LED
#define G_vde 3      //verde LED
#define B_azl 5     //azul LED
#define LDR A0     //(LDR)

// Valor_inicial do LRD
int ldrValor = 0;

void setup() {
  Serial.begin(9600);        
  pinMode(R_verme, OUTPUT);        
  pinMode(G_vde, OUTPUT);        
  pinMode(B_azl, OUTPUT);        
  pinMode(LDR, INPUT);       
}

// Essa função acende o LED RGB na cor indicada

void acenderCor(int vermelho, int verde, int azul, const char* nomeCor) {
  
  Serial.print("Cor atual: ");
  
  Serial.println(nomeCor);  
  
  analogWrite(R_verme, vermelho);   
  analogWrite(G_vde, verde);      // Define a intensidade de cada faixa de cor
  analogWrite(B_azl, azul);
         
}

void loop() {
  
  ldrValor = analogRead(LDR); // leituro do sensor (LDR)
  
  Serial.print("Valor do LDR: ");
  Serial.println(ldrValor);   // Exibe o valor do LDR no monitor serial

  // Define cores com base no valor do LDR
  
  if (ldrValor < 100) {
    acenderCor(0, 0, 0, "Desligado");       // Apaga o LED
  } else if (ldrValor < 200) {
    acenderCor(255, 0, 0, "Vermelho");      // Vermelho
  } else if (ldrValor < 300) {
    acenderCor(0, 255, 0, "Verde");         // Verde
  } else if (ldrValor < 400) {
    acenderCor(0, 0, 255, "Azul");          // Azul
  } else if (ldrValor < 500) {
    acenderCor(255, 255, 0, "Amarelo");     // Amarelo
  } else if (ldrValor < 600) {
    acenderCor(0, 255, 255, "Ciano");       // Ciano
  } else {
    acenderCor(255, 0, 255, "Magenta");     // Magenta
  }
  
  delay(2000); // Para 2 segundo e faz nova leitura
}