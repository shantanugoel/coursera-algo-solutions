#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>


/*
 * Works fine but still not able to pass the time limit on #21 though. :(
 */
#define TEST 0

int points_xsorted[100000][2];
int points_ysorted[100000][2];

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


int partition(int ar[][2], int l, int r)
{
  int i = l + 1, j = l, x = ar[l][0];
  for(; i <= r; ++i)
  {
    if(ar[i][0] <= x)
    {
      j++;
      swap(&ar[i][0], &ar[j][0]);
      swap(&ar[i][1], &ar[j][1]);
    }
  }
  swap(&ar[l][0], &ar[j][0]);
  swap(&ar[l][1], &ar[j][1]);
  return j;
}

void quicksort(int ar[][2], int l, int r)
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

double calc_distance(int a[2], int b[2])
{
  double d = 0;
  d = ((double)b[0] - (double)a[0]) * ((double)b[0] - (double)a[0]) +
    ((double)b[1] - (double)a[1]) * ((double)b[1] - (double)a[1]);
  return sqrt(d);
}

double naive_solve(int pts[][2], int n)
{
  double min_d = DBL_MAX, d = 0;
  if(n <= 1)
  {
    return min_d;
  }
  else if (n == 2)
  {
    min_d = calc_distance(pts[0], pts[1]);
  }
  else
  {
    for(int i = 0; i < n; ++i)
    {
      for(int j = i + 1; j < n; ++j)
      {
        d = calc_distance(pts[i], pts[j]);
        if(d < min_d)
        {
          min_d = d;
        }
      }
    }
  }
  return min_d;
}

double get_min_d_y(int a[][2], int n, double d)
{
  double min_d = d;
  for(int i = 0; i < n; ++i)
  {
    for(int j = i + 1;
        (j - i <= 7) && (j < n) && ((a[j][1] - a[i][1]) < d) &&
        ((a[j][0] - a[i][0]) < d);
        ++j)
    {
      d = calc_distance(a[i], a[j]);
      if(d < min_d)
      {
        min_d = d;
      }
    }
  }
  return min_d;
}

double get_min_d(int px[][2], int py[][2], int n)
{
  int m = 0, i = 0, j = 0, yl = 0, yr = 0;
  double min_d_l = DBL_MAX, min_d_r = DBL_MAX, min_d_m = DBL_MAX, min_d = 0;
  int pyl[n/2 + 1][2];
  int pyr[n/2 + 1][2];
  int strip[n][2];
  if(n <= 3)
  {
    return naive_solve(px, n);
  }
  m = n / 2;
  for(i = 0; i < n; ++i)
  {
    int mx = px[m][0];
    int pyx = py[i][1];
    if(pyx < mx)
    {
      pyl[yl][1] = py[i][1];
      pyl[yl][0] = py[i][0];
      yl++;
    }
    else if(pyx > mx)
    {
      pyr[yr][1] = py[i][1];
      pyr[yr][0] = py[i][0];
      yr++;
    }
    else
    {
      for(j = m; (j >= 0) && (px[j][0] == mx); --j)
      {
        if(py[i][0] == px[j][1])
        {
          pyl[yl][1] = py[i][1];
          pyl[yl][0] = py[i][0];
          yl++;
          break;
        }
      }
      if((j < 0) || (px[j][0] != mx))
      {
        pyr[yr][1] = py[i][1];
        pyr[yr][0] = py[i][0];
        yr++;
      }
    }
  }
  if(yl + yr != n)
  {
    printf("%d %d %d\n", yl, yr, n);
    exit(1);
  }

  min_d_l = get_min_d(px, pyl, m + 1);
  min_d_r = get_min_d(&px[m + 1], pyr, n - m - 1);
  if(min_d_l < min_d_r)
  {
    min_d = min_d_l;
  }
  else
  {
    min_d = min_d_r;
  }

  for(i = 0, j = 0; i < n; ++i)
  {
    int temp_d = px[m][0] - py[i][1];
    if(temp_d < 0)
    {
      temp_d *= -1;
    }
    if(temp_d <= min_d)
    {
      strip[j][0] = py[i][1];
      strip[j][1] = py[i][0];
      ++j;
    }
  }
  min_d_m = get_min_d_y(strip, j, min_d);
  if(min_d_m < min_d)
  {
    min_d = min_d_m;
  }
  return min_d;
}

double solve(int n)
{
  double d;
#if TEST
  struct timeval t1, t2;
  gettimeofday(&t1, NULL);
#endif
  if(n <= 1)
  {
    return 0;
  }
  quicksort(points_xsorted, 0, n - 1);
  quicksort(points_ysorted, 0, n - 1);
#if TEST
  gettimeofday(&t2, NULL);
  printf("\nSorting Time: %f seconds", (double) (t2.tv_sec - t1.tv_sec));
  gettimeofday(&t1, NULL);
#endif
  d = get_min_d(points_xsorted, points_ysorted, n);
#if TEST
  gettimeofday(&t2, NULL);
  printf("\nAlgo Time: %f seconds\n", (double) (t2.tv_sec - t1.tv_sec));
#endif
  return d;
}

int main()
{
  int n = 0, res = 0;
  double naive_distance, distance = 0;
#if TEST
  struct timeval t1, t2;
  srand(time(NULL));
  n = rand() % 10000;
  printf("n: %d\n", n);
  for(int i = 0; i < n; ++i)
  {
    points_xsorted[i][0] = (rand() - RAND_MAX / 2) % 10;
    points_xsorted[i][1] = rand() - RAND_MAX / 2;
    points_ysorted[i][1] = points_xsorted[i][0];
    points_ysorted[i][0] = points_xsorted[i][1];
  }
  gettimeofday(&t1, NULL);
#else
  res = scanf("%d", &n);
  getchar();
  for(int i = 0; i < n; ++i)
  {
    get_input(2, &points_xsorted[i][0]);
    points_ysorted[i][1] = points_xsorted[i][0];
    points_ysorted[i][0] = points_xsorted[i][1];
  }
#endif

  distance = solve(n);
  printf("%.4f", distance);
#if TEST
  naive_distance = naive_solve(points_xsorted, n);
  gettimeofday(&t2, NULL);
  if(distance == naive_distance)
  {
    printf("\nSuccess! n:%d Total Time: %f seconds", n, (double) (t2.tv_sec - t1.tv_sec));
  }
  else
  {
    printf("\nFailure. Expected: %.4f, Got: %.4f\n", naive_distance, distance);
    printf("%d\n", n);
    exit(1);
  }
#endif
  return 0;
}
