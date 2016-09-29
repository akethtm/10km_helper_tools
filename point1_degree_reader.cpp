#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
  int wet_data[600][900],i,j; //latitude and longitude
  int lat_start;
  int lat_end;
  int lon_start;
  int lon_end;

  int lat, lon;

  char key; 
  //int count = 1;
  fstream infile;
  infile.open ("10km_wet_data");
  for(i=0;i<600;i++)
   for(j=0;j<900;j++)
   {
           infile >> wet_data[i][j];
           //cout << wet_data[i][j];
           //cout << " " << count << endl;
           //count++;
   }

   while(1)
   {

          cout << endl;
          cout << "Enter your choices" << endl;
          cout << "q:quit  d:display grid p:know a point" << endl;
          cin >> key;

          if( key == 'p') 
          {
              cout << "enter the latitude" << endl; 
              cin >> lat;
              cout << "enter the longitude" << endl;             
              cin >> lon;
              cout << "wet mask at is lat "<< lat <<" and at lon "<< lon << " is "<< wet_data[lat-1][lon-1] << endl;               
          } 

          if(key == 'q') break;

          if(key == 'd')
          { 
             cout << endl;
             cout << "enter lat_start and lat_end" << endl;
             cin >> lat_start;
             cin >> lat_end;
  
             cout << "enter lon_start and lon_end" << endl;
             cin >> lon_start;
             cin >> lon_end;

             lat_start = lat_start - 1;
             lat_end = lat_end - 1;   

             lon_start = lon_start - 1;
             lon_end = lon_end - 1;
          
             for(j=lon_start;j<=lon_end;j++) 
                 if( (j+1)%10 == 0 ) 
                      cout << ( ((j+1)/10)%10  );
                 else
                       cout << " ";               
 
             cout << endl;

             for(i=lat_end;i>=lat_start;i--)
                {
                   for(j=lon_start;j<=lon_end;j++)
                      {
                         if(wet_data[i][j] == 1) 
                           { 
                             cout << "o";
                           }
                         else
                           {
                             cout << ".";      
                           }
                      }
                 cout << " " << i+1 << endl;
                 }
          for(j=lon_start;j<=lon_end;j++) cout << (j+1)%10;
          }

   }
  infile.close();
  return 0;
}
