#include <iostream>
#include <iomanip>
#include <fstream>

#include "sopp.h"

using namespace std;

#include "dups.h"

int main()
{
  //for(double x=1000; x<=1e15; x*=10)
  //int k=3;
  double xstart=0;
  double xdelta=1e15;
  double x=1e18;
  {
    int128 limit=x;
    //long firstcount=sopp(k,limit);
    //cout << limit << " " << firstcount <<" "<<sopp2(k,limit)<<endl;

    //cout << endl;

    int dup23count=0;
    int dup24count=0;
    int dup25count=0;

    ofstream out3("dups23-1e18.txt");
    ofstream out4("dups24-1e18.txt");
    ofstream out5("dups25-1e18.txt");

    int128 xlow=xstart;
    int128 xhigh=xlow+xdelta;
    int128 countsum2=0;
    int128 countsum3=0;
    int128 countsum4=0;
    int128 countsum5=0;
    vector<int128> list2, list3, list4, list5;
    while(xlow<xhigh)
    {
      list2.resize(0);
      list3.resize(0);
      list4.resize(0);
      list5.resize(0);
      int128 thiscount2=sopp3gen(2,xlow,xhigh,list2);
      int128 thiscount3=sopp3gen(3,xlow,xhigh,list3);
      int128 thiscount4=sopp3gen(4,xlow,xhigh,list4);
      int128 thiscount5=sopp3gen(5,xlow,xhigh,list5);
      countsum2+=thiscount2;
      countsum3+=thiscount3;
      countsum4+=thiscount4;
      countsum5+=thiscount5;
      //cout << "--> " << xlow << " " << xhigh << " 2:" << thiscount2
//	     << " k:"<<thiscountk << endl;
      xlow=xhigh+1;
      xhigh+=xdelta;
      if(xhigh>limit) xhigh=limit;
     // cout << "Duplicates:";
      dup23count+=dups(list2,list3,out3);
      dup24count+=dups(list2,list4,out4);
      dup25count+=dups(list2,list5,out5);
  out3.flush();
  out4.flush();
  out5.flush();
      //cout << endl;
    }
    //cout << "2:"<< countsum2 << " k:"<<countsumk << endl;
    //cout << "dups 2:k " << dupcount << " x="<< x<<endl;
  out3.close();
  out4.close();
  out5.close();
  }
  return 0;
}
