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
  cout << " k, n, p: ";
  int exponent;
  cin >> exponent;
  int128 n;
  cin >> n;
  long p;
  cin >> p;

  makeprimelist(pow(n,1.0/exponent));

  int128 sum=0;
  bool adding=false;
  cout << n << "=";
  for(int i=0; i<primelen; i++)
  {
    if(p==prime[i]) adding=true;
    if(adding)
    {
      cout << prime[i] << "^" << exponent<<"+";
      sum+= power(prime[i],exponent);
      if(sum>=n) break;
    }
  }
  cout << endl;
  if(sum!=n) cout << "Error - sums don't match\n";


  return 0;
}



