#include <iostream>
#include <iomanip>

#include "sopp.h"

using namespace std;

int main()
{
  int k;
  cin >> k;
  double start=1000;
  int log10x=3;
  double ck=k*k/(k-1.0) * powl( k+1, 1-1.0/k );
  if(powl(10,k)>start) {start=powl(10,k); log10x=k; }
//  cout << "%\\hline\n";
//  cout << " $x$ & $S_{" << k << "}(x)^*$ & $" 
//       << ck << " x^{2/" << (k+1) << "} / (\\log x)^{ "
//       << (2*k) <<"/"<<(k+1) << "}"
//       << "$ & $"
//       << (k+1)*(k+1)/2 << " x^{2/" << (k+1) << "} / (\\log x)^{ "
//       << (2*k) <<"/"<<(k+1) << "}"
//       << " $ & Ratio \\\\" << endl;
//  cout << "\\hline\n";
  for(double x=start;
    powl(x,1.0/k)<1e8 && estimate(k,x)<=1e9 && x<=1e38 ; 
      x*=10, log10x++)
  {
    int128 limit=x;
    long actual=sopp(k,limit);
    double est=estimate(k,x);
    double low=lower(k,x);

    //cout << "$10^{"<<log10x << "}$ & "<< actual << " & " << long(est) 
    //       << " & " << long(low)
	  //  << " & " << fixed <<
	  //  setprecision(2) << actual/est << " \\\\"<< endl;

    cout << x << "  " << actual << endl;
  }
//  cout << "\\hline\n";
  return 0;
}
