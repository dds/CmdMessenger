
#ifndef Messenger_h
#define Messenger_h
#define MESSENGERBUFFERSIZE 64

#include <inttypes.h>
#include "WProgram.h"

extern "C" {
// callback function
    typedef void (*messengerCallbackFunction)(void);
}

class CmdMessengerBase
{

public:
  int readInt();
  char readChar();
  void copyString(char *string, uint8_t size);
  uint8_t checkString(char *string);
  uint8_t available();
  
protected:
  uint8_t next();
  
  uint8_t messageState;
  
  char* current; // Pointer to current data
  char* last;
  
  char token[2];
  uint8_t dumped;
  
  uint8_t bufferIndex; // Index where to write the data
  char buffer[MESSENGERBUFFERSIZE]; // Buffer that holds the data
  uint8_t bufferLength; // The length of the buffer (defaults to 64)
  uint8_t bufferLastIndex; // The last index of the buffer
};


#endif

