# LightMonster
A spark Core project for controlling remote RF outlets such as those sold by Home Depot during the Holiday Season.

Library Usage:

Add library to your code #include "rf_outlet_control.h"

Add an instance of the Remote class, then call .sendSignal. sendSignal asks for a char (A-F) to tell it what channel to send
and a boolean to tell it to send either an On code or an Off code.

Example: remote.sendSignal('B', true) woul;d send an On code to Channel B.  (Cureently the Library has channels B-F should have A soon.)

The codes are comprissed of short or long HIGH pulses, followed by the opposite in a LOW pulse 
(ie Short HIGH long LOW, Long HIGH, short LOW, etc...) and generally consist of a preamble, a section indicating Off, or 
On, and finally a section indicating which channel.

I've also exposed the sendShort and sendLong methods to allow for any future channels or versions not accounted for. To use 
simply call .sendShort or sendLong and give them a boolean indicating if it's the end of the transmittion or not.

  
