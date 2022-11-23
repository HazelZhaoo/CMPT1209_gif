#include <iostream>
#include <fstream>
#include <string>
#include "Pixel.hpp"
#include <vector>
using namespace std;

void rotatePPM(ifstream&);
int main()
{
  ifstream infile("batman.ppm");
  try
  {
      rotatePPM(infile);
  }
  catch (const char* s)
  {
      cout << s;
      
  }
  infile.close();
    return 0;
    
}

void rotatePPM(ifstream& infile)
{
    vector <Pixel> fixels ;
    string magic , comment ;
    int rows , columns , maxColor , red , green , blue;
    if(infile.fail())
    {
        throw "Cant open file.";
    }
    else
    {
        getline(infile , magic , '\n');
        getline(infile , comment , '\n');
        infile >> columns >> rows  >> maxColor;
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < columns ; j++)
            {
                infile >> red >> green >> blue ;
                fixels.emplace_back(red , green , blue);
            }
        }
    }
    
    for(int i = 0 ; i < rows ; i+= 10)
    {
        rotate(fixels.begin(), fixels.begin()+ (columns*10) , fixels.end());
        ofstream outfile;
        
        string file_name = "frame_" + to_string(i / 10) + ".ppm";
        outfile.open(file_name);
        outfile << magic << "\n" << comment << endl;
        outfile << columns <<" "<< rows << " "<< maxColor << endl;
        for(auto element : fixels)
        {
            outfile << element << " " ;
        }
        outfile.close();
    }
    
     
}
