#include "mbed.h"
#include <string>
#include <stdlib.h>
#include "gps.h"
/*#include "sgp4ext.h"
#include "sgp4unit.h"
#include "sgp4io.h"
#include "sgp4coord.h"
*/

Serial pc(USBTX, USBRX);



int main()
{
    /*
    pins:17-20 - stepper motor (use USB power VU)
    cereal port GPS: 9, 10 (tx, rx) 3.3 V
    */
    
    //ENTER TWO-LINE ELEMENT HERE
    char longstr1[] = "1 25544U 98067A   15239.40934558  .00012538  00000-0  18683-3 0  9996";
    char longstr2[] = "2 25544  51.6452  88.4122 0001595  95.9665 324.8493 15.55497522959124";
    

}

void getNewData(){
    
}

void getAzEl(){
}

void initSPG4(){
    //twoline2rv(longstr1, longstr2, typerun, typeinput, opsmode, whichconst, startmfe, stopmfe, deltamin, satrec );
}
