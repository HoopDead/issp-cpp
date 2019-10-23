#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    const int W = 25;
    const int H = 40;
    for(int j = 0; j < H; j++)
    {
        for(int i = 0; i < W; i++)
        {
            int r =(i/float(W)) * 55;
            int g = 50;
            int b = (i/float(W))*100;
            cout << "\033[48;2;" << r << ";" << g << ";" << b << "m" << "   \033[0m";
        }
        cout << endl;
    }
    return 0;
}