#include "HtmServerUtilities.h"

DigIO DigitalPorts[18]={ {2,"DIO2"}, {16, "DIO16"}, {17,"DIO17"}};
const char *DigIOResp = "<script> %s(%s);</script>\n";

ADCo ADCs[9]={ {34,"ADC34",1000}};
const char *ADCResp = "<script>  %s(%d);  </script>\n";
const char *ADCUpdate = "<script> setTimeout(function (){makePOSTRequest(\"%s\",\"./ajax\",\"ADC=%s&callback=%s\");},%d); </script>\n";

String handleDigIO(String str, String CBF) {
    String Str = "";
    char buf[128];
    for(int i=0; i<DigIOCount ;i++) { 
        if(str != DigitalPorts[i].name) continue;
        if(!digitalRead(DigitalPorts[i].io)) {
            digitalWrite(DigitalPorts[i].io, HIGH);
            sprintf(buf,DigIOResp, CBF, "true");
        } else {   
            digitalWrite(DigitalPorts[i].io, LOW);
            sprintf(buf,DigIOResp, CBF, "false");
        }
        Str=buf;
        if(PrintSerial){ Serial.print(buf);}
        break;
    }
    return Str;
}

String ReadDigIO(String str, String CBF) {
    String Str = "";
    char buf[128];
    for(int i=0; i<DigIOCount ;i++) { 
        if(str != DigitalPorts[i].name) continue;
        if(digitalRead(DigitalPorts[i].io)) {
            sprintf(buf,DigIOResp, CBF, "true");
        } else {   
            sprintf(buf,DigIOResp, CBF, "false");
        }
        Str=buf;
        if(PrintSerial){ Serial.print(buf);}
        break;
    }
    return Str;
}

void setupDIO(){
    for(int i=0; i<DigIOCount ;i++) { 
        pinMode(DigitalPorts[i].io,OUTPUT);
        digitalWrite(DigitalPorts[i].io,LOW);
    }
}

String handleADC(String str, String CBF) {
    String Str = "";
    char buf[512];
    int value;
    uint8_t ADCPin;
    for(int i=0; i<ADCount ;i++) { 
        if(str != ADCs[i].name) continue;
        ADCPin = ADCs[i].io;
        value = analogRead(ADCPin);
        sprintf(buf,ADCResp, CBF, value);
        Str=buf;
        if(ADCs[i].update){
            sprintf(buf,ADCUpdate, ADCs[i].name, ADCs[i].name, CBF, ADCs[i].update);
            Str += buf;
        }
        if(PrintSerial){ Serial.print(Str); }
    }
    return Str;
}

String showPinDefs(){
    /*

        var usedPins = [2,16,17,34];
        var availDIOs = [2,4,5,13,14,15,16,17,18,19,21,22,23,25,26,27,32,33];
        var usedDIOs =[2,16,17];
        var availADCs = [2,4,32,33,34,35,36,39];
        var usedADCs =[34];
        var availTouch = [0,4,2,12,13,14,15,27,32,33];
        var usedTouch =[];
        var availPWMs = [2,4,5,13,14,15,16,17,18,19,21,22,23,25,26,27,32,33];
        var usedPWMs =[];
        var availDACs = [25,26];
        var usedDACs =[];
        var availHSPIs=[12,13,14,15];
        var usedHSPIs=[];
        var availVSPIs=[5,18,19,23];
        var usedVSPIs=[];
        var availI2Cs = [33,36];
        var usedI2Cs =[];
    */
    String Str = "";
    char buf[128];
    int usedpins[38];
    sprintf(buf,"<script>\nusedDIOs = [");
    Str += buf;
    for(int i=0; i<DigIOCount ;i++) { 
        if( i+1 == DigIOCount) {
            sprintf(buf," %d];\n", DigitalPorts[i].io);
        }else{
            sprintf(buf," %d,", DigitalPorts[i].io);
        }
        Str += buf;
    }

    sprintf(buf,"<script>\nusedADCs = [");
    Str += buf;
    for(int i=0; i<ADCount ;i++) { 
        if( i+1 == ADCount) {
            sprintf(buf," %d];\n", ADCs[i].io);
        }else{
            sprintf(buf," %d,", ADCs[i].io);
        }
        Str += buf;
    }
    
}