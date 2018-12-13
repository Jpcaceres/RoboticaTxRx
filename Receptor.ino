#include <VirtualWire.h>
 
const int dataPin = 9;
const int servo1 = 6;
const int servo2 = 5;
const int servo3 = 3;
const int ledPin = LED_BUILTIN;
;
 
void setup()
{
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();
    pinMode(servo1, OUTPUT);
    pinMode(servo2, OUTPUT);
    pinMode(servo3, OUTPUT);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, true);
    delay(300);
    digitalWrite(ledPin, false);
}
 
void loop()
{
    uint8_t data;
    uint8_t dataLength=1;
 
    if (vw_get_message(&data,&dataLength))
    {
        if((char)data=='w')
        {
            while((char)data=='w')
            {
                digitalWrite(ledPin, true);
                analogWrite(servo1, 255);
                analogWrite(servo2, 0);
                analogWrite(servo3, 0);
            }
        }
        else if((char)data=='a')
        {
            digitalWrite(ledPin, false);
            analogWrite(servo1, 255);
            analogWrite(servo2, 0);
            analogWrite(servo3, 0);
        }
        else if((char)data=='d')
        {
            digitalWrite(ledPin, false);
            analogWrite(servo1, 255);
            analogWrite(servo2, 0);
            analogWrite(servo3, 0);
        }
        else if ((char)data=='s')
        {
            digitalWrite(lenPin, false);  
            analogWrite(servo1, 255);
            analogWrite(servo2, 0);
            analogWrite(servo3, 0);
        }              
    }
}
