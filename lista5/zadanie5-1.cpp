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
<<<<<<< HEAD
 
void map_show()
{
    cout << "# 0 1 2 3 4 5 6 7 8 9" << endl;
    for(int i=0; i < rows; i++)
=======

void test_render_p1()
{
    for(int i = 0; i < 10; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < 10; j++)
        {
            if(player1_map[i][j] == 0)
            {
                cout << "? ";
            }
            else if(player1_map[i][j] == 1)
            {
                cout << "* ";
            }
            cout << "\x1b[0m";
        }
        cout << endl;
    }
}

    // int x = (int) shipStart[0];
    //int y = (int) shipStart[1];

void place_ship_player1(int shipNumber)
{
    string shipStart;
    int direction;
    cout << "Czy statek ma byc w pionie (1), czy w poziomie (2): ";
    cin >> direction;
    cout << "Gdzie ma byc pocztek statku: ";
    cin >> shipStart;
    cout << endl;
    int x = (int) shipStart[0];
    cout << x << " " <<  shipStart[1] << endl;
    if(4 + shipNumber > 9)
    {
        cout << 4 + shipNumber << endl;
        cout << "Poza zakresem" << endl;
    }
    else
    {
        player1_map[0][0] = 1;
    }
    test_render_p1();
}

void render_map_player1()
{
    cout << "     PLAYER 1 TURN" << endl;
    cout << "Masz do dysposycji: " << endl;
    cout << "* Jeden statek dwupoziomowy (2)" << endl;
    cout << "* Jeden statek trzypoziomowy (3)" << endl;
    cout << "* Jeden statek czteropoziomowy (4)" << endl;
    cout << "* Jeden statek pieciopoziomowy (5)" << endl;
    cout << "   A B C D E F G H I J" << endl;
    for(int i = 1; i < 10; i++)
>>>>>>> 62ce2b0864c2d703cd0f8d6727e9b61ec402b389
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
<<<<<<< HEAD
                cout << "\x1b[48:5:244m  \x1b[0m";
            }
            else if (unknown[i][j] == 2)
            {
                cout << "\x1b[48:5:244m  \x1b[0m";
            }
            else if (unknown[i][j] == 3)
            {
                    cout << "??";
=======
                cout << "? ";
            }
            else if(player1_map[i][j] == 1)
            {
                cout << "* ";
>>>>>>> 62ce2b0864c2d703cd0f8d6727e9b61ec402b389
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
<<<<<<< HEAD
                for(int j=0; j < elements; j++)
                {
                        if(matrix[i][j] == 1)
                        c++;
                }
        }
 
        return c;
=======
            cout << "Podaj statek, jak chcesz umiescic: ";
            cin.clear();
        };
        place_ship_player1(choose);
    }
>>>>>>> 62ce2b0864c2d703cd0f8d6727e9b61ec402b389
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