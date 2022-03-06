#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map)
{
  int n = snail_map[0].size(), n2 = n * n;
  vector<int> res;

  int row = 0, column = -1, compt = 0, compt2 = 0;
  while (compt < n2)
  {
    int i;
    for (i = column + 1; i < n - compt2; i++)
    {
      res.push_back(snail_map[row][i]);
      compt++;
    }
    column = i - 1;
    for (i = row + 1; i < n - compt2; i++)
    {
      res.push_back(snail_map[i][column]);
      compt++;
    }
    row = i - 1;

    for (i = column - 1; i >= compt2; i--)
    {
      res.push_back(snail_map[row][i]);
      compt++;
    }
    column = i + 1;
    for (i = row - 1; i >= compt2 + 1; i--)
    {
      res.push_back(snail_map[i][column]);
      compt++;
    }
    row = i + 1;
    compt2++;
  }

  return res;
}