
#include "rf_outlet_control.h"

#define outPin = D1;
Remote remote(outPin);

void setup() {

    Spark.function("LightMonster", lightMonster);

}

void loop() {

}

//Send the signal to the lights.
int lightMonster(String args){
    int type;
    char id;
    boolean state = false;
    type = args.charAt(0)-'0';
    id = args.charAt(1);

    if(args.substring(2).equals("ON")){
        state = true;
    }

    remote.sendSignal(id, state);


    return type;
}
