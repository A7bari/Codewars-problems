#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

std::string format_duration(int seconds)
{
  if (seconds == 0)
  {
    return "now";
  }
  vector<int> results(5, 0);
  string units[5] = {"year", "day", "hour", "minute", "second"};
  int div[4] = {60, 60, 24, 365};
  vector<string> formats;
  for (int i = 0; i < 4 && seconds != 0; i++)
  {
    results[i] = seconds % div[i];
    seconds /= div[i];
  }
  results[4] = seconds;

  for (int i = 0; i < 5; i++)
  {

    if (results[i] == 0)
      continue;
    string format = "";
    format += to_string(results[i]) + " " + units[4 - i];
    if (results[i] > 1)
      format += "s";
    formats.push_back(format);
  }
  int size = formats.size();
  string res = "";
  for (int i = size - 1; i >= 0; i--)
  {
    res += formats[i];
    if (i == 1)
    {
      res += " and ";
    }
    else if (i == 0)
    {
      continue;
    }
    else
    {
      res += ", ";
    }
  }

  return res;
}