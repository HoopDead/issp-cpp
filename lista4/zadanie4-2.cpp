#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

int createDoc(int s1, int s2, int s3, int s4, int s5)
{
    ofstream plot;
    plot.open("dane.dat", ios::out);
    plot << s1 << endl;
    plot << s2 << endl;
    plot << s3 << endl;
    plot << s4 << endl;
    plot << s5 << endl;
    plot.close();
}

int main()
{
    double srednia1, srednia2, srednia3, srednia4, srednia5;
    for(int i = 0; i < 10; i++)
    {
        double randomNumber = (double)rand() / (RAND_MAX + 1.0);
        srednia1 += randomNumber;
    }
    for(int i = 0; i < 100; i++)
    {
        double randomNumber = (double)rand() / (RAND_MAX + 1.0);
        srednia2 += randomNumber;
    }
    for(int i = 0; i < 1000; i++)
    {        
        double randomNumber = (double)rand() / (RAND_MAX + 1.0);
        srednia3 += randomNumber;
    }
    for(int i = 0; i < 2500; i++)
    {        
        double randomNumber = (double)rand() / (RAND_MAX + 1.0);
        srednia4 += randomNumber;
    }
    for(int i = 0; i < 5000; i++)
    {        
        double randomNumber = (double)rand() / (RAND_MAX + 1.0);
        srednia5 += randomNumber;
    }
    createDoc(srednia1, srednia2, srednia3, srednia4, srednia5);
    cout << srednia1 / 10 << endl;
    cout << srednia2 / 100 << endl;
    cout << srednia3 / 1000 << endl;
    cout << srednia4 / 2500 << endl;
    cout << srednia5 / 5000 << endl;
}

