#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "primelist.h"
#include "bigint.h"

using namespace std;

int main()
{
  int128 limit;
  cin >> limit;

  makeprimelist(sqrt(limit));

  int128 prefix[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+((int128)prime[i])*prime[i];

  for(long bottom=0; bottom<primelen; bottom++)
    for(long top=bottom+1; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>limit) break;
      else  cout << next << "                " << prime[bottom] << endl;
    }

  return 0;
}

