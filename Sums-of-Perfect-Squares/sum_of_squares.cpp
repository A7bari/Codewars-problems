#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> sqr(int n)
{
  std::vector<int> tab;
  int it = 1, multi = 1;

  while (multi <= n)
  {
    tab.push_back(multi);
    it++;
    multi = it * it;
  }
  return tab;
}

int sum_of_squares(int n);
int rec(std::vector<int> &arr, int n, int size)
{
  if (n < 4)
  {
    return n;
  }
  else
  {
    int compt = (int)n / arr[size];
    return compt + sum_of_squares(n % arr[size]);
  }
}

int sum_of_squares(int n)
{
  if (n < 4)
  {
    return n;
  }
  else
  {
    std::vector<int> arr = sqr(n);
    int size = arr.size();
    int array[6];
    array[0] = rec(arr, n, size - 1);
    int min = array[0];
    for (int i = 1; i < size && i < 6; i++)
    {
      array[i] = rec(arr, n, size - i - 1);
      if (min > array[i])
      {
        min = array[i];
      }
    }

    return min;
  }
}