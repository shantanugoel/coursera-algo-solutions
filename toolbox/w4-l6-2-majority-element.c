#include <stdio.h>
#include <stdlib.h>

/*
 * Concept used is to use a divide and conquer apporach. If there's a majority
 * element, it should be majority in at least 1 half of the array. In each
 * stage, we divide the array into two halves and get the majority element from
 * each half. It continues till we have a single element left which returns
 * that single element value. The main trick lies in how to combine these
 * 2 results. So, we can have 4 combinations:
 * 1. Both halves do not contain a majority element. In this case, we simply
 *    return 0 or no majority element found.
 * 2. One half or both halves have a majority element. This makes up the rest
 *    3 cases. In this, we count this element across all the array and see if
 *    it still makes a majority. If it does, we return the element, otherwise
 *    return 0.
 */
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

int count(int x, int n,int num[])
{
  int cnt = 0;
  for(int i = 0; i < n; ++i)
  {
    if(x == num[i])
    {
      cnt++;
    }
  }
  return cnt;
}

int solve(int n, int num[])
{
  int l = 0, r = 0, ln = 0, rn = 0, cnt = 0;
  if(n == 1)
  {
    return num[0];
  }
  ln = n / 2;
  rn = (n + 1) / 2;
  l = solve(ln, &num[0]);
  r = solve(rn, &num[ln]);
  if(r != 0)
  {
    cnt = count(r, n, num);
    if(cnt > n / 2)
    {
      return r;
    }
  }
  if(l != 0)
  {
    cnt = count(l, n, num);
    if(cnt > n / 2)
    {
      return l;
    }
  }
  return 0;
}

int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
  res = solve(n, a);
  if(res != 0)
  {
    res = 1;
  }
  printf("%d", res);
  return 0;
}
