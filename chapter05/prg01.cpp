#include <iostream>
#include <vector>

const long long INF = 1LL << 60;  // 十分大きい値とする（ここでは2^60）


// Frog問題を動的計画法で解く
int main()
{
  int N;

  std::cout << "足場の数 N を入力" << std::endl;
  std::cin >> N;

  std::cout << "足場の高さ h を入力" << std::endl;
  std::vector<long long> h(N);
  for (int i = 0; i < N; i++) std::cin >> h[i];

  std::vector<long long> dp(N, INF);  // 配列 dp を定義（配列全体を無限大を表す値に初期化）

  dp[0] = 0;  // 初期条件（スタート地点のコストは0）
  for (int i = 1; i < N; i++) {
    // 足場0から足場1へ移動するコスト
    if (i == 1) dp[i] = std::abs(h[i] - h[i - 1]);

    // 右隣の頂点へ移動する手段の最小コストと，1つ飛ばしで移動する手段の最小コストを比較
    else dp[i] = std::min(dp[i - 1] + std::abs(h[i] - h[i - 1]),
                          dp[i - 2] + std::abs(h[i] - h[i - 2]));
  }

  std::cout << "コストの総和の最小値：" << dp[N - 1] << std::endl;
}