#include <iostream>
#include <cmath>

long properFractions(long n)
{
  if (n == 1)
    return 0;

  long compt = n, fac = n;

  for (int i = 2; i <= sqrt(fac); i++)
  {
    if (fac % i == 0)
    {
      compt = (compt / i) * (i - 1);
      while (fac % i == 0)
      {
        fac = fac / i;
      }
    }
  }

  if (fac > 1)
  {
    compt = compt - compt / fac;
  }

  return compt;
}