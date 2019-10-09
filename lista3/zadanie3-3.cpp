#include <iostream>

using namespace std;

int main()
{
    long long x, ans = 1;
    cout<< "Podaj liczbe: ";
    cin >> x;
    for(int i = 1; i <= x; i++)
    {
        ans *= i;
    }
    cout << "Silnia z " << x << " to " << ans << endl;
    return 0;
}
//Program nie daje rady przy 40 - wyjaśnienie TO-DO.