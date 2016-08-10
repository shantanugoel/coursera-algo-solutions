#include <stdio.h>

int euclid_gcd(int a, int b)
{
  int c = a % b;
  if(c != 0)
  {
    return euclid_gcd(b, c);
  }
  else
  {
    return b;
  }
}

int main()
{
  int a = 0, b =0, res = 0;
  res = scanf("%d %d", &a, &b);
  printf("%d", euclid_gcd(a, b));
  return 0;
}
