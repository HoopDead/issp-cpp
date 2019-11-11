#include <iostream>
#include <ctime>
using namespace std;
 
const int rows = 10;
const int elements = 10;
 
int maxships = 25;
int round = 0;
 
int matrix[rows][elements];
int unknown[rows][elements];
 
void map_clear()
{
        for(int i=0; i < rows; i++)
        {
                for(int j=0; j < elements; j++)
                {
                        matrix[i][j] = 0;
                        unknown[i][j] = 3;
                }
        }
}
 
void map_show()
{
    cout << "# 0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i=0; i < rows; i++)
    {
        cout << i << " ";
        for(int j=0; j < elements; j++)
        {
            if(unknown[i][j] == 0)
            {
                cout << "\x1b[48:5:33m  \x1b[0m";
            }
            else if (unknown[i][j] == 1)
            {
                cout << "\x1b[48:5:244m  \x1b[0m";
            }
            else if (unknown[i][j] == 2)
            {
                cout << "\x1b[48:5:244m  \x1b[0m";
            }
            else if (unknown[i][j] == 3)
            {
                    cout << "??";
            }
        }
        cout << "\x1b[0m";
        cout << endl;
    }
}
 
int shipsleft()
{
        int c = 0;
        for(int i=0; i < rows; i++)
        {
                for(int j=0; j < elements; j++)
                {
                        if(matrix[i][j] == 1)
                        c++;
                }
        }
 
        return c;
}
 
void map_set()
{
        int s = 0;
        while(s < maxships)
        {
                int x = rand() % rows;
                int y = rand() % elements;
                if(matrix[x][y] != 1)
                {
                        s++;
                        matrix[x][y] = 1;
                }
        }
}
 
bool try_hit(int x,int y)
{
        if(matrix[x][y] == 1)
        {
                matrix[x][y] = 2;
                unknown[x][y] = 2;
                return true;
        }
        else
        {
                unknown[x][y] = 0;
        }
        return false;
}
 
int main()
{
        srand(time(NULL));
        map_clear();
        map_set();
        map_show();
        int x,y;
        char option;
        for(;;)
        {
            cout << "Wpisz lokalizacje np. (1 1): "; 
            cin >> x >> y;
            round++;
            if(try_hit(x,y))
            {
                cout << "Udalo sie trafic!" << endl;
            }
            else
            {
                cout << "Nie ma statku na tej pozycji!" << endl;
                cout << "Ile statkow zostalo: " << shipsleft() << endl;
                cout << "Czy chcesz skonczyc gre? (T/N)? "; 
                cin >> option;
                if(option == 'T' || option == 't')
                {
                    break;
                }
            }
            map_show();
        }
        cout << "Koniec gry!" << endl;
        cout << "Zajelo Ci to: " << round << " rund" << endl;
        system("pause");
        return 0;
}