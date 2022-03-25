#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef unsigned long long ull;
class SumFct
{
public:
  static ull perimeter(int n)
  {
    ull *f = new ull[n + 2];

    f[0] = 1;
    f[1] = 1;
    ull somme = 2;
    for (int i = 2; i <= n; i++)
    {
      f[i] = f[i - 1] + f[i - 2];
      somme += f[i];
    }
    return 4 * somme;
  }
};