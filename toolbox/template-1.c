#include <stdio.h>

#define TEST 0

int solve(int n)
{
}

int test()
{
}

int main()
{
  int n = 0, res = 0;
#if TEST == 0
  res = scanf("%d", &n);
  printf("%d", solve(n);
#else
  test();
#endif
  return 0;
}
