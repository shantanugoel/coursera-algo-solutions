#include <stdio.h>

#define TEST 0

int candies[1000000000] = {0};

/*
 * Strategy followed here is that we "try to take" the lowest possible number of
 * candies from the available pool. Check if the remaining pool after this
 * number is taken is large enough to take for the next round. If yes, then
 * take this number, reduce the pool by the same number and continue for next
 * round. If the remaining pool is not large enough, then take all the
 * remaining candies, otherwise we won't be able to create a "distinct" number
 * pool.
 */
int solve(int n)
{
  int k = 0;
  for(int i = 1; i <= n; ++i)
  {
    if(((n - i) > i) || (n == i))
    {
      n -= i;
      candies[k] = i;
      ++k;
    }
  }
  return k;
}

int test()
{
}

int main()
{
  int n = 0, res = 0, k =0;
#if TEST == 0
  res = scanf("%d", &n);
  k = solve(n);
  printf("%d\n", k);
  for(int i = 0; i < k; ++i)
  {
    printf("%d ", candies[i]);
  }
#else
  test();
#endif
  return 0;
}
