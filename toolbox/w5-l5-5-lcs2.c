#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TEST 0

char s1[101];
char s2[101];
int distance[101][101] = {0};

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

int solve(char s1[], char s2[])
{
  int len1, len2;
  len1 = strlen(s1);
  len2 = strlen(s2);

  for(int i = 0; i <= len1; ++i)
  {
    distance[i][0] = 0;
  }
  for(int j = 0; j <= len2; ++j)
  {
    distance[0][j] = 0;
  }

  for(int i = 1; i <= len1; ++i)
  {
    for(int j = 1; j <= len2; ++j)
    {
      int temp_d[4] = {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
      temp_d[0] = distance[i - 1][j]; //Insertion
      temp_d[1] = distance[i][j - 1]; //Deletion
      if(s1[i - 1] != s2[j - 1])
      {
        temp_d[2] = distance[i - 1][j - 1]; //Mismatch
      }
      else
      {
        temp_d[3] = distance[i - 1][j - 1] + 1; //Match
      }
      distance[i][j] = max(temp_d, 4);
    }
  }
  for(int i = 0; i <= len1; ++i)
  {
    printf("\n");
    for(int j = 0; j <= len2; ++j)
    {
      printf("%d ", distance[i][j]);
    }
  }
  return distance[len1][len2];
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
  printf("%d", solve(s1, s2));
#else
  test();
#endif
  return 0;
}
