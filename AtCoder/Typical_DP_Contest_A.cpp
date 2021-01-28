/*
  章末問題5.3

  N 問の問題があるコンテストがあり，i 問目の問題の配点は p_i 点である．
  コンテスタントは，この問題の中から何問か解き，解いた問題の配点の合計が得点となる．
  このコンテストの得点は何通り考えられるか．

  【制約】
    1 ≤ N ≤ 100
    1 ≤ p_i ≤ 100
*/

#include <iostream>
#include <vector>


int main()
{
  // 正の整数の個数
  int N;
  std::cin >> N;

  // N個の配列
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++) std::cin >> a[i];

  // DPテーブル定義
  int W = 100 * 100;
  std::vector<std::vector<bool> > dp(N + 1, std::vector<bool>(W + 1, false));

  dp[0][0] = true;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < W + 1; j++) {
      if (!dp[i][j]) continue;
      dp[i + 1][j] = true;
      if (j + a[i] < W + 1) dp[i + 1][j + a[i]] = true;
    }
  }

  int res = 0;
  for (int i = 0; i < W + 1; i++) if (dp[N][i]) res++;

  std::cout << res << "通り" << std::endl;
}