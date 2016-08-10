#include <stdio.h>
#include <stdlib.h>

int num[200000];

void get_input(int n)
{
  int i =0, j =0;
  char ch = 0;
  char str[11];
  ch = getchar();
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
        num[i] = atoi(str);
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

unsigned long long max_pair_prod(int n)
{
  int max1 = 0, max2 = 0, i = 0;
  int maxn1 = 0, maxn2 = 0;
  unsigned long long res = 0;
  for(i = 0; i <n; ++i)
  {
    if(maxn1 < num[i])
    {
      maxn1 = num[i];
      max1 = i;
    }
  }
  for(i = 0; i <n; ++i)
  {
    if((i != max1) && (maxn2 < num[i]))
    {
      maxn2 = num[i];
      max2 = i;
    }
  }
  //printf("\n max %d %d\n", num[max1], num[max2]);

  res = (long long)num[max1] * (long long)num[max2];
  return res;
}

int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  get_input(n);
  printf("%llu", max_pair_prod(n));
  return 0;
}
