#include <iostream>
#include <vector>

bool recursion(int i, int w, const std::vector<int> &a);


// 部分和問題を再帰関数を用いる全探索で解く
int main()
{
  int N, W;

  std::cout << "正の整数 N を入力" << std::endl;
  std::cin >> N;
  std::cout << "求めたい総和 W を入力" << std::endl;
  std::cin >> W;
  std::cout << "N個の配列を入力" << std::endl;
  std::vector<int> a(N);

  for (int i = 0; i < N; ++i) std::cin >> a[i];

  // 再帰的に解く
  if (recursion(N, W, a)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
}


// N個の正の整数のうちの最初のi個から何個か選んで，総和をwにできるかを真偽値で返す
bool recursion(int i, int w, const std::vector<int> &a)
{
  // ベースケース（0個の整数の総和は常に0）
  if (i == 0) {
    if (w == 0) return true;
    else        return false;
  }

  // a[i - 1]を選ばない場合
  if (recursion(i - 1, w, a)) return true;

  // a[i - 1]を選ぶ場合
  if(recursion(i -1, w - a[i - 1], a)) return true;

  // どちらでもない場合
  return false;
}