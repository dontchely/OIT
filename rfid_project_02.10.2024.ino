
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>

 
#define SS_PIN 10
#define RST_PIN 9
#define LED_G 4 //define green LED pin
#define LED_R 5 //define red LED


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup() 
{
  Serial.begin(9600);
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  
  pinMode(LED_G, OUTPUT);
  pinMode(LED_R, OUTPUT);
 

}
void loop() 
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  content.toUpperCase();
  if (content.substring(1) == "70 36 13 A4" ) //change here the UID of the card/cards that you want to give access
  {
    digitalWrite(LED_G, HIGH);
    Serial.println("Authorized access");
    Serial.println();
    delay(3000);
    digitalWrite(LED_G, LOW);
   
    
  }
 
 else   {
 
    digitalWrite(LED_R, HIGH);
    Serial.println(" Access denied");
    delay(3000);
    digitalWrite(LED_R, LOW);
    
   
  }
} 

