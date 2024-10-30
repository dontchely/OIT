const int bt_out1 =  1; 
const int bt_out2 =  2; 
const int bt_out3 =  3; 
const int bt_out4 =  4; 

const int pinoLed_1 =  10; 
const int pinoLed_2 =  11;
const int pinoLed_3 =  12; 
const int pinoLed_4 =  13; 

void setup(){

  pinMode(pinoLed_1, OUTPUT); 
  pinMode(pinoLed_2, OUTPUT); 
  pinMode(pinoLed_4, OUTPUT); 
  pinMode(pinoLed_4, OUTPUT); 

  pinMode(bt_out1, INPUT); 
  pinMode(bt_out2, INPUT); 
  pinMode(bt_out3, INPUT); 
  pinMode(bt_out4, INPUT); 

}

void loop(){
  
  if(digitalRead(bt_out1) == HIGH){ 
      digitalWrite(pinoLed_1, HIGH);
  }else{ 
      digitalWrite(pinoLed_1, LOW); 
  }
  if(digitalRead(bt_out2) == HIGH){ 
      digitalWrite(pinoLed_2, HIGH); 
  }else{ 
      digitalWrite(pinoLed_2, LOW); 
  }
  if(digitalRead(bt_out3) == HIGH){ 
      digitalWrite(pinoLed_3, HIGH); 
  }else{ 
      digitalWrite(pinoLed_3, LOW); 
  }
  if(digitalRead(bt_out4) == HIGH){ 
      digitalWrite(pinoLed_4, HIGH); 
  }else{ 
      digitalWrite(pinoLed_4, LOW); 
  }
}
