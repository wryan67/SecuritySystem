/**********************************************************
 *   mcp23x17 extension library for wiringPi              *
 *                                                        *
 *   Example usage program                                *
 *                                                        *
 *   Please follow the directions to make and install     *
 *   the libaray before compliling this program.          *
 *                                                        *
 *   $ make                                               *
 *   $ ./example                                          *
 *                                                        *
 *                                                        *
 **********************************************************/
#include <mcp23x17rpi.h>
#include <sys/time.h>
#include <limits.h>
#include <unistd.h>
#include <neopixel.h>

int txs0108_pin = 22;         // wiringpi pin number

int mcp23x17_handle   = -1;
int mcp23x17_address  = 0x20;
int mcp23x17_inta_pin = 0;    // wiringpi pin number
int mcp23x17_intb_pin = 7;    // wiringpi pin number


MCP23x17_GPIO zone1aPin = mcp23x17_getGPIO(mcp23x17_address, MCP23x17_PORTA, 0);
MCP23x17_GPIO zone1bPin = mcp23x17_getGPIO(mcp23x17_address, MCP23x17_PORTB, 0);

int zone1Pixel=0;

int Green=0;
int Yellow=42;
int Red=85;
int Magenta=128;
int Blue=170;
int Cyan=212;

bool ledStatus = false;


#define STRIP_TYPE              WS2811_STRIP_RGB
#define TARGET_FREQ             WS2811_TARGET_FREQ
#define GPIO_PIN                18   // BCM numbering system
#define DMA                     10   // DMA=Direct Memory Access
int led_count =                 12; 
int brightness =                64;

unsigned long long currentTimeMillis() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    return (unsigned long long)(currentTime.tv_sec) * 1000 +
        (unsigned long long)(currentTime.tv_usec) / 1000;
}

int getColor(int v1, int v2) {
    
    return (v1 && v2)?Green:Red; 
}

void eventMethod(MCP23x17_GPIO gpio, int v1) {

    MCP23x17_PORT port=mcp23x17_getPort(gpio);
    MCP23x17_PIN  pin=mcp23x17_getPin(gpio);

    printf("event pin<%c%d> value=%d\n", 97+port, pin, v1); 

    int v2=mcp23x17_virtualRead(mcp23x17_getGPIO(mcp23x17_address,1-port,pin));

    // set LED to match event
    neopixel_setPixel(0,neopixel_wheel(getColor(v1,v2)));  
    neopixel_render();
}




int setup() {

    if (wiringPiSetup() != 0) {
        fprintf(stderr, "Wiring Pi could not be initialized\n");
        return 9;
    }

    fprintf(stderr, "enable txs0108\n");
    pinMode(txs0108_pin, OUTPUT);
    digitalWrite(txs0108_pin, 1);    


    mcp23x17_setDebug(false);
    mcp23x17_handle = mcp23x17_setup(0, mcp23x17_address, mcp23x17_inta_pin, mcp23x17_intb_pin);

    if (mcp23x17_handle < 0) {
        fprintf(stderr, "mcp23017 could not be initialized\n");
        return 9;
    }

    if (mcp23x17_getDebug()) {
        fprintf(stderr, "mcp23x17_handle=%d\n\n", mcp23x17_handle);  
    }

    int ret=neopixel_init(STRIP_TYPE, WS2811_TARGET_FREQ, DMA, GPIO_PIN, led_count);

    if (ret!=0) {
        fprintf(stderr, "neopixel initialization failed: %s\n", neopixel_error(ret));
        return 9;
    }

    neopixel_setBrightness(brightness);   // valid values are 0 to 255


    return 0;
}

int main(int argc, char** argv) {

    if (setup() != 0) {
        fprintf(stderr, "setup failed, terminating\n");
        return 2;
    }

    fprintf(stderr, "system initialization complete\n");
    fprintf(stderr, "initialize input pin(s)\n");  

    mcp23x17_setPinInputMode(zone1aPin, TRUE, &eventMethod);
    mcp23x17_setPinInputMode(zone1bPin, TRUE, &eventMethod);

    // read initial value and set LED to match accordingly;
    int v1 = mcp23x17_digitalRead(zone1aPin);   
    int v2 = mcp23x17_digitalRead(zone1bPin);   


    neopixel_setPixel(0,neopixel_wheel(getColor(v1,v2)));  
    neopixel_render();

    while (true) {
        delay(500); fflush(stdout); fflush(stderr);
    }

//  not necessary
    neopixel_clear();
    neopixel_render();
    neopixel_close();

    return 0;
}

