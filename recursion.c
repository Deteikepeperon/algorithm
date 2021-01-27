#include <stdio.h>

// フィボナッチ数列（再帰ver.）
int fibonacci(int n)
{
  if (n <= 1)  return 1;
  else         return fibonacci(n - 1) + fibonacci(n - 2);
}


int main()
{
  for (int i = 0; i < 15; i++)  printf("n = %2d のとき %d\n", i, fibonacci(i));

  return 0;
}