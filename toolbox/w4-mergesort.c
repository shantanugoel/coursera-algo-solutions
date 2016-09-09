#include <stdio.h>
#include <stdlib.h>


int a[100000];
int L[100000];
int R[100000];

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
    //printf("%d ", num[i]);
  }
#endif
}


void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void merge(int ar[], int l, int m, int r)
{
  int i = 0, j = 0;
  for(i = 0; i <= m - l; ++i)
  {
    L[i] = ar[l + i];
  }
  for(i = 0; i < r - m; ++i)
  {
    R[i] = ar[m + i + 1];
  }
  for(i = 0, j = 0; (i <= m - l) && (j < r - m);)
  {
    if(L[i] < R[j])
    {
      ar[l + i + j] = L[i];
      ++i;
    }
    else
    {
      ar[l + i + j] = R[j];
      ++j;
    }
  }
  while(i <= m - l)
  {
    ar[l + i + j] = L[i];
    ++i;
  }
  while(j < r - m)
  {
    ar[l + i + j] = R[j];
    ++j;
  }

}

void mergesort(int ar[], int l, int r)
{
  if(l < r)
  {
    int m = l + (r - l) / 2;
    mergesort(ar, l, m);
    mergesort(ar, m + 1, r);

    merge(ar, l, m, r);
  }
}

int main()
{
  int n = 0, res = 0;
  int * sorted = NULL;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
  mergesort(a, 0, n - 1);
  for(int i = 0; i < n; ++i)
  {
    printf("%d ", a[i]);
  }
  return 0;
}
