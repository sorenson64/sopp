#include <iostream>
#include <iomanip>

#include "ssp.h"

using namespace std;

int main()
{
  for(double x=1000; x<=1e15; x*=10)
  {
    int128 limit=x;
    long actual=ssp(limit);
    double est=estimate(x);

    cout << "x="<<x
	    << setw(12)<< actual << setw(12) << est << setw(10) <<
	    actual/est << endl;
  }
}
