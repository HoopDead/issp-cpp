#include <iostream>
#include <unistd.h>

using namespace std;

//227, 134, 20 - orange
//237, 245, 7 - yellow
void init()
{
    for(int i = 11; i < 26; i++)
    {
        for(int j = 11; j < 61; j++)
        {
            cout << "\x1b[" << i << ";" << j << "H" << "\x1b[48;5;27m ";
        }
    }
}

void randomize_particles()
{
    int randomY = rand()%(25-11 + 1) + 11;
    int randomX = rand()%(60-11 + 1) + 11;
    int randomcolor = rand()%(200-100 + 1) + 100;
    cout << "\x1b[" << randomY << ";" << randomX << "H" << "\x1b[0m ";
    cout << "\x1b[" << randomY << ";" << randomX << "H" << "\x1b[48;2;" << "255;" << randomcolor << ";37m " ;
    usleep(7500);
    randomY = 0;
    randomX = 0;
}


int main()
{
    bool run = true;
    cout << "\x1b[2J";
    init();
    while(run)
    {
        randomize_particles();
    }
    cout << "\x1b[0m";
    cout << "\x1b[30;0H";
    return 0;
}