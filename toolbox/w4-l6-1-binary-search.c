#include <stdio.h>
#include <stdlib.h>

int a[100000];
int b[100000];

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

void solve(int n, int k)
{
  for(int i = 0; i < k; ++i)
  {
    int l = 0, r = n, pos = -1, m = 0;
    while(l <= r)
    {
      m = l + (r - l) / 2;
      if(r == -1)
      {
        exit(0);
      }
      if(a[m] == b[i])
      {
        pos = m;
        break;
      }
      else if(a[m] < b[i])
      {
        l = m + 1;
      }
      else
      {
        r = m - 1;
      }
    }
    printf("%d ", pos);
  }
}

int main()
{
  int n[1] = {0}, k[1] = {0};
  get_input(1, n);
  get_input(n[0], a);
  get_input(1, k);
  get_input(k[0], b);
  solve(n[0], k[0]);
  return 0;
}
