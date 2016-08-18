#include <stdio.h>
#include <stdlib.h>

int num[100];

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


int get_num_digits(int n)
{
  int i = 0;
  for(; n > 0; ++i)
  {
    n = n / 10;
  }
  return i;
}

int do_swap(int a, int b)
{
  int new_a, new_b, num_digits_a, num_digits_b;
  new_a = a;
  new_b = b;
  num_digits_a = get_num_digits(a);
  num_digits_b = get_num_digits(b);
  for(int i = 0; i < num_digits_b; ++i)
  {
    new_a *= 10;
  }

  for(int i = 0; i < num_digits_a; ++i)
  {
    new_b *= 10;
  }
  new_a += b;
  new_b += a;
  if(new_a > new_b)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

void solve(int n)
{
  int temp = 0;
  for(int i = 0; i < n; ++i)
  {
    for(int j = i + 1; j < n; ++j)
    {
      if(do_swap(num[i], num[j]))
      {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
      }
    }
  }
}


int main()
{
  int n = 0, res = 0;
  res = scanf("%d", &n);
  get_input(n);
  solve(n);
  for(int i = 0; i < n; ++i)
  {
    printf("%d", num[i]);
  }
  return 0;
}
