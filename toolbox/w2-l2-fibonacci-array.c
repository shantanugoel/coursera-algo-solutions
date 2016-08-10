#include <stdio.h>

unsigned long a[100] = {0}; // Allowing calculations for uptil 100th number

unsigned long fib(int n)
{
  if(n <= 1)
  {
    return n;
  }
  a[0] = 0;
  a[1] = 1;
  for(int i = 2; i <= n; ++i)
  {
    a[i] = a[i - 1] + a[i - 2];
  }
  return a[n];

}

int main()
{
  int n = 0, res = 0; // nth Fibonacci number to be found
  res = scanf("%d", &n);
  printf("%lu", fib(n));
  return 0;
}
