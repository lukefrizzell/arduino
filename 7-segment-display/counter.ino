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
  
  for(int i=0;i<10;i++)
  {
    setDigit(i);
    delay(1000);
  }
}

void setDigit(int digit)
{
  uint8_t segs;

  switch(digit){
    case 0:
      segs = 0x3F;
      break;
    case 1:
      segs = 0x06;
      break;
    case 2:
      segs = 0x6B;
      break;
    case 3:
      segs = 0x4F;
      break;
    case 4: 
      segs = 0x56;
      break;
    case 5:
      segs = 0x5D;
      break;
    case 6:
      segs = 0x7D;
      break;
    case 7:
      segs = 0x07;
      break;
    case 8:
      segs = 0x7F;
      break;
    case 9:
      segs = 0x5F;
      break;
    default:
      segs = 0x00;
      break;
  }
  
  clear();
  
  for(int i = 0; i < 7; i++){
    if((segs >> i) & 0x01) { 
      digitalWrite(i+2, HIGH); 
      }
  }
}

void clear(){
  for(int i = 0; i < 9; i++){
    digitalWrite(i, LOW);
  }
}
