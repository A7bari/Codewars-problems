#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

using ull = unsigned long long;
ull f(vector<vector<ull>> &tab, int k, int n)
{
  if (n == 0 && k == 0)
  {
    return 1;
  }
  else if (k <= 0 || n <= 0)
  {
    return 0;
  }
  else if (k > n)
  {
    return 0;
  }
  else
  {

    return tab[k][n - k] + tab[k - 1][n - 1];
  }
}
ull exp_sum(unsigned int n)
{
  ull result = 0;
  int taille = n + 1;
  vector<vector<ull>> res(taille, vector<ull>(taille, 1));

  for (int nn = 0; nn <= n; nn++)
  {
    for (int k = 0; k <= n; k++)
    {

      res[k][nn] = f(res, k, nn);
    }
  }
  for (int i = 0; i < n + 1; i++)
  {
    result += res[i][n];
  }
  return result;
}