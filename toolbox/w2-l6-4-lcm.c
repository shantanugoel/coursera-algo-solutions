#include <stdio.h>

#define TEST 0

int gcd(int a, int b)
{
  int c = a % b;
  if(c != 0)
  {
    return gcd(b, c);
  }
  return b;
}

unsigned long long solve(int a, int b)
{
  int g = 0;
  unsigned long long lcm = 0;
  g = gcd(a, b);
  lcm = (unsigned long long)a *(unsigned long long)b / g;
  return lcm;
}

int test()
{
}

int main()
{
  int a = 0, b = 0, res = 0;
#if TEST == 0
  res = scanf("%d %d", &a, &b);
  printf("%llu", solve(a, b));
#else
  test();
#endif
  return 0;
}
