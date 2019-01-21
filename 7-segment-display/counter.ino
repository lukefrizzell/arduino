void setup()
{
  // define pin modes
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 
}

void loop() 
{
  // loop to turn leds od seven seg ON
  
  for(int i=0;i<=16;i++)
  {
    setDigit(i);
    delay(1000);
  }
}

void setDigit(int digit)
{

  if (digit < 0 || digit > 15){
    clear();
    return;
  }

  uint8_t segs[] = {0x3F, 0x06, 0x6B, 0x4F, 0x56, 0x5D, 0x7D, 0x07, 0x7F, 0x5F, 0x77, 0x7C, 0x39, 0x6E, 0x79, 0x71};
  
  clear();
  
  for(int i = 0; i < 7; i++){
    if((segs[digit] >> i) & 0x01) { 
      digitalWrite(i+2, HIGH); 
    }
  }
}

void clear(){
  for(int i = 0; i < 9; i++){
    digitalWrite(i, LOW);
  }
}
