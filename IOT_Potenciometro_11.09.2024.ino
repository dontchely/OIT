
int pinoX = A0;
int pinoY = A1;

void setup() {
  Serial.begin(9600);        
  pinMode(pinoX, INPUT);     
  pinMode(pinoY, INPUT);     
}

void loop() {
  int valorX = analogRead(pinoX);   
  int valorY = analogRead(pinoY);   
  
  Serial.print("Eixo X: ");
  Serial.println(valorX);           
  Serial.print("Eixo Y: ");
  Serial.println(valorY);           
  Serial.println("----------------------");

  delay(500);                    
