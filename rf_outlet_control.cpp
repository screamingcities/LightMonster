/*This library is designed to control the remote RF Outlets sold in places like
Home Depot around the holidays.

To use -

Screamingcities 2015
Version 1.0
 */

#if defined (SPARK)
  #include "application.h"
#else
  #if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
  #else
    #include "WProgram.h"
  #endif

#endif
