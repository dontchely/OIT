
const int touchPin = 2;    
const int ledPin = 13;     

void setup() {
  
  Serial.begin(9600);
  
  
  pinMode(touchPin, INPUT);
  
  // Configura o pino do LED como saída
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  int touchState = digitalRead(touchPin);
  
  // Verifica se o sensor detectou um toque
  if (touchState == HIGH) {
    
    digitalWrite(ledPin, HIGH);  // Liga o LED
  } else {
    
    digitalWrite(ledPin, LOW);   // Desliga o LED
  }

  // Atraso para não sobrecarregar o monitor serial
  delay(1000);
}