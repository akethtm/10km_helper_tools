// A C++ program to implement flood fill algorithm
#include<iostream>
#include<fstream>
using namespace std;

// Dimentions of paint screen
#define M 600
#define N 900

void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC)
{
	// Base cases
	if (x < 0 || x >= M || y < 0 || y >= N)
		return;
	if (screen[x][y] != prevC)
		return;

	// Replace the color at (x, y)
        cout << y+1 << "\t," << x+1 << "\t," << newC << endl;  
	screen[x][y] = newC;

	// Recur for north, east, south and west
	floodFillUtil(screen, x+1, y, prevC, newC);
	floodFillUtil(screen, x-1, y, prevC, newC);
	floodFillUtil(screen, x, y+1, prevC, newC);
	floodFillUtil(screen, x, y-1, prevC, newC);
}

// It mainly finds the previous color on (x, y) and
// calls floodFillUtil()
void floodFill(int screen[][N], int x, int y, int newC)
{
	int prevC;
        x = x-1;
        y = y-1;
        prevC = screen[x][y]; // lat long
        cout << "Correct Cooridinates are " << x << " " << y << endl;
        if( prevC == newC )
        {
        cout << "Incorrect point";
        return;     
        }
	floodFillUtil(screen, x, y, prevC, newC);
}

int main()
{
	int screen[M][N];
        int i,j,count=1;
        int x,y,newC; 
        ifstream infile;
        ofstream outfile;
        char filename[100];

        infile.open ("flooddata");
        for(i=0;i<600;i++)
            for(j=0;j<900;j++)
                {
                     infile >> screen[i][j];
                }
        
        cout << "enter the seed point"<< endl;
        cin >> x >> y;
        cout << "enter the new color"<< endl;
        cin >> newC;
        floodFill(screen, x, y, newC);

        /*outfile.open("flooddata");
        for(i=0;i<600;i++)
           { 
            for(j=0;j<900;j++)
                {
                     outfile << screen[i][j] << " ";
               }
                     outfile << endl; 
           }*/
}
