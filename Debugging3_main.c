#include "geomag.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#define ARRAY_SIZE 5
//#define TARGET_EMBEDDED
//extern BFieldModel BFieldModel1;

extern BFieldModel model;
extern BFieldModel model2015;
//model2015.name[9][0]=model.name[9][0];

//new plan. figure out  what exaclty is there

int main(void)
{
  //  model2015.name[9][0]=model.name[9][0];
//1-9 of rows may have to be for looped
    //model2015.altmax[9]=model.altmax[9];


    unsigned int i = ARRAY_SIZE -1;
    unsigned int source[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    unsigned int destination[ARRAY_SIZE];

    // done is a flag we are using to represent the completion of the copying of the array
    unsigned int done = 0;

    /*
    typedef enum {
    kUnitsKilometers = 1,
    kUnitsMeters     = 2,
    kUnitsFeet       = 3
} Units;
*/
    /*
typedef enum {
    kCoordSysGeodetic   = 1, /* WGS-84 */
  //  kCoordSysGeocentric = 2
//} CoordinateSystem;



//get_field_components(.00030,&model,3000,2,2,30,30,1);

//#define target EMBEDDED Functions read the files in place of file I/O on the MSP
//Have to be used in conjunction with other functions
/*


 * Reads model coefficients from a file.
 *
 * @param model Structure into which model coefficients will be read.
 * @param mdfile Model file name.
 * @return Zero on failure; non-zero on success.

1.

int read_model(BFieldModel *const model, const char mdfile[])

2.

double julday(const int month, const int day, const int year)

3.

get_field_components(BField *const bfield,
                         BFieldModel const*const model,
                         double alt,
                         const Units altUnits,
                         const CoordinateSystem coordSys,
                         const double latitude,
                         const double longitude,
                         const double sdate)                 //writes to the bfield variable

bfield->hdot = htemp - bfield->h;
    bfield->xdot = xtemp - bfield->x;
    bfield->ydot = ytemp - bfield->y;
    bfield->zdot = ztemp - bfield->z;
    bfield->fdot = ftemp - bfield->f;

does the magnetic field direction component calcs with shval3 and dihf3

*/

//read_model(model,"WMM2015.COF");
    initialize_LaunchpadLED1();
    //GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
BField bfield;
double maxalt_b=model.name[1][0];//total field intens                                        //lat long
double minalt_b=model.altmin[1];
 char name_b=model.name[0][0];
 double epoch_b=model.epoch[1];

double sdate=julday(10,18,2020);
get_field_components(&bfield, &model, 500, kUnitsKilometers, kCoordSysGeodetic, 50, 49, sdate); //linking error here

double b=bfield.f;
double maxalt=model.altmax[1];//total field intens                                        //lat long
double minalt=model.altmin[1];//total field intens                                        //lat long

    while (i>0) {
        destination[i] = source[ARRAY_SIZE-i-1];
        i--;
    }

    done = 1;
    while (1) {
    }
}

