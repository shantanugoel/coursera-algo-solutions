#include <stdio.h>

#define TEST 0

int segments[100][2] = {0};
int endpoints[100] = {0};

void sort(int segments[][2], int n)
{
  int temp0 = 0, temp1 = 0;
  for(int i = 0; i < n; ++i)
  {
    for(int j = i + 1; j < n; ++j)
    {
      if(segments[i][0] > segments[j][0])
      {
        temp0 = segments[i][0];
        temp1 = segments[i][1];
        segments[i][0] = segments[j][0];
        segments[i][1] = segments[j][1];
        segments[j][0] = temp0;
        segments[j][1] = temp1;
      }
    }
  }
}

/*
 * Technique to follow is:
 * 1. Sort all the segments according to earlier start addresses first
 * 2. Select earliest segment's starting point
 * 3. Find all overlapping segments for this segment and find the common range
 * 4. Select the start point of this range as an endpoint
 * 5. Repeat for the remaining segments
 */
int solve(int n)
{
  int start = 0, end = 0, m = 0;
  sort(segments, n);
  for(int i = 0; i < n; ++i)
  {
    start = segments[i][0];
    end = segments[i][1];
    for(int j = i + 1; j < n; ++j)
    {
      if((segments[j][0] >= start) && (segments[j][0]) <= end)
      {
        start = segments[j][0];
        if(segments[j][1] <= end)
        {
          end = segments[j][1];
        }
        ++i;
      }
      else
      {
        break;
      }
    }
    endpoints[m] = start;
    ++m;
  }
  return m;
}

int test()
{
}

int main()
{
  int n = 0, res = 0, m = 0;
#if TEST == 0
  res = scanf("%d", &n);
  for(int i = 0; i < n; ++i)
  {
    res = scanf("%d %d", &segments[i][0], &segments[i][1]);
  }
  m = solve(n);
  printf("%d\n", m);
  for(int i = 0; i < m; ++i)
  {
    printf("%d ", endpoints[i]);
  }
#else
  test();
#endif
  return 0;
}
