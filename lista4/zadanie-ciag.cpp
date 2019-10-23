#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float ans = 0;
    for(int i = 1; i < 1000; i++)
    {
        ans = ans + (1/pow(i, 2));
    }
    cout << "Pi^2 / 6 = " << pow(M_PI, 2) / 6 << endl;
    cout <<  "Ciag an = an-1 + 1/(n^2) = " << ans << endl;
    return 0;
}