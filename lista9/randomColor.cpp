#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

typedef struct {
    int R;
    int G;
    int B;
} pixel;

const int W = 800;
const int H = 600;
pixel obrazek[W][H];

void zapisz(pixel obr[W][H])
{
    char workbuf[80];
    ofstream file(workbuf);
    sprintf(workbuf, "obrazek1.ppm");
    file << "P3" << endl;
    file << W << " " << H << endl;
    file << 255 << endl;
    for(int j = 0; j < H;j ++)
    {
        for(int i = 0; i < W; i++)
        {
            file << rand() % ((256 + 1) - 1) << " ";
            file << rand() % ((256 + 1) - 1) << " ";
            file << rand() % ((256 + 1) - 1) << " ";
        }
        file << endl;
    }
    file.close();
}

int main()
{
    srand(time(NULL));
    for(float t = 0; t < 1; t+=0.1)
    {
        zapisz(obrazek);
    }
    return 0;
}