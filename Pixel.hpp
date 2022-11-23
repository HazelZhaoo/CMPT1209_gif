#ifndef Pixel_hpp
#define Pixel_hpp
#include <iostream>
using namespace std;

class Pixel
{
private:
    unsigned int blue;
    unsigned int green;
    unsigned int red;

public:
    ~Pixel();
    const unsigned int& operator[](const char*) const;
    Pixel();
    Pixel(const Pixel&);
    Pixel(unsigned int, unsigned int, unsigned int);
    class InputOutOfBoundsException;
    friend ofstream& operator<<(ofstream&, const Pixel&);


};


#endif
