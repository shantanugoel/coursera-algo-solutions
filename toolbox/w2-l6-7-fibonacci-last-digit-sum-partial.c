#include <stdio.h>

#define TEST 0

/*
 * This program is basically a special case where we sum the mod 10 of
 * fibonacci numbers. Pisano period specifies the period after which this sum
 * repeats. We calculated offline (or can also add it in the program) the
 * pisano period for m = 10.
 */
#define PISANO_PERIOD 60

int sum(unsigned long long n)
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

/*
 * Since we are required to find the sum of a range, we can just find the
 * impact that the lower excluded range causes to the overall sum. So, we
 * calcualted the lower range (m -1)'s sum and subtract it from the total
 * upper range. Note that the lower range's impact may cause a carry over to
 * the total sum. So, we need to add 10 and take a modulus of 10 to be able to
 * get the correct result.
 */
int solve(unsigned long long m, unsigned long long n)
{
  return (10 + sum(n) - sum(m - 1)) % 10;
}

int test()
{
}

int main()
{
  unsigned long long n = 0, m = 0;
  int res = 0;
#if TEST == 0
  res = scanf("%llu %llu", &m, &n);
  printf("%d", solve(m, n));
#else
  test();
#endif
  return 0;
}
