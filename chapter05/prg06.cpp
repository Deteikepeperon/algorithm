#include <iostream>
#include <string>
#include <vector>

const int INF = 1 << 29;  // 十分大きな値（ここでは2^29とする）

// 編集距離は最小化問題である
template<class T> void choose_minimum(T& a, T b) {
  if (a > b) a = b;
}


// 編集距離を動的計画法を用いて求める
int main()
{
  std::string S, T;

  std::cout << "文字列 S を入力" << std::endl;
  std::cin >> S;
  std::cout << "文字列 T を入力" << std::endl;
  std::cin >> T;

  // DPテーブル定義
  std::vector<std::vector<int> > dp(S.size() + 1, std::vector<int>(T.size() + 1, INF));

  // DP初期条件
  dp[0][0] = 0;

  for (int i = 0; i <= S.size(); i++) {
    for (int j = 0; j <= T.size(); j++) {
      // 変更操作
      if (i > 0 && j > 0) { // dpの添字が負の値にならないように
        if (S[i - 1] == T[j - 1])  choose_minimum(dp[i][j], dp[i - 1][j - 1]);
        else choose_minimum(dp[i][j], dp[i - 1][j - 1] + 1);
      }

      // 削除操作
      if (i > 0) choose_minimum(dp[i][j], dp[i - 1][j] + 1);

      // 挿入操作
      if (j > 0) choose_minimum(dp[i][j], dp[i][j - 1] + 1);
    }
  }

  std::cout << "操作回数の最小値：" << dp[S.size()][T.size()] << std::endl;
}