#include <iostream>

using namespace std;

void a()
{
    cout << "Hello World" << endl;
}

float b(float b)
{
    return b;
}

int c(int c1, int c2)
{
    return c1 + c2;
}

int d(int x1, float x2)
{
    return x1 * x2;
}

int e(int tab[5], int len)
{
    int suma = 0;
    for(int i = 0; i < len; i++)
    {
        suma += tab[i];
    }
    return suma;
}

int main()
{
    int tab[5] = {1, 2, 3, 4, 5};
    a();
    cout << b(5.123123) << endl;
    cout << c(1, 3) << endl;
    cout << d(4, 4.5) << endl;
    cout << e(tab, sizeof(tab)/sizeof(int)) << endl;
    return 0;
}