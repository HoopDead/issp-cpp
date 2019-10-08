#include <iostream>

using namespace std;

void text_ansi(int i) //Funkcja wypisująca wszystkie operacje, które można wykonać na tekście.
{
    for(i = 0; i < 8; i++)
    {
        cout << "Numer kodu - " << i << ": " << "\x1b[" << i << "m" << "Wynik" << "\x1b[0m" << endl;
    }
}

void color_ansi(int i) //Funkcja wypisująca wszystkie operacjące pozwalająca zmienić kolor tekstu - BEZ TŁA
{
    for(i = 30; i < 38; i++)
    {
        cout << "Numer kodu - " << i << ": " << "\x1b[" << i << "m" << "Wynik" << "\x1b[0m" << endl;
    }
}

void color_background_ansi(int i) //Funkcja wypisująca wszystkie kolory tła.
{
    for(i = 41; i < 48; i++)
    {
        cout << "Numer kodu - " << i << ": " << "\x1b[" << i << "m" << "Wynik" << "\x1b[0m" << endl;
    }
}

int main()
{
    text_ansi(7);
    color_ansi(30);
    color_background_ansi(41);
    cout << "\x1b[0m";
}