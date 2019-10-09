#include <iostream>

using namespace std;

int main()
{
    const int W = 20;
    const int H = 30;
    for(int j = 0; j < H; j++)
    {
        for(int i = 0; i < W; i++)
        {
            int r =(i/float(W)) * 100;
            int g = (j/float(H))*255;
            int b = (i/float(W))*255;
            cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m" << "   \x1b[0m";
        }
        cout << endl;
    }
    return 0;
}