#include <iostream>
#include <vector>
#include <string>


using namespace std;


int water = 0;
int ship = 1;
int hit = 2;
int miss = 3;

int player1_map[10][10];
int player2_map[10][10];

vector <int> player1_ships;
vector <int> player2_ships;


void init_game()
{
    for(int i = 1; i < 7; i++)
    {
        player1_ships.push_back(i);
        player2_ships.push_back(i);
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            player1_map[i][j] = 0;
            player2_map[i][j] = 0;
        }
    }
}

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
    {
        cout << i << "  ";
        for (int j = 1; j < 11; j++)
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
    for(int i = 0; i < 2; i++)
    {
        int choose;
        cout << "Podaj statek, jak chcesz umiescic: ";
        while(! (cin>>choose) )
        {
            cout << "Podaj statek, jak chcesz umiescic: ";
            cin.clear();
        };
        place_ship_player1(choose);
    }
}

int main()
{
    init_game();
    render_map_player1();
    cout << "\x1b[0m ";
    return 0;
}