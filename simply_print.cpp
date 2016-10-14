#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()

{
    float lat = -30.0;
    float lng =  30.0;
    int i,j;
     
    for(i=0;i<=6;i++)
     {
     for(j=0;j<=9000;j++)
       {
         cout << setprecision(2) << "{ lat: " << lat << "," << "lng:" << lng << "}," << endl;
         lng = lng + 0.01;
         
       }
       lng = 30.0;
       lat = lat + 0.01;
     }
    return 0;
}

