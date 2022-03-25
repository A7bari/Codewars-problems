#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class RomanHelper
{

public:
  vector<vector<string>> tab = {{"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"M", "MM", "MMM"}};

  std::string to_roman(unsigned int n)
  {
    vector<string> roman;
    string r = "";

    for (int i = 0; i < 4; i++)
    {
      if (n % 10 != 0)
      {
        roman.push_back(tab[i][(n % 10) - 1]);
      }
      n = n / 10;
    }
    reverse(roman.begin(), roman.end());
    for (unsigned int i = 0; i < roman.size(); i++)
    {
      r += roman[i];
    }
    return r;
  }

  int from_roman(std::string rn)
  {
    int res = 0;
    vector<string> rnParse = parseRoman(rn);

    for (unsigned int i = 0; i < rnParse.size(); i++)
    {
      int multiple = 1;
      for (int j = 0; j < 4; j++)
      {

        auto it = find(tab[j].begin(), tab[j].end(), rnParse[i]);
        if (it != tab[j].end())
        {
          int index = it - tab[j].begin();
          // cout << index << "  "<< rnParse[i]<<endl;
          res += (index + 1) * multiple;
          break;
        }
        multiple *= 10;
      }
    }
    return res;
  }

  vector<string> parseRoman(string &rn)
  {
    vector<string> res;
    string temp = "";
    for (unsigned int i = 0; i < rn.size() - 1; i++)
    {
      temp += rn.at(i);
      if (!next(temp, rn.at(i + 1)))
      {
        res.push_back(temp);
        temp = "";
      }
    }
    temp += rn.at(rn.size() - 1);
    res.push_back(temp);
    reverse(res.begin(), res.end());
    return res;
  }
  bool next(string &f, char n)
  {
    char first = f.at(0);

    switch (first)
    {
    case 'I':
      if (n == 'I' || n == 'V' || n == 'X')
      {
        return true;
      }
      else
        return false;
      break;
    case 'V':
      if (n == 'I')
      {
        return true;
      }
      else
        return false;
      break;
    case 'X':
      if (n == 'X' || n == 'L' || n == 'C')
      {
        return true;
      }
      else
        return false;
      break;
    case 'L':
      if (n == 'X')
      {
        return true;
      }
      else
        return false;
      break;
    case 'C':
      if (n == 'C' || n == 'D' || n == 'M')
      {
        return true;
      }
      else
        return false;
      break;
    case 'D':
      if (n == 'C')
      {
        return true;
      }
      else
        return false;
      break;
    case 'M':
      if (n == 'M')
      {
        return true;
      }
      else
        return false;
      break;
    default:
      return false;
      break;
    }
  }
} RomanNumerals;