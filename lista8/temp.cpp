// vector::begin/end
#include <iostream>
#include <vector>

using namespace std;


int tab[100];
vector<int> liczby;

void everyTwoTab()
{
    for(int i = 0; i < 100; i = i+2)
    {
        cout << tab[i] << " ";
    }
}


void getTab(int N)
{
    for(int i = 0; i < 100; i = i+N)
    {
        cout << tab[i] << " ";
    }
}

int main ()
{
    int N;
    cout << "Podaj N: ";
    cin >> N;
    for(int i = 0; i < 100; i++)
    {
        tab[i] = i;
    }
    cout << "Co dwa: ";
    everyTwoTab();
    cout << endl;
    cout << "Co " << N << ": ";
    getTab(N);
    cout << '\n';
    return 0;
}