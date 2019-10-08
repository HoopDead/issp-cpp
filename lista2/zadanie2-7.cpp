#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

#define PI 3.14159265

int main()
{
    double angle, result, resultroot;
    ofstream wyniki;
    wyniki.open("wyniki.dat", ios::out);
    for(int i = 0; i < 360; i++)
    {
        result = cos(i * PI / 180.0);
        resultroot = pow(cos(i * PI / 180.0), 2);
        cout << i << "  " << result << "  " << resultroot << endl;
        wyniki << i << "    " << result << "    " << resultroot << endl;
    }
    wyniki.close();
    return 0;
}