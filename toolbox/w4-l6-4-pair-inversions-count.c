#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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


unsigned long long merge(int ar[], int l, int m, int r)
{
  int i = 0, j = 0;
  unsigned long long inversion_count = 0;
  //printf("%d %d %d\n", l, m, r);
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
    //printf("L[%d] %d, R[%d] %d\n", i, L[i], j, R[j]);
    if(L[i] > R[j])
    {
      inversion_count += m - l - i + 1;
      ar[l + i + j] = R[j];
      ++j;
    }
    else
    {
      ar[l + i + j] = L[i];
      ++i;
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
  //printf("ic %d\n", inversion_count);
  return inversion_count;
}

unsigned long long mergesort(int ar[], int l, int r)
{
  unsigned long long count = 0;
  if(l < r)
  {
    int m = l + (r - l) / 2;
    count = mergesort(ar, l, m);
    count += mergesort(ar, m + 1, r);

    count += merge(ar, l, m, r);
  }
  return count;
}

unsigned long long gen_test(int *n)
{
  unsigned long long count = 0;
  srand(time(NULL));
  *n = rand() % 10000;
  for(int i = 0; i < *n; ++i)
  {
    a[i] = rand();
  }
  for(int i = 0; i < *n; ++i)
  {
    for(int j = i + 1; j < *n; ++j)
    {
      if(a[i] > a[j])
      {
        count++;
      }
    }
  }
  return count;
}
int main()
{
  int n = 0, res = 0;
  unsigned long long gen_inv_count = 0, inv_count = 0;
  int * sorted = NULL;
  res = scanf("%d", &n);
  getchar();
  get_input(n, a);
#if TEST
  for(int i = 0; i < 999999999; ++i)
  {
    gen_inv_count = gen_test(&n);
    printf("Test %d with %d numbers\n", i, n);
    inv_count = mergesort(a, 0, n - 1);
    printf("Got: %d, expected %d\n", inv_count, gen_inv_count);
    if(gen_inv_count != inv_count)
    {
      printf("Failed!\n");
      for(int i = 0; i < n; ++i)
      {
        printf("%d ", a[i]);
      }
      printf("\n");
      while(1);
      exit(1);
    }
    else
    {
      printf("Success!\n");
    }
  }
#else
  printf("%llu", mergesort(a, 0, n - 1));
#endif
  return 0;
}
