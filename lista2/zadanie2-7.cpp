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
    cout << "Kat\t" << "cos(x)\t\t" << "cos^2(x)" << endl;
    for(int i = 0; i < 361; i++)
    {
        result = cos(i * PI / 180.0);
        resultroot = pow(cos(i * PI / 180.0), 2);
        cout << i << "\t" << result << "\t" << resultroot << endl;
        wyniki << i << "	" << result << "	" << resultroot << endl;
    }
    wyniki.close();
    return 0;
}
