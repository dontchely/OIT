 #include<LiquidCrystal_I2C.h>
int temp = A0;
LiquidCrystal_I2C lcd(0x3F,16,2);
 void setup(){

  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

 }
void loop(){
temp = analogRead(temp);
  float tempCelcius = (temp / 1023.0) * 500.0;
  //float tempC = analogRead(temp);
  Serial.println(temp);
  lcd.setCursor(2,0);
  lcd.print("temperatura");

  lcd.setCursor(2,1);
  lcd.print(tempCelcius);
}




// int temp = A0;
// float grausC;
  
// LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// void setup()
// {
//  lcd.begin(16, 2);
// }

// void loop()
// {
//   temp = analogRead(temp);
//   float tempCelcius  = (temp / 1023.0) * 500.0;
//   lcd.setCursor(2,0);          
//  lcd.print("temperatura");
//  lcd.setCursor(4,1);          
//   lcd.print("PREGADO HOJE!");