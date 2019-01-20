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
  int segs[7];
  switch(digit){
    case 0:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 4;
      segs[3] = 5;
      segs[4] = 6;
      segs[5] = 7;
      segs[6] = 0;
      break;
    case 1:
      segs[0] = 3;
      segs[1] = 4;
      segs[2] = 0;
      segs[3] = 0;
      segs[4] = 0;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 2:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 5;
      segs[3] = 7;
      segs[4] = 8;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 3:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 4;
      segs[3] = 5;
      segs[4] = 8;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 4: 
      segs[0] = 3;
      segs[1] = 4;
      segs[2] = 8;
      segs[3] = 6;
      segs[4] = 0;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 5:
      segs[0] = 2;
      segs[1] = 4;
      segs[2] = 5;
      segs[3] = 6;
      segs[4] = 8;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 6:
      segs[0] = 2;
      segs[1] = 4;
      segs[2] = 5;
      segs[3] = 6;
      segs[4] = 7;
      segs[5] = 8;
      segs[6] = 0;
      break;
    case 7:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 4;
      segs[3] = 0;
      segs[4] = 0;
      segs[5] = 0;
      segs[6] = 0;
      break;
    case 8:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 4;
      segs[3] = 5;
      segs[4] = 6;
      segs[5] = 7;
      segs[6] = 8;
      break;
    case 9:
      segs[0] = 2;
      segs[1] = 3;
      segs[2] = 4;
      segs[3] = 5;
      segs[4] = 6;
      segs[5] = 8;
      segs[6] = 0;
      break;
    default:
      segs[0] = 0;
      segs[1] = 0;
      segs[2] = 0;
      segs[3] = 0;
      segs[4] = 0;
      segs[5] = 0;
      segs[6] = 0;
      break;
  }
  
  clear();
  
  for(int i = 0; i < 7; i++){
    if(segs[i] == 0) { continue; }
    else { digitalWrite(segs[i], HIGH); }
  }
}

void clear(){
  for(int i = 0; i < 9; i++){
    digitalWrite(i, LOW);
  }
}
