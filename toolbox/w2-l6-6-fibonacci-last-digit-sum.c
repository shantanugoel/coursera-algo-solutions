#include <stdio.h>

#define TEST 0

/*
 * This program is basically a special case where we sum the mod 10 of
 * fibonacci numbers. Pisano period specifies the period after which this sum
 * repeats. We calculated offline (or can also add it in the program) the
 * pisano period for m = 10.
 */
#define PISANO_PERIOD 60

int solve(unsigned long long n)
{
  int a =0, b = 1, c = 1, d = 1;

  n = n % PISANO_PERIOD;
  if(n < 2)
  {
    return n;
  }
  for(int i = 2; i <= n; ++i)
  {
    c = (a + b) % 10;
    a = b;
    b = c;
    d = (d + c) % 10;
  }
  return d;
}

int test()
{
}

int main()
{
  unsigned long long n = 0;
  int res = 0;
#if TEST == 0
  res = scanf("%llu", &n);
  printf("%d", solve(n));
#else
  test();
#endif
  return 0;
}
