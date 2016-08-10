#include <stdio.h>


unsigned int fib(int n)
{
  if(n <= 1)
  {
    return n;
  }

  return (fib(n -1) + fib(n - 2));
}

int main()
{
  int n = 0, res = 0; // nth Fibonacci number to be found
  res = scanf("%d", &n);
  printf("%d", fib(n));
  return 0;
}
