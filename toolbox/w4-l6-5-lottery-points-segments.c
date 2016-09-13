#include <stdio.h>
#include <stdlib.h>

#define LABEL_START 1
#define LABEL_END   2
#define LABEL_POINT 3

/*
 * The idea is to plot all the start, end and given points on a straight line.
 * Or equivalently, put them together in a single array and sort them. While
 * doing this, we label each element (by taking a 2D array) to mark them as
 * start, end and point. This sorting can be done in O(nlogn). Now, a naive
 * algo to do point searching is O(n^2) but in our sorted array, we can iterate
 * through in O(n) and every time we hit a start, increment the count and every
 * time we hit an end, decrement the count. When we hit a point, the current
 * count will give us the currently "open" segments and we can use this to
 * determine how many segements does the point lie in.
 * Gotchas:
 * 1. In case the point lies on a start/end, the sorting may put them in any
 *    order. So we need to make sure to account for additional segments if
 *    there was an end that occured (and thus decremented the segment count)
 *    before reaching the point. And similarly, if there was a start that is
 *    yet to occur (and hence hasn't incremented the segment count yet)
 * 2. Since the points are being sorted, we need to keep a "index map" of which
 *    point corresponds to which number in the given point list.
 */

int temp[2];
/* 2 points for each segment, start and end and 1 point itself. If max
 *   permissible items aren't same for these, then adjust array size
 *   accordingly.
 * 1 extra element to store the label
 */
int segments_points[50000 * 3][2];
int points[50000];
int points_map[200000001];
int result[50000] = {0};

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


int* solve(int s, int p)
{
  int count = 0;
  int same_count = 0;
  int value = 0;
  int label = 0;
  quicksort(segments_points, 0, 2 * s + p - 1);
  for(int i = 0; i < 2 * s + p; ++i)
  {
    value = segments_points[i][0];
    label = segments_points[i][1];
    if(label == LABEL_START)
    {
      count++;
    }
    else if(label == LABEL_END)
    {
      count--;
    }
    else
    {
      for(int j = 1;
          (j <= i) && (segments_points[i - j][0] == value);
          j++)
      {
        if(segments_points[i - j][1] == LABEL_END)
        {
          same_count++;
        }
      }
      for(int j = 1;
          (j < (2 * s + p - i)) &&
          (segments_points[i + j][0] == value);
          j++)
      {
        if(segments_points[i + j][1] == LABEL_START)
        {
          same_count++;
        }
      }
      result[points_map[value + 100000000]] = count + same_count;
      same_count = 0;
    }
  }
  return result;
}

int main()
{
  int s = 0, p = 0, res = 0, point = 0;
  int * ans = 0;
  res = scanf("%d %d", &s, &p);
  getchar();
  for(int i = 0; i < s; ++i)
  {
    get_input(2, temp);
    segments_points[i][0] = temp[0];
    segments_points[i][1] = LABEL_START;
    segments_points[i + s][0] = temp[1];
    segments_points[i + s][1] = LABEL_END;
  }
  get_input(p, points);
  for(int i = 0; i < p; ++i)
  {
    point = points[i];
    segments_points[i + 2 * s][0] = point;
    segments_points[i + 2 * s][1] = LABEL_POINT;
    /*
     * 10^8 is being added here since the point can vary between -10^8 to 10^8
     * but array indexes can only be positive. So we allocate an array of size
     * 2*10^8 + 1 and add 10^8 to every point to shift the floor.
     */
    points_map[point + 100000000] = i;
  }
  ans = solve(s, p);
  for(int i = 0; i < p; ++i)
  {
    printf("%d ", ans[points_map[points[i] + 100000000]]);
  }
  return 0;
}
