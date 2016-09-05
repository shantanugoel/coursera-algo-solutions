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


void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}


int partition(int ar[], int l, int r)
{
  int i = l + 1, j = l, x = ar[l];
  for(; i <= r; ++i)
  {
    if(ar[i] <= x)
    {
      j++;
      swap(&ar[i], &ar[j]);
    }
  }
  swap(&ar[l], &ar[j]);
  return j;
}

void quicksort(int ar[], int l, int r)
{
  int m = 0;
  if(l >= r)
  {
    return;
  }
  m = partition(ar, l, r);
  quicksort(ar, l, m - 1);
  quicksort(ar, m + 1, r);
}

int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
  quicksort(a, 0, n - 1);
  for(int i = 0; i < n; ++i)
  {
    printf("%d ", a[i]);
  }
  return 0;
}
