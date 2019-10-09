#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    for(int i = 0; i < 16; i++)
    {
	    cout << "\x1b[44m" << endl;
        Sleep(150);
    }
    for(int i = 0; i < 15; i++)
    {
        cout <<"o\x1b[1B";
        Sleep(150);
    }
    for(int i = 0; i < 15; i++)
    {
        cout << "o\x1b[1A";
        Sleep(150);
    }
    for(int i = 0; i < 4; i++)
    {
        cout <<"o\x1b[1B";
        Sleep(150);
    }
    for(int i = 0; i < 4; i++)
    {
        cout << "o\x1b[1A";
        Sleep(150);
    }
    for(int i = 0; i < 15; i++)
    {
        cout <<"o\x1b[1B";
        Sleep(150);
    }
    for(int i = 0; i < 9; i++)
    {
        cout << "o\x1b[1A";
        Sleep(150);
    }
    for(int i = 0; i < 9; i++)
    {
        cout << "o\x1b[1B";
        Sleep(150);
    }
        for(int i = 0; i < 15; i++)
    {
        cout << "o\x1b[1A";
        Sleep(150);
    }
    cout << "\x1b[100;100H";
    cout << "\x1b[0m";
    return 0;
}