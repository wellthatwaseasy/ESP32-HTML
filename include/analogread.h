#ifndef _AnalogRead_DEF
#define _AnalogRead_DEF

// Analog ports will have a name and the port that it is associated with and an update to start a timer to recall the ADC's ajax

struct ADCo{
    uint8_t io;
    const char  *name;
    int update;
};

#define ADCount 1


struct ADC{
    uint8_t io;
    int value;
    String type="ADC";
    
    int read(){
        value = analogRead(io);
        return value;
    }
    void init(){
        pinMode(io,INPUT);
        value = read();
    }
};

struct TOUCH{
    uint8_t io;
    int value;
    String type="TCH";
    
    int read(){
        value = touchRead(io);
        return value;
    }
    void init(){
        pinMode(io,INPUT);
        value = read();
    }
};

struct HallSensor{
    int value;
    String type="HALL";
    
    int read(){
        return value = hallRead();
    }
};

#endif