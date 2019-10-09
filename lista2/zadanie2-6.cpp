#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



void create_leaves()
{
	int i, j;
	int whitespace = 10;
   	int rows = 1;

	for(j = 1; j <= 10; j++)
	{
	   for(i = 1; i <= whitespace; i++)
	   {
	      cout << " ";
	   }
	whitespace--;

	   for(i = 1; i <= rows; i++)
	   {
		  if(i%3 == 0)
		  {
		  	cout << "\x1b[33mo";
		  }
		  else
		  {
		 	 cout << "\x1b[32m#";
		  }
	   }
	   rows += 2;

	   cout << endl;
	}
}

void create_root()
{
	for(int j = 0; j < 3; j++)
	{
		for(int i = 0; i < 8; i++)
		{
			cout << " ";
		}
		cout << "\x1b[38;5;214m%%%%" << endl;
	}
}

int main()
{
	create_leaves();
	create_root();
   cout << "\x1b[0m";
}
