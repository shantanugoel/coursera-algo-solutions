#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TEST 0

/*
 * Coursera submissions were closed by the time I wrote this. So I haven't made
 * the input format same as coursera exercise (lists of integers). I'm using
 * simple strings as inputs like the lecture but the algorithm is going to be
 * same. If you are using this for coursera problem, then you need to modify
 * the input format code accordingly and use integer arrays instead of char.
 */

char s1[101];
char s2[101];
char s3[101];
int distance[101][101][101] = {0};

int min(int num[], int n)
{
  int min = INT_MAX;
  for(int i = 0; i < n; ++i)
  {
    if(num[i] < min)
    {
      min = num[i];
    }
  }
  return min;
}

int max(int num[], int n)
{
  int max = INT_MIN;
  for(int i = 0; i < n; ++i)
  {
    if(num[i] > max)
    {
      max = num[i];
    }
  }
  return max;
}

int solve(char s1[], char s2[], char s3[])
{
  int len1, len2, len3;
  len1 = strlen(s1);
  len2 = strlen(s2);
  len3 = strlen(s3);

  for(int i = 0; i <= len1; ++i)
  {
    distance[i][0][0] = 0;
  }
  for(int j = 0; j <= len2; ++j)
  {
    distance[0][j][0] = 0;
  }
  for(int k = 0; k <= len2; ++k)
  {
    distance[0][0][k] = 0;
  }

  for(int i = 1; i <= len1; ++i)
  {
    for(int j = 1; j <= len2; ++j)
    {
      for(int k = 1; k <= len3; ++k)
      {
        int temp_d[5] = {INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN};
        temp_d[0] = distance[i - 1][j][k];
        temp_d[1] = distance[i][j - 1][k];
        temp_d[2] = distance[i][j][k - 1];
        if((s1[i - 1] == s2[j - 1]) && (s2[j - 1] == s3[k - 1]) && (s1[i - 1] == s3[k - 1]))
        {
          temp_d[3] = distance[i - 1][j - 1][k - 1] + 1; //Match
        }
        else
        {
          temp_d[4] = distance[i - 1][j - 1][k - 1]; //Mismatch
        }
        distance[i][j][k] = max(temp_d, 5);
      }
    }
  }
  return distance[len1][len2][len3];
}

int test()
{
}

int main()
{
  int n = 0, res = 0;
#if TEST == 0
  res = scanf("%s", s1);
  res = scanf("%s", s2);
  res = scanf("%s", s3);
  printf("%d", solve(s1, s2, s3));
#else
  test();
#endif
  return 0;
}
