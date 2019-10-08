#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    do{
        cout << i+1 <<": " << "Hello World!" << endl;
        i++;
    } while(i < 100);
    return 0;
}