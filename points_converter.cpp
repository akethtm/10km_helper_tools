#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int main()
{

float lat,lon,eps;

//file handles
ifstream infile;
ofstream outfile;

int integer_part,decimal_part;
int grid_point;

cin >> lat;
cin >> lon;

eps = (fmod(lat,0.1) - 0.05);
eps = fabs(eps);
if( eps >= 0.01 ) 
   { 
        cout << "error in lat" << " " << "fmod is " << fmod(lat,0.1) << endl;
   }

eps = (fmod(lon,0.1) - 0.05);
eps = fabs(eps);
if( eps >= 0.01 )
   {
        cout << "error in lon" << " " << "fmod is " << fmod(lon,0.1) << endl;
   }

// converting from lat-lon to points
integer_part = int(lat);
decimal_part = ( int ( ( lat - int(lat) ) * 10 ) ) % 10;

cout << integer_part << endl;
cout << decimal_part << endl;

grid_point = integer_part * 10 + decimal_part;
cout << grid_point;

return 0;
}
