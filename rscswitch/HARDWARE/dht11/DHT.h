//#if ARDUINO >= 100
// #include "Arduino.h"
//#else
// #include "WProgram.h"
//#endif

/* DHT library 

MIT license
written by Adafruit Industries
*/
#include "stm32f10x.h"
#include "sys.h"
#include "stdio.h"
// how many timing transitions we need to keep track of. 2 * number bits + extra
#define MAXTIMINGS 85

#define DHT11 11
#define DHT22 22
#define DHT21 21
#define AM2301 21

void DHT (void)
	{

  uint8_t data[6];
  uint8_t _pin, _type;
  boolean read(void);
  unsigned long _lastreadtime;
  boolean firstreading;

};
