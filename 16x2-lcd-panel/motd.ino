const int rs = 12, en = 10, rw=11;
const int data_pins[] = {9, 8, 7, 6, 5, 4, 3, 2};
const int bit_mode = 8; //4 or 8 (4 not yet implemented)

void setup() {
    pinMode(rs, INPUT);
    pinMode(rw, INPUT);
    pinMode(en, INPUT);

    delay(500);
    
    sendInstruction(0x01); //clear display
    sendInstruction(0x02); //return home
    sendInstruction(0x05); //entry mode set
    sendInstruction(0x0F); //display on
    sendInstruction(0x1C); //cursor shift
    sendInstruction(0x38); //function set

    sendData(0x55); //send 'U'
}

void loop() {
  
}

void sendInstruction(uint8_t input){
  sendInput(input, 0);
}

void sendData(uint8_t input){
  sendInput(input, 1);
}

void sendInput(uint8_t input, uint8_t mode){
    setDataPinModes(0);

    digitalWrite(rs, mode & 0x01);
    //digitalWrite(rw, (input >> 8) & 0x01);

    for(int i = 0; i < bit_mode; i++){
      digitalWrite(data_pins[i], (input >> i) & 0x01);
    }

    digitalWrite(en, LOW);
    delayMicroseconds(1);  
    digitalWrite(en, HIGH);
    delayMicroseconds(1);  
    digitalWrite(en, LOW);
    delayMicroseconds(1000); 
}

void setDataPinModes(int read){
    if(read == 1){
        for(int i = 0; i < bit_mode; i++){
            pinMode(data_pins[i], INPUT);
        }
    } else{
        for(int i = 0; i < bit_mode; i++){
            pinMode(data_pins[i], OUTPUT);
        }
    }
}