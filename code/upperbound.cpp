#include<iostream>
#include<cmath>
using namespace std;

int main()
{
/*
  for(int k=2; k<=25; k++)
  {
    double B;
    B = powl((7.0/6.0)*powl(8.856,1.0/(k+1)), (k-1.0)/k );
    cout << "k="<< k << " B="<<B << endl;
  }
*/

  cout << " ============= " << endl;

  for(int k=2; k<=10000; k++)
  {
    double A;
    A = k*k/((k-1)*(k-1)) * (k+1) * powl( k+1, (k-1.0)/k );
    cout << "k="<< k << " A="<<A << " A/(k+1)^2=" << A/((k+1)*(k+1)) << endl;
  }

  return 0;
}

