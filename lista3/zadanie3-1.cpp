#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(nullptr));
    const int W = 20;
    const int H = 30;
    for(int j = 0; j < H; j++)
    {
        for(int i = 0; i < W; i++)
        {
            int r =(i/float(W)) * 0;
            int g = (j/float(H))*255;
            int b = (i/float(W))*55;
            cout << "\033[48;2;" << r << ";" << g << ";" << b << "m" << "   \033[0m";
        }
        cout << endl;
    }
    return 0;
}