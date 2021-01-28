/*
  N 日間の夏休みです．i 日目には，

    A: 海で泳ぐ．幸福度 a_i を加算
    B: 山で虫取りする．幸福度 b_i を加算
    C: 家で宿題をする．幸福度 c_iを加算

  の三択の中から好きなものを選ぶことができます．
  ただし，2日連続で A, B, C のうちの同一種類の活動を選択をすることはできません．
  この制約下で最終的に得られる幸福度の総和を最大にせよ．

  【制約】
    1 ≤ N ≤ 10^5
    1 ≤ a_i, n_i, c_i ≤ 10^4
*/

#include <iostream>
#include <vector>
#include <cmath>

template<class T> void choose_maximum(T& a, T b) {
  if (a < b) a = b;
}


int main(void)
{
  int N;

  std::cout << "夏休みの日数 N を入力" << std::endl;
  std::cin >> N;

  std::cout << "その日の幸福度（A，B，C）を" << N << "日分入力" << std::endl;
  std::vector<std::vector<long long> > a(std::pow(10, 5), std::vector<long long>(3, 0));
  for (int i = 0; i < N; i++) for (int j = 0; j < 3; j++) std::cin >> a[i][j];

  // DPテーブル定義（最大化問題なので0で初期化）
  std::vector<std::vector<long long> > dp(std::pow(10, 5), std::vector<long long>(3, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        choose_maximum(dp[i + 1][k], dp[i][j] + a[i][k]);
      }
    }
  }

  long long res = 0;
  for (int i = 0; i < 3; i++) choose_maximum(res, dp[N][i]);

  std::cout << "幸福度の総和：" << res << std::endl;
}