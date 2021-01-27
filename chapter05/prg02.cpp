#include <iostream>
#include <vector>

const long long INF = 1LL << 60;

// 緩和処理（引数は様々な型を取りうることを考慮してテンプレート関数にする）
template<class T> void choose_minimum(T& a, T b) {
  if (a > b) a = b;  // 現時点の最小値 a よりも挑戦者 b のほうが小さかった場合，値を更新
}


// Frog問題を「緩和」を意識した動的計画法で解く
int main()
{
  int N;

  std::cout << "足場の数 N を入力" << std::endl;
  std::cin >> N;

  std::cout << "足場の高さ h を入力" << std::endl;
  std::vector<long long> h(N);
  for (int i = 0; i < N; i++) std::cin >> h[i];

  std::vector<long long> dp(N, INF);

  dp[0] = 0;
  for (int i = 1; i < N; i++) {
    choose_minimum(dp[i], dp[i - 1] + std::abs(h[i] - h[i - 1]));

    // i = 1 のとき，dp[i - 2]の添字の値が -1 になるため回避
    if (i > 1) choose_minimum(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2]));
  }

  std::cout << "コストの総和の最小値：" << dp[N - 1] << std::endl;
}