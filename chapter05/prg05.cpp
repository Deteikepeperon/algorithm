#include <iostream>
#include <vector>

// ナップサック問題は最大化問題である
template<class T> void choose_maximum(T& a, T b) {
  if (a < b) a = b;  // 現時点の最大値 a よりも挑戦者 b のほうが大きかった場合，値を更新
}


// ナップサック問題に対する動的計画法
int main()
{
  int N;
  long long W;

  std::cout << "品物の個数 N を入力" << std::endl;
  std::cin >> N;
  std::cout << "重さの総和 W を入力" << std::endl;
  std::cin >> W;
  std::cout << "N個の配列（重さ w，価値 v）を入力" << std::endl;
  std::vector<long long> weight(N), value(N);
  for (int i = 0; i < N; i++) std::cin >> weight[i] >> value[i];

  // DPテーブル定義（2次元配列）
  std::vector<std::vector<long long> > dp(N + 1, std::vector<long long>(W + 1, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      // i番目の品物を選ぶ場合
      // 選んだ後に(i + 1, j)の状態になるならば，選ぶ前は（i, j - weight[j]) その状態に価値が加わる
      // 但し，w - weight[i] >= 0 の場合のみ
      if (j - weight[i] >= 0) choose_maximum(dp[i + 1][j], dp[i][j - weight[i]] + value[i]);

    // i番目の品物を選ばない場合
    // 重さも価値も特に変化しない
    choose_maximum(dp[i + 1][j], dp[i][j]);
    }
  }

  std::cout << "価値の総和の最大値：" << dp[N][W] << std::endl;
}
