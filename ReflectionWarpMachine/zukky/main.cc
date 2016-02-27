#include <bits/stdc++.h>
using namespace std;

typedef complex<double> P;

class UnionFind {
private:
  vector<int> par;
  vector<int> rank;

public:
  UnionFind(int n) {
    par.resize(n);
    rank.resize(n);
    for(int i = 0; i < n; ++i) {
      par[i] = i;
      rank[i] = 0;
    }
  }
  
  int find(int x) {
    if(par[x] == x) {
      return x;
    } else  {
      return par[x] = find(par[x]);
    }
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
  
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if(rank[x] == rank[y]) ++rank[x];
    }
  }
};

const int N_MAX = 9;
const int INF = 1<<28;
const double eps = 1e-8;
const double inf = 1e10;

int n;
P ps[N_MAX];
int G[N_MAX][N_MAX];
vector<vector<pair<int, int> > > es;
int ans;

double equals(double a, double b) {
  return abs(a - b) < eps;
}

pair<double, double> getLine(P p1, P p2) {
  if (equals(p1.imag(), p2.imag())) {
    return make_pair(inf, (p1.real() + p2.real()) / 2.0);
  } else {
    P m = (p1 + p2) / 2.0;
    double a = - (p1.real() - p2.real()) / (p1.imag() - p2.imag());
    double b = m.imag() - a * m.real();
    return make_pair(a, b);
  }
}

void rec(UnionFind uf, int num, int count, int prev = 0) {
  if (num >= ans) {
    return;
  }
  if (count == n - 1) {
    ans = num;
    return;
  }
  for (int i = prev; i < es.size(); ++i) {
    UnionFind next = uf;
    int ncount = count;
    for (int j = 0; j < es[i].size(); ++j) {
      int a = es[i][j].first;
      int b = es[i][j].second;
      if (!next.same(a, b)) {
        next.unite(a, b);
        ncount++;
      }
    }
    rec(next, num + 1, ncount, i + 1);
  }
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> ps[i].real() >> ps[i].imag();
    }

    vector<pair<double, double> > ls;
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        pair<double, double> l = getLine(ps[i], ps[j]);
        int id = -1;
        for (int k = 0; k < ls.size(); ++k) {
          if (equals(l.first, ls[k].first) &&
              equals(l.second, ls[k].second)) {
            id = k;
            break;
          }
        }
        if (id == -1) {
          id = ls.size();
          ls.push_back(l);
        }
        G[i][j] = G[j][i] = id;
      }
    }

    es.clear();
    es.resize(ls.size());
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        es[G[i][j]].push_back(make_pair(i, j));
      }
    }

    ans = n - 1;
    rec(UnionFind(n), 0, 0);
    cout << ans << endl;
  }
  return 0;
}
