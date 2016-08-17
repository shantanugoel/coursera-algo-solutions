#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long a[1000][2] = {0};
long c[1000][2] = {0};

void get_input(int n, long num[][2])
{
  int i =0, j =0;
  char ch = 0;
  char str[11];
  for(; i< n; ++i)
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
        //printf("==%s==", str);
        num[i][0] = atoi(str);
        //printf("**%d**", num[i]);
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

long long max_dot_prod(int n)
{
  int max_a = INT_MIN, max_c = INT_MIN, max_idx = 0;
  long long max = 0;
  for(int i = 0; i < n ; ++i)
  {
    max_a = INT_MIN;
    max_c = INT_MIN;
    max_idx = 0;
    for(int j = 0; j < n; ++j)
    {
      if( (a[j][1] != 1) && (a[j][0] > max_a))
      {
        max_a = a[j][0];
        max_idx = j;
        //printf("a %d\n", max_a);
      }
    }
    a[max_idx][1] = 1;
    for(int j = 0; j < n; ++j)
    {
      if( (c[j][1] != 1) && (c[j][0] > max_c))
      {
        max_c = c[j][0];
        max_idx = j;
        //printf("c %d\n", max_c);
      }
    }
    c[max_idx][1] = 1;

    //printf("%d * %d\n", max_a, max_c);
    max += (long long) max_a * (long long) max_c;
  }
  return max;
}

int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
  get_input(n, c);
  printf("%lld", max_dot_prod(n));
  return 0;
}
