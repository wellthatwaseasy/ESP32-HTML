#ifndef _Digital_DEF
#define _Digital_DEF

// Digital ports will have a name and the port that it is associated with

struct DigIO{
    uint8_t io;
    const char  *name;
};
#define DigIOCount 3


struct DIO{
    uint8_t io;
    bool state;
    String type="DIO";
    
    void update(){
        digitalWrite(io, state ? HIGH : LOW);
    }
    void write(bool s){
        state=s;
        update();
    }
    int read(){
        return state = digitalRead(io);
    }
    void init(){
        pinMode(io,OUTPUT);
        digitalWrite(io,LOW);
        state = digitalRead(io);
    }
};

#endif