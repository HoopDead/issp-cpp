#include <iostream>

using namespace std;

int main()
{
    cout << "\t-5\t-4\t-3\t-2\t-1\t0\t1\t2\t3\t4\t5" << endl;
    for (int i = -5; i < 6; i++)
    {
        cout << i << "\t";
        for (int j = -5; j < 6; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}