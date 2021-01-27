#include <iostream>
#include <vector>

const long long INF = 1LL << 60;

std::vector<long long> h;   // 入力データ用配列
std::vector<long long> dp;  // メモ化用配列

template<class T> void choose_minimum(T& a, T b) {
  if (a > b) a = b;
}

long long recursive_func(int i);


// Frog問題を「メモ化再帰」で解く
int main()
{
  int N;

  std::cout << "足場の数 N を入力" << std::endl;
  std::cin >> N;

  h.resize(N);  // 要素数を変更
  for (int i = 0; i < N; i++) std::cin >> h[i];

  dp.assign(N, INF);  // 指定した値（最小化問題なのでINF）でvectorを埋め尽くす

  std::cout << "コストの総和の最小値：" << recursive_func(N - 1) << std::endl;
}


long long recursive_func(int i)
{
  // DPの値が更新されていたらそのままリターン
  if (dp[i] < INF) return dp[i];

  // ベースケース：足場0のコストは0
  if (i == 0) return 0;

  long long res = INF;  // 答えを表す変数を初期化

  // 足場 i - 1 から来た場合
  choose_minimum(res, recursive_func(i - 1) + abs(h[i] - h[i - 1]));

  // 足場 i - 2 から来た場合
  if (i > 1) choose_minimum(res, recursive_func(i - 2) + abs(h[i] - h[i - 2]));

  return dp[i] = res;  // 結果をメモ化しながら返す
}