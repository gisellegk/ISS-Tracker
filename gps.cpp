#include "mbed.h"
#include "gps.h"

GPS::GPS(){
    gps = new Serial(p9, p10);
}

//this is run once at startup, and can be re-run on demand. 
void GPS::getLocation() 
{
    gps->baud(9600);
    float location[4];
    while(1) {
        parseData(location);
        
    }
}

void GPS::parseData(float* location)
{
    if(gps->readable()) {
        std::string rawGPSData = "";
        char c = gps->getc();
        //pc.putc(c);
        if(c == '\n' || c == '\r') {
            // marks end of line
            // GPS data marked as GPGGA is useful and gets put into an array
            if(rawGPSData.find("GPGGA") != std::string::npos) {
                location = createLocArray(rawGPSData); // THIS IS RETURNING TO NOWHERE !!!
                rawGPSData = "";
            }
        } else {
            // continues adding characters to the line, as it's not completed and ready to be parsed.
            rawGPSData.push_back(c);
        }
    }
}

float* GPS::createLocArray(string unparsed)
{

    std::string gpsData[10];
    for(int i = 0; i<10; i++) {
        unparsed = unparsed.substr(unparsed.find_first_of(",")+1);
        gpsData[i] = unparsed.substr(0,unparsed.find_first_of(","));
    }

    //check valid data flag, if the data is valid, put flag / lat / long / alt in correct formats
    if(gpsData[5]=="1") {
        float* location = new float[4];
        location[0] = strtof(gpsData[5].c_str(),NULL);
        location[1] = strtof(gpsData[1].c_str(),NULL);
        if(gpsData[2] != "N") {
            location[1] = 0 - location[0]; //i think???
        }
        location[2] = strtof(gpsData[3].c_str(),NULL);
        if(gpsData[4] != "E") {
            location[2] = 0 - location[1]; // ??????
        }
        location[3] = strtof(gpsData[8].c_str(),NULL);
        //pc.printf("flt Coordinates: %f %s , %f %s . Altitude: %f Meters.\n\r", location[1], gpsData[2].c_str(), location[2], gpsData[4].c_str(), location[3]);
        //pc.printf("str Coordinates: %s %s , %s %s . Altitude: %s Meters.", gpsData[1].c_str(), gpsData[2].c_str(), gpsData[3].c_str(), gpsData[4].c_str(), gpsData[8].c_str());

        return location;
    } else {
        //pc.printf("No GPS Signal");
        float* invalid = {0};
        return invalid;
    }

}
