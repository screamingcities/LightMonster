/*This library is designed to control the remote RF Outlets sold in places like
Home Depot around the holidays. Currently covers Channels A-F. Base pulse
methods exposed in case others are needed. The control is done with inexpensive
transmitters (315mhz) like the FS1000A.

Created by Jason S. (screamingcities) 2015

V1.0
*/

#ifndef rf_outlet_control_h
#define rf_outlet_control_h

#include "application.h"

class Remote
{
  public:
    Remote(int pin);
    void sendSignal(char code, boolean state);
    void sendShort(boolean final);
    void sendLong(boolean final);

  private:
    int TIME_SHORT = 564;
    int SHORT_BREAK = 1798;
    int TIME_LONG = 1798;
    int LONG_BREAK  = 564;
    int TIME_DELAY = 10592;
    int _pin;
    void sendPreamble();
    void sendOnOffSignal(boolean _state);
    void sendID(char _code);
};

#endif
