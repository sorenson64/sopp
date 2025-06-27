#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

int main()
{
  for(double x=1000; x<=1e15; x*=10)
  {
    int128 limit=x;
    cout << limit << " " << sopp(2,limit) <<" "<<sopp2(2,limit)<<endl;
  }
}
