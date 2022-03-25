#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class DoubleLinear
{
public:
  static int dblLinear(int n)
  {
    vector<int> u = {1};
    int comptz = 0, compty = 0, t = 0;
    int s = 0;
    for (int i = 0; i < n + t; i++)
    {
      int u1 = 3 * u[comptz] + 1;
      int u2 = 2 * u[compty] + 1;

      if (u1 < u2)
      {
        u.push_back(u1);
        comptz++;
      }
      else if (u1 > u2)
      {
        u.push_back(u2);
        compty++;
      }
      else
      {
        u.push_back(u2);
        compty++;
        comptz++;
        t++;
      }
    }

    return u[n];
  }
};