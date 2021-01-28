#include <iostream>
#include <vector>

// Union-Find
struct UnionFind {
  std::vector<int> par;
  std::vector<int> siz;

  UnionFind(int n) : par(n, -1), siz(n, 1) { }

  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);

    if (x == y) return false;

    if (siz[x] < siz[y]) std::swap(x, y);

    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
};


// Union-Findを用いて連結成分の個数を求める
int main()
{
  int N, M;

  std::cout << "頂点数 N を入力" << std::endl;
  std::cin >> N;

  std::cout << "辺数 M を入力" << std::endl;
  std::cin >> M;

  // Union-Findを要素数 N で初期化
  UnionFind uf(N);

  std::cout << "各辺 e = (u, v) を" << M << "回入力" << std::endl;

  // 各辺に対する処理
  for (int i = 0; i < M; i++) {
    int u, v;

    std:: cin >> u >> v;

    uf.unite(u, v);  // u を含むグループと v を含むグループを併合
  }

  // 根付き木の根となっている頂点の個数を集計
  int res = 0;
  for (int x = 0; x < N; x++) {
    if (uf.root(x) == x) res++;
  }

  std::cout << "Union-Findに含まれる根付き木の個数：" << res << std::endl;
}