#include <stdio.h>
#include <stdlib.h>


int a[100000];

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
        num[i] = atoi(str);
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


int solve(int n, int num[])
{
  return 0;
}

int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
  res = solve(n, a);
  printf("%d", res);
  return 0;
}
