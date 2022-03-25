#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

std::vector<std::string> get_pins(std::string observed)
{
  vector<string> res;
  vector<vector<string>> ref = {{"0", "8"}, {"1", "2", "4"}, {"2", "1", "5", "3"}, {"3", "2", "6"}, {"4", "1", "5", "7"}, {"5", "2", "6", "8", "4"}, {"6", "3", "5", "9"}, {"7", "4", "8"}, {"8", "5", "7", "9", "0"}, {"9", "6", "8"}};
  for (char it : observed)
  {
    int f = atoi(&it);
    if (res.size() == 0)
    {
      res = ref[f];
    }
    else
    {
      vector<string> newres;
      for (unsigned int i = 0; i < res.size(); i++)
      {
        for (unsigned int j = 0; j < ref[f].size(); j++)
        {
          newres.push_back(res[i] + ref[f][j]);
        }
      }

      res = newres;
    }
  }

  return res;
}