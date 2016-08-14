#include <stdio.h>

#define TEST 0

int solve(int a, int b)
{
  int c = a % b;
  if(c != 0)
  {
    return solve(b, c);
  }
  return b;
}

int test()
{
}

int main()
{
  int a = 0, b = 0, res = 0;
#if TEST == 0
  res = scanf("%d %d", &a, &b);
  printf("%d", solve(a, b));
#else
  test();
#endif
  return 0;
}
