#include <stdio.h>

int memo[128] = {0};

// フィボナッチ数列（メモ化再帰ver.）
int fibonacci(int n)
{
  if (n <= 1)  return 1;
  else {
    if (memo[n] == 0) memo[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memo[n];
  }
}


int main()
{
  for (int i = 0; i < 15; i++)  printf("n = %2d のとき %d\n", i, fibonacci(i));

  return 0;
}