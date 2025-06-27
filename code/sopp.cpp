#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "primelist.h"
#include "bigint.h"

using namespace std;

int128 power(int base, int exp)
{
  int128 answer=1;
  int128 x=base;
  while(exp>0)
  {
    if(exp%2==1) // exp is even
      answer*=x;
    x=x*x;
    exp=exp/2;
  }
  return answer;
}

int main()
{
  int128 limit;
  double lim;
  cin >> lim;
  limit=lim;
  int exponent;
  cin >> exponent;

  makeprimelist(powl(limit,1.0/exponent));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+power(prime[i],exponent);

  for(long bottom=0; bottom<primelen; bottom++)
    for(long top=bottom+1; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>limit) break;
      else  cout << next << "                " << prime[bottom] << endl;
    }

  delete [] prefix;

  return 0;
}

