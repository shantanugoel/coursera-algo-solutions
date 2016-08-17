#include <stdio.h>

#define TEST 0

double A[1000][2] = {0};

int max_ratio(int n)
{
  int max_idx = 0, i = 0;

  for(i = 0; i < n; ++i)
  {
    if(A[i][1] > 0)
    {
      max_idx = i;
      break;
    }
  }

  for(i = 0; i < n; ++i)
  {
    if( (A[i][1] > 0) &&
        ((A[i][0] / A[i][1]) > (A[max_idx][0] / A[max_idx][1])))
    {
      max_idx = i;
    }
  }
  return max_idx;
}

double solve(int n, int W)
{
  double value = 0;
  int i = 0, j = 0, usable_weight = 0;
  for(; (j < n) && (W > 0); ++j)
  {
    i = max_ratio(n);
    usable_weight = (A[i][1] < W)?A[i][1]:W;
    value += usable_weight * (A[i][0] / A[i][1]);
    A[i][1] -= usable_weight;
    W -= usable_weight;
    //printf("%f %d %d\n", value, i, W);
    if(W <= 0)
    {
      break;
    }
  }
  return value;
}

int test()
{
}

int main()
{
  int n = 0, W = 0, res = 0;
#if TEST == 0
  res = scanf("%d %d", &n, &W);
  for(int i = 0; i < n; ++i)
  {
    res = scanf("%lf %lf", &A[i][0], &A[i][1]);
  }
  printf("%.4lf", solve(n, W));
#else
  test();
#endif
  return 0;
}
