#include <iostream>
#include <unistd.h>
#include <climits>
#include <stdlib.h>


using namespace std;



int menu(int arg)
{
    if (arg == 2)
    {
        cout << "RULES" << endl;
    }
}


int main()
{
    srand(time(NULL));
    int x, level = 1, attempt = 1, arg, choose;
    int randomNumber = rand()%(level*5-1 + 1) + 1;
    cout << " ##############################################################" << endl;
    cout << " #                                                            #" << endl;
    cout << " #                 #    #  ##### ###### ######                #" << endl;
    cout << " #                 # #  #  #   # #    # #     #               #" << endl;
    cout << " #                 #  # #  ##### ###### #     #               #" << endl;
    cout << " #                 #   ##  # #   #    # #     #               #" << endl;
    cout << " #                 #    #  #  #  #    # ######                #" << endl;
    cout << " #                                                            #" << endl;
    cout << " ##############################################################" << endl;
    cout << "                              === Menu ===                         " << endl;
    cout << "                             1. Zacznij gre                    " << endl;
    cout << "                  2. Informacje o grze i zacznij gre   " << endl;
    cout << "\x1b[94m[Menu]\x1b[0m Wybierz opcje: ";
    cin >> arg;
    menu(arg);
    for(;;)
    {
        cout << "\x1b[94m[?]\x1b[0mPodaj liczbe: ";
        while(!(cin>>x))
        {
        cout << "\x1b[94m[!]\x1b[0mPodaj liczbe: ";
            cin.clear();
            cin.ignore(INT_MAX,'\n');
        }
        if(x == randomNumber)
        {
            cout << "\x1b[93mUdalo Ci sie po \x1b[0m" << attempt << " \x1b[93mprobach!\x1b[0m" << endl;
            cout << "\x1b[94m[?]\x1b[0mCzy kontynuowac? (1 - tak; 2 - nie): ";
            cin >> choose;
            if(choose == 2)
            {
                break;
            }
            else
            {
                level = level + 5;
                x = 0; attempt = 1;
                randomNumber = rand()%(level*3-1 + 1) + 1;
                cout << "\x1b[94m[!]\x1b[0mLosuje z przedzialu " << 3*level << endl;
            }
        }
        else
        {
            attempt++;
        }

        }
    return 0;
    }

