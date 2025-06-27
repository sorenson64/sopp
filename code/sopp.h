#ifndef _SOPP
#define _SOPP


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

long sopp(int exponent, int128 limit)
{
  long count=0;

  makeprimelist(pow(limit,1.0/exponent));

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
      //else  cout << next << "                " << prime[bottom] << endl;
      count++;
    }

  delete[] prefix;

  return count;
}

long sopp2(int exponent, int128 limit)
{
  long count=0;

  makeprimelist(pow(limit,1.0/exponent));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+power(prime[i],exponent);

  long top=0;
  while(top<primelen && prefix[top+1]<=limit) top++;

  for(long bottom=0; bottom<primelen; bottom++)
    {
      if(top<primelen && 
        prefix[top+1]-prefix[bottom]<=limit) top++;
      count+=top-bottom;
    }

  delete[] prefix;

  return count;
}

long sopp3(int exponent, int128 xlow, int128 xhigh)
{
  long count=0;

  makeprimelist(pow(xhigh,1.0/exponent));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+power(prime[i],exponent);

  long topstart=1;
  for(long bottom=0; bottom<primelen; bottom++)
  {
    while(topstart<=primelen && topstart<=bottom) 
      topstart++;
    while(topstart<=primelen && prefix[topstart]-prefix[bottom]<xlow) 
      topstart++;
    for(long top=topstart; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>xhigh) break;
      //else  cout << next << "                " << prime[bottom] << endl;
      count++;
    }
  }

  delete[] prefix;

  return count;
}

long sopp3gen(int exponent, int128 xlow, int128 xhigh, vector<int128> & list)
{
  long count=0;

  makeprimelist(pow(xhigh,1.0/exponent));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+power(prime[i],exponent);

  long topstart=1;
  for(long bottom=0; bottom<primelen; bottom++)
  {
    while(topstart<=primelen && topstart<=bottom) 
      topstart++;
    while(topstart<=primelen && prefix[topstart]-prefix[bottom]<xlow) 
      topstart++;
    for(long top=topstart; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>xhigh) break;
      else if(next>=xlow) { list.push_back(next); count++; }
      //else  cout << next << "                " << prime[bottom] << endl;
      //count++;
    }
  }
  delete[] prefix;

  return count;
}

void exact(int k, int128 n)
{
  makeprimelist(pow(n,1.0/k));

  int128 *prefix;
  prefix=new int128[primelen+1];
  prefix[0]=0;
  for(long i=0; i<primelen; i++)
    prefix[i+1]=prefix[i]+power(prime[i],k);

  long topstart=1;
  for(long bottom=0; bottom<primelen; bottom++)
  {
    while(topstart<=primelen && topstart<=bottom) 
      topstart++;
    while(topstart<=primelen && prefix[topstart]-prefix[bottom]<n) 
      topstart++;
    for(long top=topstart; top<=primelen; top++)
    {
      int128 next=prefix[top]-prefix[bottom];
      if(next>n) break;
      else if(next==n) { cout << "k="<<k<<" pb="<< prime[bottom] << endl; }
      //else  cout << next << "                " << prime[bottom] << endl;
      //count++;
    }
  }
}

int64_t findM(int128 x, int k)
{
  makeprimelist(pow(x,1.0/k));

  int128 sum=0;
  for(long i=0; i<primelen; i++)
  {
    sum+= power(prime[i],k);
    if (sum>x) return i;
  }
  return primelen;
}


double estimate(int k, int128 limit)
{
  double lim=limit;
  double ck;
  ck=(k*(k)) *powl( k+1, 1.0-1.0/k)/(k-1.0);
  return ck*powl(lim,2.0/(k+1.0)) / powl( logl(limit), 2.0*k/(k+1.0) );
}
double lower(int k, int128 limit)
{
  double lim=limit;
  double c;
  c=((k+1)*(k+1))/2.0;
  return c*powl(lim,2.0/(k+1.0)) / powl( logl(limit), 2.0*k/(k+1.0) );
}

#endif
