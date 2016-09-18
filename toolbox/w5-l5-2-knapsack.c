#include <stdio.h>
#include <stdlib.h>


int weights[301] = {0};
int result_table[301][10001] = {0};

void get_input(int n, int num[])
{
  int i =0, j =0;
  char ch = 0;
  char str[11];
  for(; i < n; ++i)
  {
    for(j = 0; j < 11; ++j)
    {
      str[j] = '\0';
    }

    j = 0;
    while(1)
    {
      ch = getchar();
      if( (ch == ' ') || (ch == '\n') )
      {
        num[i + 1] = atoi(str);
        break;
      }
      str[j] = ch;
      ++j;
    }
    if(ch == '\n')
    {
      break;
    }
  }
#if 0
  for(i = 0; i < n; ++i)
  {
    printf("%d ", num[i]);
  }
#endif
}


int solve(int n, int W)
{
  for(int i = 0; i <= n; ++i)
  {
    result_table[i][0] = 0;
  }
  for(int w = 0; w <= W; ++w)
  {
    result_table[0][w] = 0;
  }
  for(int i = 1; i <= n; ++i)
  {
    for(int w = 1; w <= W; ++w)
    {
      result_table[i][w] = result_table[i - 1][w];
      if(weights[i] <= w)
      {
        int val = result_table[i - 1][w - weights[i]] + weights[i];
        if((val <= w) && (val > result_table[i][w]))
        {
          result_table[i][w] = val;
        }
      }
    }
  }
  return result_table[n][W];
}

int main()
{
  int W = 0, n = 0, res = 0;
  res = scanf("%d %d", &W, &n);
  getchar();
  get_input(n, weights);
  res = solve(n, W);
  printf("%d", res);
  return 0;
}
