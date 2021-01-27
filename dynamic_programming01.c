#include <stdio.h>

// フィボナッチ数列(動的計画法ver.)
int fibonacci(int n)
{
  int a[128];

  a[0] = 1;
  a[1] = 1;

  // a[2]以降の出力
  for (int i = 2; i <= n; i++)  a[i] = a[i - 1] + a[i - 2];

  return a[n];
}


int main()
{
  for (int i = 0; i < 15; i++)  printf("n = %2d のとき %d\n", i, fibonacci(i));

  return 0;
}