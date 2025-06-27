
#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;


int main()
{
  int128 n;
  while(!cin.eof())
  {
    cin >> n;
    cout << n << endl;
    for(int k=2; k<=20; k++)
	  exact(k,n);
  }
  return 0;
}
