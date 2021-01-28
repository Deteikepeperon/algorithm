#include <iostream>
#include <vector>

// Union-Find
struct UnionFind {
  std::vector<int> par;  // 各頂点の親頂点の番号．自身が根の場合は-1
  std::vector<int> siz;  // 各頂点の属する根付き木の頂点数

  // 初期化
  UnionFind(int n) : par(n, -1), siz(n, 1) { }

  // 根を求める（経路圧縮の工夫あり）
  int root(int x) {
    if (par[x] == -1) return x;         // x が根の場合は x を直接返す
    else return par[x] = root(par[x]);  // 経路中の各頂点に対し，x の親 par[x] を根に設定する

    // else return root(par[x]);   // x が根でないなら再帰的に親へと進む（経路圧縮の工夫なしver.）
  }

  // x と y が同じグループに属するか判定（根が一致するかどうか）
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // x を含むグループと y を含むグループとを併合する
  bool unite(int x, int y) {
    // x, y をそれぞれ根まで移動
    x = root(x);
    y = root(y);

    // 既に同じグループのときは何もしない
    if (x == y) return false;

    // union by size（頂点数の小さい方の根付き木を大きい方に併合，y 側のサイズが小さくなるようにする）
    if (siz[x] < siz[y]) std::swap(x, y);

    // y を x の子とする
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
};


// Union-Findの全体実装
int main()
{
  UnionFind uf(7);  // {0}, {1}, {2}, {3}, {4}, {5}, {6}

  uf.unite(1, 2);   // {0}, {1, 2}, {3}, {4}, {5}, {6}
  uf.unite(2, 3);   // {0}, {1, 2, 3}, {4}, {5}, {6}
  uf.unite(5, 6);   // {0}, {1, 2, 3}, {4}, {5, 6}

  std::cout << uf.issame(1, 3) << std::endl;  // true
  std::cout << uf.issame(2, 5) << std::endl;  // false

  uf.unite(1, 6);   // {0}. {1, 2, 3, 5, 6}, {4}

  std::cout << uf.issame(2, 5) << std::endl;  // true
}