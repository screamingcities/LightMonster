int TIME_SHORT = 564;
int SHORT_BREAK = 1798;
int TIME_LONG = 1798;
int LONG_BREAK  = 564;
int TIME_DELAY = 10592;

int sendPin = D1;

void setup() {

    Serial.begin(9600);
    pinMode(sendPin, OUTPUT);
    digitalWrite(sendPin, LOW);

    Spark.function("LightMonster", lightMonster);

}

void loop() {

}


void sendShort(){
    digitalWrite(sendPin, HIGH);
    delayMicroseconds(TIME_SHORT);
    digitalWrite(sendPin, LOW);
    delayMicroseconds(SHORT_BREAK);
}

void sendLong(){
    digitalWrite(sendPin, HIGH);
    delayMicroseconds(TIME_LONG);
    digitalWrite(sendPin, LOW);
    delayMicroseconds(LONG_BREAK);
}

void sendShortFinal(){
    digitalWrite(sendPin, HIGH);
    delayMicroseconds(TIME_SHORT);
    digitalWrite(sendPin, LOW);
}

void sendLongFinal(){
    digitalWrite(sendPin, HIGH);
    delayMicroseconds(TIME_LONG);
    digitalWrite(sendPin, LOW);
}

void sendPreamble(){
     //short
    sendShort();
    //long
    sendLong();
    //long
    sendLong();
    //short
    sendShort();
    //Long
    sendLong();
    //Short
    sendShort();
    //Short
    sendShort();
    //Short
    sendShort();
    //Short
    sendShort();
    //Short
    sendShort();
}


void sendOnOffSignal(boolean on){
    if(on){
        //Long
        sendLong();
        //Short
        sendShort();
    }else{
        //short
        sendShort();
        //Long
        sendLong();
    }

}

void sendIDKey(char code){


        if(code == 'A'){

        }
        if(code == 'B'){
            //Short
            sendShort();
            //Long
            sendLong();
            //Short
            sendShort();
            //ShortEnd
            sendShortFinal();

        }
        if(code == 'C'){
            //Short
            sendShort();
            //Short
            sendShort();
            //Long
            sendLong();
            //Short
            sendShortFinal();
        }
        if(code == 'D'){
            //Short
            sendShort();
            //Short
            sendShort();
            //Short
            sendShort();
            //Long
            sendLongFinal();
        }
        if(code == 'E'){
            //Long
            sendLong();
            //Long
            sendLong();
            //Short
            sendShort();
            //Short
            sendShortFinal();
        }

        if(code == 'F'){
             //Short
            sendShort();
            //Short
            sendShort();
            //Short
            sendShort();
             //Short
            sendShortFinal();

        }


}


//Final code for Remote Controls.


int lightMonster(String args){
    int type;
    char id;
    boolean state = false;
    type = args.charAt(0)-'0';
    id = args.charAt(1);

    if(args.substring(2).equals("ON")){
        state = true;
    }


    for(int i=0; i<16; i++){
         //Preamble
    sendPreamble();
    //ON/OFF
    sendOnOffSignal(state);
    //IDKey
    sendIDKey(id);
    //Delay
    delayMicroseconds(TIME_DELAY);

    }

    return type;
}
