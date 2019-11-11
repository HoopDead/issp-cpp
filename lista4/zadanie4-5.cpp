#include <iostream>
#include <ofstream>
using namespace std;

void createDoc(int number)
{

}

long long fibonnaci(int x) 
{
   if((x==1)||(x==0)) {
      return(x);
   }
   else 
   {
      return(fibonnaci(x-1)+fibonnaci(x-2));
   }
}
int main() {
   int x , i=0;
   cout << "Wprowadz ilosc liczb: " << endl;
   cin >> x;
   cout << "Kolejne liczby ciagu Fibonnaciego : ";
   while(i < x) {
      cout << " " << fibonnaci(i) << " ";
      i++;
   }
   cout << endl;
   return 0;
}