#include <iostream>

using namespace std;

int main()
{
    for (int i = -5; i < 6; i++)
    {
        for (int j = -5; j < 6; j++)
        {
            cout << i << " * " << j << " = " << i*j << endl;
        }
        cout << "==============" << endl;
    }
    return 0;
}