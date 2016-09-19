#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TEST 0

int result_table_min[15][15];
int result_table_max[15][15];
char ops[14];


int minimum(int num[], int n)
{
  int min = INT_MAX;
  for(int i = 0; i < n; ++i)
  {
    if(num[i] < min)
    {
      min = num[i];
    }
  }
  return min;
}

int maximum(int num[], int n)
{
  int max = INT_MIN;
  for(int i = 0; i < n; ++i)
  {
    if(num[i] > max)
    {
      max = num[i];
    }
  }
  return max;
}

int do_op(char op, int a, int b)
{
  int result = 0;
  switch(op)
  {
    case '+':
      result = a + b;
      break;
    case '-':
      result = a - b;
      break;
    case '*':
      result = a * b;
      break;
  }
  return result;
}

void min_and_max(int i, int j)
{
  int num[4] = {0};
  int min = 0, max = 0;
  result_table_min[i][j] = INT_MAX;
  result_table_max[i][j] = INT_MIN;
  for(int k = i; k < j; ++k)
  {
    num[0] = do_op(ops[k], result_table_max[i][k], result_table_max[k + 1][j]);
    num[1] = do_op(ops[k], result_table_max[i][k], result_table_min[k + 1][j]);
    num[2] = do_op(ops[k], result_table_min[i][k], result_table_max[k + 1][j]);
    num[3] = do_op(ops[k], result_table_min[i][k], result_table_min[k + 1][j]);
    min = minimum(num, 4);
    max = maximum(num, 4);
    if(min < result_table_min[i][j])
    {
      result_table_min[i][j] = min;
    }
    if(max > result_table_max[i][j])
    {
      result_table_max[i][j] = max;
    }
  }
}

int solve(char input[], int n)
{
  int digits[15];
  int len_digits = 0, len_ops = 0;
  for(int i = 0; i < n; ++i)
  {
    if(i % 2 == 0)
    {
      digits[len_digits++] = (int) (input[i] - '0');
    }
    else
    {
      ops[len_ops++] = input[i];
    }
  }
  for(int i = 0; i < len_digits; ++i)
  {
    result_table_min[i][i] = digits[i];
    result_table_max[i][i] = digits[i];
  }
  for(int s = 1; s <= len_digits - 1; ++s)
  {
    for(int i = 0; i <= len_digits - s - 1; ++i)
    {
      int j = i + s;
      if(i == j)
      {
        result_table_max[i][j] = digits[i];
        result_table_min[i][j] = digits[i];
      }
      else
      {
        min_and_max(i, j);
      }
    }
  }
  return result_table_max[0][len_digits - 1];
}

int test()
{
}

int main()
{
  int n = 0, res = 0, len = 0;
  char input[30];
#if TEST == 0
  res = scanf("%s", input);
  len = strlen(input);
  printf("%d", solve(input, len));
#else
  test();
#endif
  return 0;
}
