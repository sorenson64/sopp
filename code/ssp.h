#ifndef _SSP
#define _SSP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "primelist.h"
#include "bigint.h"

using namespace std;

long ssp(int128 limit)
{
  long count=0;

  makeprimelist(sqrt(limit));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+((int128)prime[i])*prime[i];

  for(long bottom=0; bottom<primelen; bottom++)
    for(long top=bottom+1; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>limit) break;
      //else  cout << next << "                " << prime[bottom] << endl;
      else count++;
    }

  delete[] prefix;

  return count;
}

double estimate(int128 limit)
{
  double lim=limit;
  return powl(lim,2.0/3.0) / powl( logl(limit), 4.0/3.0 );
}

#endif
