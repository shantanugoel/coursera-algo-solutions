#include <stdio.h>

#define TEST 0

/*
 * We don't need to save the whole index and can make do with only last
 * 2 values. Hence this saves a lot on memory.
 */
unsigned long long array[3] = {0, 1, 1};
int last_fib_idx = 1;

/*
 * Since our "fib" function depends on the last_fib_idx state, we need to be
 * able to reset it if it is being used again.
 */
void init_fib()
{
  array[0] = 0;
  array[1] = 1;
  last_fib_idx = 1;
}

/*
 * This is not a real fibonacci calculator. It's a special one for this
 * particular problem which relies on the fact that we are only interested in
 * the fibonacci number % m value. We also know that to calculate this mod for
 * a fibonacci number, we need to only add the same mods for the last
 * 2 fibonacci numbers. Hence, we leverage this fact to be able to calculate
 * for very large fibonacci numbers while keeping time and memory limits in
 * check.
 */
unsigned long long fib(int a, int m)
{
  if(a < 2)
  {
    return a;
  }
  else
  {
    for(int i = last_fib_idx + 1; i <=a; ++i)
    {
      array[i % 3] = (array[(i - 1) % 3] + array[(i - 2) % 3]) % m;
    }
  }
  last_fib_idx = a;
  return array[a % 3];
}

/*
 * Calculate the pisano period
 */
int pisano(int m)
{
  int i = 2;
  init_fib();
  while(1)
  {
    if(0 == fib(i, m))
    {
      ++i;
      if(1 == fib(i, m))
      {
        break;
      }
    }
    ++i;
  }
  return (i -1);
}

int solve(unsigned long long n, int m)
{
  int a = 0, pisano_length = 0;
  unsigned long long fin = 0;
  pisano_length = pisano(m);
  a = n % pisano_length;
  init_fib();
  fin = fib(a, m);
  return fin;

}

int test()
{
}

int main()
{
  unsigned long long n = 0;
  int m = 0, res = 0;
#if TEST == 0
  res = scanf("%llu %d", &n, &m);
  printf("%d", solve(n, m));
#else
  test();
#endif
  return 0;
}
