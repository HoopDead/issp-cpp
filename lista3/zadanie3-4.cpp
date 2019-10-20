#include <iostream>

using namespace std;

int main()
{
    int x, firstnumber, secondnumber;
    bool run = true;
    int isnext = 1;
    while(run)
    {
    if(isnext == 0)
    {
        run = false;
        break;
    }
    else
        {
        cout << "Wprowadz operacje (1 - odejmowanie, 2 - mnozenie): ";
            while(!(cin>>x))
            {
                cout << "\x1b[31m[!]\x1b[0mNumer operacji koniecznie musi byc liczba!" << endl;
                cout << "Wprowadz operacje (1 - odejmowanie, 2 - mnozenie): ";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
            }
            cout << "Podaj pierwsza liczbe: ";
            while(!(cin>>firstnumber))
            {
                cout << "\x1b[31m[!]\x1b[0mUps! Podales cos innego, niz liczbe." << endl;
                cout << "Podaj pierwsza liczbe: ";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
            }
            cout << "Podaj druga liczbe: ";
            while(!(cin>>secondnumber))
            {
                cout << "\x1b[31m[!]\x1b[0mUps! Podales cos innego, niz liczbe." << endl;
                cout << "Podaj druga liczbe: ";
                cin.clear();
                cin.ignore(INT_MAX,'\n');        
            }
            if(x == 1)
            {
                cout << "Wynik to: " << firstnumber - secondnumber << endl;
            }
            else if(x == 2)
            {
                cout << "Wynik to: " << firstnumber * secondnumber << endl;
            }
            cout << "Czy chcesz kontynuowac? (0 - NIE, 1 - TAK): ";
            while(!(cin>>isnext))
            {
                cout << "\x1b[31m[!]\x1b[0mUps! Podales cos innego, niz tekst." << endl;
                cout << "Czy chcesz kontynuowac? (0 - NIE, 1 - TAK): ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }
        }
    }
    return 0;
}