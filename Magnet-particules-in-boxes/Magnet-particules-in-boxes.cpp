#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Magnets
{
public:
  static double doubles(int maxk, int maxn)
  {
    double u = 0;
    for (int k = 1; k <= maxk; k++)
    {
      double v = 0;
      for (int n = 1; n <= maxn; n++)
      {
        v += pow(n + 1, -2 * k);
      }
      u += ((double)1 / k) * v;
    }
    return u;
  }
};