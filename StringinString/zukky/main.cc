#include <bits/stdc++.h>
using namespace std;

class SuffixArray {
private:
  string S;
  vector<int> sa, rank;
  struct Comp {
    const vector<int> &rank;
    int k;
    Comp(const vector<int> &rank, int k) : rank(rank), k(k) {}
    bool operator () (int i, int j) {
      if (rank[i] != rank[j]) {
        return rank[i] < rank[j];
      } else {
        int ri = i + k < rank.size() ? rank[i + k] : -1;
        int rj = j + k < rank.size() ? rank[j + k] : -1;
        return ri < rj;
      }
    }
  };

public:
  SuffixArray(string S) : S(S) {
    int n = S.size();
    sa.resize(n + 1);
    rank.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
      sa[i] = i;
      rank[i] = i < n ? S[i] : -1;
    }
    for (int k = 1; k <= n; k *= 2) {
      Comp comp(rank, k);
      sort(sa.begin(), sa.end(), comp);
      vector<int> tmp(n + 1);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; ++i) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (comp(sa[i - 1], sa[i]) ? 1 : 0);
      }
      rank = tmp;
    }
  }

  vector<int> getArray() const {
    return sa;
  }

  int lower_bound(const string &T) const {
    int a = 0, b = sa.size();
    while (b - a > 1) {
      int c = (a + b) / 2;
      if (S.compare(sa[c], T.size(), T) < 0) a = c;
      else b = c;
    }
    return b;
  }

  int upper_bound(const string &T) const {
    int a = 0, b = sa.size();
    while (b - a > 1) {
      int c = (a + b) / 2;
      if (S.compare(sa[c], T.size(), T) <= 0) a = c;
      else b = c;
    }
    return b;
  }

  bool contain(const string &T) const {
    return S.compare(sa[lower_bound(T)], T.size(), T) == 0;
  }

};

typedef int elm;

class SegmentTree {
private:
  int n;
  vector<vector<elm> > dat;

public:
  SegmentTree(const vector<elm> &A) {
    n = 1;
    while (n < A.size()) n *= 2;
    dat = vector<vector<elm> >(n*2-1);
    n = A.size();
    init(0, 0, A.size(), A);
  }

  void init(int k, int l, int r, const vector<elm> &A) {
    if (r - l == 1) {
      dat[k].push_back(A[l]);
    } else {
      int lch = k * 2 + 1, rch = k * 2 + 2;
      init(lch, l, (l + r) / 2, A);
      init(rch, (l + r) / 2, r, A);
      dat[k].resize(r - l);
      merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(),
            dat[k].begin());
    }
  }

  int query(int i, int j, elm x, int k = 0, int l = 0, int r = -1) {
    if (r == -1) r = n;
    if (j <= l || r <= i) {
      return 0;
    } else if (i <= l && r <= j) {
      return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    } else {
      int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
      int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
      return lc + rc;
    }
  }
};

int main() {
  string S;
  int Q;
  while (cin >> S >> Q) {
    SuffixArray suf(S);
    vector<int> sa = suf.getArray(); 
    for (int i = 0; i < sa.size(); ++i) {
      sa[i] = -sa[i];
    }
    SegmentTree seg(sa);
    while (Q--) {
      int l, r;
      string M;
      cin >> l >> r >> M;
      int a = suf.lower_bound(M);
      int b = suf.upper_bound(M);
      int s = l;
      int t = r - M.size() + 2;
      int ans = seg.query(a, b, -s) - seg.query(a, b, -t);
      cout << ans << endl;
    }
  }
  return 0;
}
