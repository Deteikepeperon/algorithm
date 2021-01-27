#include <iostream>
#include <vector>

const long long INF = 1LL << 60;

template<class T> void choose_minimum(T& a, T b) {
  if (a > b) a = b;
}


// Frog問題を「配る遷移形式」で解く
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
  for (int i = 0; i < N; i++) {
    if (i + 1 < N) choose_minimum(dp[i + 1], dp[i] + std::abs(h[i] - h[i + 1]));
    if (i + 2 < N) choose_minimum(dp[i + 2], dp[i] + std::abs(h[i] - h[i + 2]));
  }

  std::cout << "コストの総和の最小値：" << dp[N - 1] << std::endl;
}