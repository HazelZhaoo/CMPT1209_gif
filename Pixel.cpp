#include "Pixel.hpp"
#include <fstream>

class Pixel::InputOutOfBoundsException
{
private:
    const char* errorMessage;
    const char* offendingIndex;
public:
    InputOutOfBoundsException(const char*, const char*);
    const char* returnError();
    const char* returnOffendingIndex();

};

Pixel::InputOutOfBoundsException::InputOutOfBoundsException(const char* error, const char* index) : errorMessage(error), offendingIndex(index)
{
};
const char* Pixel::InputOutOfBoundsException::returnError()
{
    return errorMessage;
};

const char* Pixel::InputOutOfBoundsException::returnOffendingIndex()
{
    return offendingIndex;
};

Pixel:: ~Pixel()
{
    //cout << "Pixel destructor called." << endl;
};

Pixel::Pixel() :blue(0), green(0), red(0)
{
    //cout << "Pixel default constructor called." << endl;
};

Pixel::Pixel(unsigned int p_blue, unsigned int p_green, unsigned int p_red) :blue(0), green(0), red(0)
{
    blue = p_blue;
    green = p_green;
    red = p_red;
    //cout << "Pixel 3 arg constructor is called" << endl;
}
Pixel::Pixel(const Pixel& p) :blue(0), green(0), red(0)
{
    blue = p.blue;
    green = p.green;
    red = p.red;
   // cout << "Pixel copy constructor called." << endl;
};

const unsigned int& Pixel::operator[](const char* color) const
{
    if (strcmp(color, "red") == 0)
        return red;
    else if (strcmp(color, "blue") == 0)
        return blue;
    else if (strcmp(color, "green") == 0)
        return green;
    else
        throw (InputOutOfBoundsException(color, "error message"));
};

ofstream& operator<< (ofstream& output, const Pixel& p)
{
    //cout << "Now creating the Newton Fractal..." << endl;
    try
    {
        output << p["red"] << " " << p["green"] << " " << p["blue"] << " ";

    }
    catch (Pixel::InputOutOfBoundsException Error)
    {
        output << Error.returnError() << endl;
        cout << "> Offending input was: " << Error.returnOffendingIndex() << endl;
        cout << "> Application exiting...\n";
        exit(1);
    }
    return output;
};

