#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define TEST 0

// This table has the number of operations needed to achieve n
int result_table[1000000] = {0};
// This table has the actual intermediate values through which n is reached
int result_table2[1000000] = {0};

int min(int a, int b, int c, int d)
{
  int min = a;
  int num[4] = {a, b, c, d};
  for(int i = 0; i < 4; ++i)
  {
    if(num[i] < min)
    {
      min = num[i];
    }
  }
  return min;
}

int solve_recursive(int n)
{
  int min_ops = INT_MAX, n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MAX;
  if (n <= 1)
  {
    return 0;
  }
  if(result_table[n] != 0)
  {
    return result_table[n];
  }
  if(n % 3 == 0)
  {
    n3 = solve_recursive(n / 3) + 1;
  }
  if(n % 2 == 0)
  {
    n2 = solve_recursive(n / 2) + 1;
  }
  if(n >= 1)
  {
    n1 = solve_recursive(n - 1) + 1;
  }
  min_ops = min(n1, n2, n3, min_ops);
  result_table[n] = min_ops;
  return min_ops;
}

int solve(int n)
{
  result_table[0] = 0;
  result_table[1] = 0;
  for(int i = 2; i <= n; ++i)
  {
    int n1 = INT_MAX, n2 = INT_MAX, n3 = INT_MAX;
    result_table[i] = INT_MAX;
    if(i % 3 == 0)
    {
      n3 = result_table[i / 3] + 1;
    }
    if(i % 2 == 0)
    {
      n2 = result_table[i / 2] + 1;
    }
    if(i > 1)
    {
      n1 = result_table[i - 1] + 1;
    }
    result_table[i] = min(n1, n2, n3, result_table[i]);
  }
  // Now calculate the path
  result_table2[0] = n;
  for(int i = n, j = 1; i > 1;)
  {
    if(i % 3 == 0)
    {
      if(result_table[i] - 1 == result_table[i / 3])
      {
        i = i / 3;
        result_table2[j] = i;
        ++j;
        continue;
      }
    }
    if(i % 2 == 0)
    {
      if(result_table[i] - 1 == result_table[i / 2])
      {
        i = i / 2;
        result_table2[j] = i;
        ++j;
        continue;
      }
    }
    if(i >= 1)
    {
      if(result_table[i] - 1 == result_table[i - 1])
      {
        i = i - 1;
        result_table2[j] = i;
        ++j;
        continue;
      }
    }
    else
    {
      printf("Should never reach here\n");
      exit(1);
    }
  }
  return result_table[n];
}

int test()
{
}

int main()
{
  int n = 0, res = 0;
#if TEST == 0
  res = scanf("%d", &n);
  res = solve(n);
  printf("%d\n", res);
  for(int i = res; i >= 0; --i)
  {
    printf("%d ", result_table2[i]);
  }
#else
  test();
#endif
  return 0;
}
