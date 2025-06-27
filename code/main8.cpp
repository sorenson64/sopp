#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

#include "dups.h"

int main()
{
  int k=2;
  //for(double x=1000; x<=1e15; x*=10)
  double x=1e18;
  double xstart=1e15;
  double xdelta=1e15;
  {
    int128 limit=x;
    //long firstcount=sopp(k,limit);
    //cout << limit << " k="<<k<<" " << firstcount <<" "<<sopp2(k,limit)<<endl;

    cout << endl;

    int dupcount=0;

    int128 xlow=xstart;
    int128 xhigh=xlow+xdelta;
    int128 countsum=0;
    vector<int128> list;
    while(xlow<xhigh)
    {
      list.resize(0);
      int128 thiscount=sopp3gen(k,xlow,xhigh,list);
      countsum+=thiscount;
      //cout << "--> " << xlow << " " << xhigh << " " << thiscount << endl;
      xlow=xhigh+1;
      //xhigh+=x/10;
      xhigh+=xdelta;
      if(xhigh>limit) xhigh=limit;
      //cout << "Duplicates:" << endl;
      dupcount+=dups(list);
    }
    cout << countsum << endl;
    cout << "dups  " << dupcount << " x="<< x<<endl;
  }
  return 0;
}
