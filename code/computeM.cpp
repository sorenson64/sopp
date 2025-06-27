#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

#include "dups.h"

int main()
{
  for(int k=2; k<6; k++)
  for(double x=1e12; x<1e17; x*=10)
  {
    cout << x <<" "<<k<<" "<<findM(x,k)<<endl;
  }
}
