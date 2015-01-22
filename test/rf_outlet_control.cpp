/*This library is designed to control the remote RF Outlets sold in places like
Home Depot around the holidays. Currently covers Channels A-F. Base pulse
methods exposed in case others are needed.

Created by Jason S. (screamingcities) 2015

V1.0
 */

#include "application.h"
#include "rf_outlet_control.h"

Remote::Remote(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;

}

void Remote::sendShort(boolean final){

  digitalWrite(_pin, HIGH);
  delayMicroseconds(TIME_SHORT);
  digitalWrite(_pin, LOW);

  if(!final){
    delayMicroseconds(SHORT_BREAK);
  }
}

void Remote::sendLong(boolean final){
  digitalWrite(_pin, HIGH);
  delayMicroseconds(TIME_LONG);
  digitalWrite(_pin, LOW);

  if(!final){
  delayMicroseconds(LONG_BREAK);
  }
}

//All of the remotes seem to have the same pre-amble.
void Remote::sendPreamble(){
sendShort(false);
//long
sendLong(false);
//long
sendLong(false);
//short
sendShort(false);
//Long
sendLong(false);
//Short
sendShort(false);
//Short
sendShort(false);
//Short
sendShort(false);
//Short
sendShort(false);
//Short
sendShort(false);
}

void Remote::sendOnOffSignal(boolean _state){
    if(_state){
        //Long
        sendLong(false);
        //Short
        sendShort(false);
    }else{
        //short
        sendShort(false);
        //Long
        sendLong(false);
    }

}

void Remote::sendID(char _code){
  if(_code == 'A'){

  }
  if(_code == 'B'){
      //Short
      sendShort(false);
      //Long
      sendLong(false);
      //Short
      sendShort(false);
      //ShortEnd
      sendShort(true);

  }
  if(_code == 'C'){
      //Short
      sendShort(false);
      //Short
      sendShort(false);
      //Long
      sendLong(false);
      //Short
      sendShort(true);
  }
  if(_code == 'D'){
      //Short
      sendShort(false);
      //Short
      sendShort(false);
      //Short
      sendShort(false);
      //Long
      sendLong(true);
  }
  if(_code == 'E'){
      //Long
      sendLong(false);
      //Long
      sendLong(false);
      //Short
      sendShort(false);
      //Short
      sendShort(true);
  }
  if(_code == 'F'){
       //Short
      sendShort(false);
      //Short
      sendShort(false);
      //Short
      sendShort(false);
       //Short
      sendShort(true);
  }
}

void Remote::sendSignal(char code, boolean state){

  //Send the code 16 times
  for(int i=0; i<16; i++){
  //Preamble
  sendPreamble();
  //ON/OFF
  sendOnOffSignal(state);
  //IDKey
  sendID(code);
  //Delay
  delayMicroseconds(TIME_DELAY);

  }

}
