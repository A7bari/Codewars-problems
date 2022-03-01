#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <cmath>

using namespace std;

bool is_interval(vector<int> &args, int indice, int &size)
{
  if (indice >= size - 2)
  {
    return false;
  }
  if (args[indice] + 1 == args[indice + 1] && args[indice] + 2 == args[indice + 2])
  {
    return true;
  }
  return false;
}
std::string range_extraction(std::vector<int> args)
{
  int size = args.size();
  string result = "";
  for (int i = 0; i < size; i++)
  {
    if (is_interval(args, i, size))
    {
      if (i != 0)
      {
        result += ",";
      }
      result += to_string(args[i]);
      while ((i < size - 1) && (args[i] + 1 == args[i + 1]))
      {
        i++;
      }
      result += "-" + to_string(args[i]);
    }
    else
    {
      if (i == 0)
      {
        result += to_string(args[i]);
      }
      else
      {
        result += "," + to_string(args[i]);
      }
    }
  }
  return result;
}