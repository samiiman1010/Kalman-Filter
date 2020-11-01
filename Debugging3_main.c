#include "geomag.h"
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#define ARRAY_SIZE 5
//#define TARGET_EMBEDDED
//extern BFieldModel BFieldModel1;

extern BFieldModel model2015;
//extern BFieldModel model;
//model2015.name[9][0]=model.name[9][0];

//new plan. figure out  what exaclty is there

int main(void)
{
  //  model2015.name[9][0]=model.name[9][0];
//1-9 of rows may have to be for looped
    //model2015.altmax[9]=model.altmax[9];
/*
    unsigned int i = ARRAY_SIZE -1;
    unsigned int source[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    unsigned int destination[ARRAY_SIZE];

    // done is a flag we are using to represent the completion of the copying of the array
    unsigned int done = 0;

    float countlat=90-(-90);
    float countlong=135-(-135);

    float inc1=countlat/400;

    lats[0]=-90;
    int a;
    for(a=0;a < 400;a++)
            { lats[a]=lats[a-1]+inc1;

            }
  */
float latspath1[100]={-90,-88.18181818,-86.36363636,-84.54545455,-82.72727273,-80.90909091,-79.09090909,-77.27272727,-75.45454545,-73.63636364,-71.81818182,-70,-68.18181818,-66.36363636,-64.54545455,-62.72727273,-60.90909091,-59.09090909,-57.27272727,-55.45454545,-53.63636364,-51.81818182,-50,-48.18181818,-46.36363636,-44.54545455,-42.72727273,-40.90909091,-39.09090909,-37.27272727,-35.45454545,-33.63636364,-31.81818182,-30,-28.18181818,-26.36363636,-24.54545455,-22.72727273,-20.90909091,-19.09090909,-17.27272727,-15.45454545,-13.63636364,-11.81818182,-10,-8.181818182,-6.363636364,-4.545454545,-2.727272727,-0.909090909,0.909090909,2.727272727,4.545454545,6.363636364,8.181818182,10,11.81818182,13.63636364,15.45454545,17.27272727,19.09090909,20.90909091,22.72727273,24.54545455,26.36363636,28.18181818,30,31.81818182,33.63636364,35.45454545,37.27272727,39.09090909,40.90909091,42.72727273,44.54545455,46.36363636,48.18181818,50,51.81818182,53.63636364,55.45454545,57.27272727,59.09090909,60.90909091,62.72727273,64.54545455,66.36363636,68.18181818,70,71.81818182,73.63636364,75.45454545,77.27272727,79.09090909,80.90909091,82.72727273,84.54545455,86.36363636,88.18181818,90};
float longpath1[100]={-135,-132.2727273,-129.5454545,-126.8181818,-124.0909091,-121.3636364,-118.6363636,-115.9090909,-113.1818182,-110.4545455,-107.7272727,-105,-102.2727273,-99.54545455,-96.81818182,-94.09090909,-91.36363636,-88.63636364,-85.90909091,-83.18181818,-80.45454545,-77.72727273,-75,-72.27272727,-69.54545455,-66.81818182,-64.09090909,-61.36363636,-58.63636364,-55.90909091,-53.18181818,-50.45454545,-47.72727273,-45,-42.27272727,-39.54545455,-36.81818182,-34.09090909,-31.36363636,-28.63636364,-25.90909091,-23.18181818,-20.45454545,-17.72727273,-15,-12.27272727,-9.545454545,-6.818181818,-4.090909091,-1.363636364,1.363636364,4.090909091,6.818181818,9.545454545,12.27272727,15,17.72727273,20.45454545,23.18181818,25.90909091,28.63636364,31.36363636,34.09090909,36.81818182,39.54545455,42.27272727,45,47.72727273,50.45454545,53.18181818,55.90909091,58.63636364,61.36363636,64.09090909,66.81818182,69.54545455,72.27272727,75,77.72727273,80.45454545,83.18181818,85.90909091,88.63636364,91.36363636,94.09090909,96.81818182,99.54545455,102.2727273,105,107.7272727,110.4545455,113.1818182,115.9090909,118.6363636,121.3636364,124.0909091,126.8181818,129.5454545,132.2727273,135};

//int latspath2=-90;
    int a=0;

//float longpath2[781]={135,134.0909091,133.1818182,132.2727273,131.3636364,130.4545455,129.5454545,128.6363636,127.7272727,126.8181818,125.9090909,125,124.0909091,123.1818182,122.2727273,121.3636364,120.4545455,119.5454545,118.6363636,117.7272727,116.8181818,115.9090909,115,114.0909091,113.1818182,112.2727273,111.3636364,110.4545455,109.5454545,108.6363636,107.7272727,106.8181818,105.9090909,105,104.0909091,103.1818182,102.2727273,101.3636364,100.4545455,99.54545455,98.63636364,97.72727273,96.81818182,95.90909091,95,94.09090909,93.18181818,92.27272727,91.36363636,90.45454545,89.54545455,88.63636364,87.72727273,86.81818182,85.90909091,85,84.09090909,83.18181818,82.27272727,81.36363636,80.45454545,79.54545455,78.63636364,77.72727273,76.81818182,75.90909091,75,74.09090909,73.18181818,72.27272727,71.36363636,70.45454545,69.54545455,68.63636364,67.72727273,66.81818182,65.90909091,65,64.09090909,63.18181818,62.27272727,61.36363636,60.45454545,59.54545455,58.63636364,57.72727273,56.81818182,55.90909091,55,54.09090909,53.18181818,52.27272727,51.36363636,50.45454545,49.54545455,48.63636364,47.72727273,46.81818182,45.90909091,45};
    /*
    typedef enum {
    kUnitsKilometers = 1,
    kUnitsMeters     = 2,
    kUnitsFeet       = 3
} Units;
*/
    /*
typedef enum
    kCoordSysGeodetic   = 1, /* WGS-84 */
  //  kCoordSysGeocentric = 2
// CoordinateSystem;



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
    turnOff_LaunchpadLED1();
BField bfield;

//double maxalt_b=model2015only.name[1][1];//total field intens                                        //lat long

//double epoch_b=model2015only.nmodel;
//double epoch_b2=model2015only.altmax[1];
double sdate=julday(12,29,2014);//model2015 is the best working model
float path2bfield_x[100];
//float path2bfield_y[100];
//float path2bfield_z[100];
//lat must be <90
//long must be <180
//get_field_components(&bfield, &model2015, 10, kUnitsKilometers, kCoordSysGeodetic, 80, 145/*longpath2[130]*/, sdate); //if the max year is set at YEAR any date past 1/1/YEAR will be greater then YEAR

/*

int get_field_components(BField *const bfield,              // const changed to float
                         BFieldModel const*const model,      // const changed to float
                         double alt,
                         const Units altUnits,
                         const CoordinateSystem coordSys,
                         const double latitude,
                         const double longitude,
                         const double sdate)
*/
//get_field_components(&bfield, &model2015, 10, kUnitsKilometers, kCoordSysGeodetic, 37.22,-80.42, sdate);

for(a=0;a<100;a++)
{
    //get_field_components(&bfield, &model2015, 100, kUnitsKilometers, kCoordSysGeodetic,-90, longpath2[a], sdate); //if the max year is set at YEAR any date past 1/1/YEAR will be greater then YEAR
   get_field_components(&bfield, &model2015, 10, kUnitsKilometers, kCoordSysGeodetic,latspath1[a], longpath1[a], sdate); //if the max year is set at YEAR any date past 1/1/YEAR will be greater then YEAR

    //path2bfield_d[a]=bfield.d;
    //path2bfield_f[a]=bfield.f;
   path2bfield_x[a]=bfield.f;
  // path2bfield_y[a]=bfield.y;
   //path2bfield_z[a]=bfield.z;
}

 //if the max year is set at YEAR any date past 1/1/YEAR will be greater then YEAR

//a=3 value
//get_field_components(&bfield, &model2015, 10, kUnitsKilometers, kCoordSysGeodetic,-90, 100, sdate); //if the max year is set at YEAR any date past 1/1/YEAR will be greater then YEAR


//double maxalt=model2015.altmax[1];//total field intens                                        //lat long
//double minalt=model2015.altmin[1];//total field intens                                        //lat long
/*
    while (i>0) {
        destination[i] = source[ARRAY_SIZE-i-1];
        i--;
    }

    done = 1;
    while (1) {
    }
*/
}

