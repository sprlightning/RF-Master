
#ifndef _TCSwitch_h
#define _TCSwitch_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad, FraunchPad and StellarPad specific
    #include "Energia.h"
#elif defined(RPI) // Raspberry Pi
    #define RaspberryPi

    // Include libraries for RPi:
    #include <string.h> /* memcpy */
    #include <stdlib.h> /* abs */
    #include <wiringPi.h>
#elif defined(SPARK)
    #include "application.h"
#else
    #include "WProgram.h"
#endif

#include <stdint.h>


#if defined( __AVR_ATtinyX5__ ) or defined ( __AVR_ATtinyX4__ )
#define TCSwitchDisableReceiving
#endif


#define TCSwitch_MAX_CHANGES 67

class TCSwitch {

  public:
    TCSwitch();
    
    void switchOn(int nGroupNumber, int nSwitchNumber);
    void switchOff(int nGroupNumber, int nSwitchNumber);
    void switchOn(const char* sGroup, int nSwitchNumber);
    void switchOff(const char* sGroup, int nSwitchNumber);
    void switchOn(char sFamily, int nGroup, int nDevice);
    void switchOff(char sFamily, int nGroup, int nDevice);
    void switchOn(const char* sGroup, const char* sDevice);
    void switchOff(const char* sGroup, const char* sDevice);
    void switchOn(char sGroup, int nDevice);
    void switchOff(char sGroup, int nDevice);

    void sendTriState(const char* sCodeWord);
    void send(unsigned long code, unsigned int lengt);
    void send(const char* sCodeWord);
    
    #if not defined( TCSwitchDisableReceiving )
    void enableReceive(int interrupt);
    void enableReceive();
    void disableReceive();
    bool available();
    void resetAvailable();

    unsigned long getReceivedValue();
    unsigned int getReceivedBitlength();
    unsigned int getReceivedDelay();
    unsigned int getReceivedProtocol();
    unsigned int* getReceivedRawdata();
    #endif
  
    void enableTransmit(int nTransmitterPin);
    void disableTransmit();
    void setPulseLength(int nPulseLength);
    void setRepeatTransmit(int nRepeatTransmit);
    #if not defined( TCSwitchDisableReceiving )
    void setReceiveTolerance(int nPercent);
    #endif


    struct HighLow {
        uint8_t high;
        uint8_t low;
    };

    struct Protocol {
        /** base pulse length in microseconds, e.g. 350 */
        uint16_t pulseLength;

        HighLow syncFactor;
        HighLow zero;
        HighLow one;


        bool invertedSignal;
    };

    void setProtocol(Protocol protocol);
    void setProtocol(int nProtocol);
    void setProtocol(int nProtocol, int nPulseLength);

  private:
    char* getCodeWordA(const char* sGroup, const char* sDevice, bool bStatus);
    char* getCodeWordB(int nGroupNumber, int nSwitchNumber, bool bStatus);
    char* getCodeWordC(char sFamily, int nGroup, int nDevice, bool bStatus);
    char* getCodeWordD(char group, int nDevice, bool bStatus);
    void transmit(HighLow pulses);

    #if not defined( TCSwitchDisableReceiving )
    static void handleInterrupt();
    static bool receiveProtocol(const int p, unsigned int changeCount);
    int nReceiverInterrupt;
    #endif
    int nTransmitterPin;
    int nRepeatTransmit;
    
    Protocol protocol;

    #if not defined( TCSwitchDisableReceiving )
    static int nReceiveTolerance;
    volatile static unsigned long nReceivedValue;
    volatile static unsigned int nReceivedBitlength;
    volatile static unsigned int nReceivedDelay;
    volatile static unsigned int nReceivedProtocol;
    const static unsigned int nSeparationLimit;

    static unsigned int timings[TCSwitch_MAX_CHANGES];
    #endif

    
};

#endif
