#include "testlib.h"
#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

// 制約
const int N_MIN = 1;
const int N_MAX = 3000;
const int M_MIN = 1;
const int V_MIN = 0;
const int V_MAX = 1;

// 入力変数
int n, m;
int v[N_MAX], s[N_MAX], t[N_MAX], q[N_MAX];

vector<int> G[N_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  m = inf.readInt(M_MIN, n, "m");
  inf.readEoln();

  for (int i = 0; i < n; ++i) {
    v[i] = inf.readInt(V_MIN, V_MAX, format("v[%d]", i));
    inf.readSpace();
    s[i] = inf.readInt(0, n - 1, format("s[%d]", i));
    inf.readSpace();
    t[i] = inf.readInt(0, n - 1, format("t[%d]", i));
    inf.readEoln();
  }

  for (int i = 0; i < m; ++i) {
    q[i] = inf.readInt(0, n - 1, format("q[%d]", i));
    inf.readEoln();
  }

  inf.readEof();
}

bool visited[N_MAX];

void dfs(int cur) {
  rep(i,(int)G[cur].size()) {
    int next = G[cur][i];
    if( visited[next] ) continue;
    visited[next] = true;
    dfs(next);
  }
}

void check() {
  rep(i,n) {
    G[i].push_back(s[i]);
    G[i].push_back(t[i]);
    G[s[i]].push_back(i);
    G[t[i]].push_back(i);
  }
  visited[0] = true;
  dfs(0);
  rep(i,n) assert( visited[i] );
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
