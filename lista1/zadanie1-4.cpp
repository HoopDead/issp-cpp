#include <iostream>

using namespace std;


void test_coursor()
{
    cout << "\x1b[2J"; 
    cout << "\x1b[1;0H ** \x1b[1;11H **";
    cout << "\x1b[2;0H * \x1b[2;1H * \x1b[2;4H ** \x1b[2;8H ** \x1b[2;12H *";
    cout << "\x1b[3;0H * \x1b[3;6H ** \x1b[3;12H *";
    cout << "\x1b[4;0H * \x1b[4;12H *" << endl;
}


int main()
{
    cout << "\x1b[2J";
    cout << "\x1b[44m**        ** \x1b[0m  \x1b[45m****** \x1b[0m" << endl;
    cout << "\x1b[44m*  **  **  * \x1b[0m  \x1b[45m*    * \x1b[0m" << endl;
    cout << "\x1b[44m*    **    * \x1b[0m  \x1b[45m****** \x1b[0m" << endl;
    cout << "\x1b[44m*          * \x1b[0m  \x1b[45m* \x1b[0m" << endl;
    cout << "\x1b[44m*          * \x1b[0m  \x1b[45m* \x1b[0m" << endl;
    cout << "\x1b[0m";
    return 0;
}