#include "testlib.h"
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int> > Graph;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;

// 入力変数
int n, u, v;
int a[N_MAX], b[N_MAX];

bool is_tree() {
  // 連結リストを0-indexedで作成
  Graph g(n);
  for (int i = 0; i < n - 1; ++i) {
    // 1-indexed into 0-indexed
    g[a[i]-1].push_back(b[i]-1);
    g[b[i]-1].push_back(a[i]-1);
  }

  // BFSを行い、連結判定を行う。
  // 頂点数がnで、n-1本の辺からなるグラフが連結 ⇒ グラフは木である
  int count = 0;
  vector<int> visited(n, 0);
  queue<int> que;
  count++;
  visited[0] = 1;
  que.push(0);
  while (!que.empty()) {
    int current_vertex = que.front();
    que.pop();
    for (size_t i = 0; i < g[current_vertex].size(); ++i) {
      int next_vertex = g[current_vertex][i];
      if (visited[next_vertex] == 0) {
        count++;
        visited[next_vertex] = 1;
        que.push(next_vertex);
      }
    }
  }

  return count == n;
}

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  u = inf.readInt(1, n, "u");
  inf.readSpace();
  v = inf.readInt(1, n, "v");
  inf.readEoln();

  for (int i = 0; i < n - 1; ++i) {
    a[i] = inf.readInt(1, n, format("a[%d]", i + 1));
    inf.readSpace();
    b[i] = inf.readInt(1, n, format("b[%d]", i + 1));
    inf.readEoln();
  }

  inf.readEof();
}

void check() {
  // u != v
  ensuref(u != v, "Input 'v' and 'u' must be different");

  // ai != bi
  for (int i = 0; i < n - 1; ++i) {
    ensuref(a[i] < b[i], "Input 'a[i]' and 'b[i]' must be 'a[i] < b[i]'");
  }

  // 木であるかどうか
  ensuref(is_tree(), "The input graph is not a tree");
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
