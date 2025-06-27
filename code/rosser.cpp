#include<iostream>
#include<cmath>
using namespace std;

int main()
{
  for(int n=2; n<100; n++)
  {
    cout << n << "\t";
    cout << n*log(n) << "\t";
    cout << n*(log(n) +  log(log(n))) << "\t";
    cout << 1.5*n*log(n) << "\t";
    cout << endl;
  }
}

