#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

#include "dups.h"

int main()
{
  for(double x=1000; x<=1e15; x*=10)
  //double x=1000;
  {
    int128 limit=x;
    long firstcount=sopp(2,limit);
    cout << limit << " " << firstcount <<" "<<sopp2(2,limit)<<endl;

    cout << endl;

    int128 xlow=0;
    int128 xhigh=xlow+x/10;
    int128 countsum=0;
    while(xlow<xhigh)
    {
      int128 thiscount=sopp3(2,xlow,xhigh);
      countsum+=thiscount;
      cout << "--> " << xlow << " " << xhigh << " " << thiscount << endl;
      xlow=xhigh+1;
      xhigh+=x/10;
      if(xhigh>limit) xhigh=limit;
    }
    cout << countsum << endl;
  }
}
