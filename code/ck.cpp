#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

int main()
{
  int k;
  for(k=2; k<=25; k++)
  {
    double ck=k*k/(k-1.0) * powl( k+1, 1-1.0/k );
    double k2=(k+1)*(k+1);
    //cout <<k << " & "<< ck << " & " << k2 << "\\\\" << endl;
    //cout << "ck=" << ck << " (k+1)^2="<<k2 << " (k+1)^2/2="<< k2/2 << endl;
    cout << "ck=" << ck << "\t"<<k2 << "\t"<< k2/2 << endl;
  }

  return 0;
}
