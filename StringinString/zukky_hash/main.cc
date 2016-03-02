/**
 * 嘘解法その1
 * Sに対しMの長さのローリングハッシュを行い、
 * 各ハッシュ値に対応するインデクスの配列に対し二分探索を行う。
 */
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ulli;

const ulli B = 1000000007ULL;

struct Query {
  int l, r;
  string M;
  int id, ans;
};

bool comp1(const Query &a, const Query &b) {
  return a.M.size() < b.M.size();
}

bool comp2(const Query &a, const Query &b) {
  return a.id < b.id;
}

int main() {
  string S;
  int Q;
  while (cin >> S >> Q) {
    vector<Query> qs;
    for (int i = 0; i < Q; ++i) {
      Query q;
      cin >> q.l >> q.r >> q.M;
      q.id = i;
      qs.push_back(q);
    }

    sort(qs.begin(), qs.end(), comp1);

    for (int i = 0; i < Q; ) {
      int n = qs[i].M.size();
      map<ulli, vector<int> > m;
      {
        ulli hash = 0;
        ulli bn = 1;
        for (int j = 0; j < n; ++j) bn *= B;
        for (int j = 0; j < S.size(); ++j) {
          hash = hash * B + S[j];
          if (j >= n) {
            hash -= bn * S[j-n];
          }
          if (j >= n-1) {
            m[hash].push_back(j - n + 1);
          }
        }
      }
      while (i < Q && qs[i].M.size() == n) {
        if (qs[i].M.size() > qs[i].r - qs[i].l + 1) {
          qs[i].ans = 0;
        } else {
          ulli hash = 0;
          for (int j = 0; j < qs[i].M.size(); ++j) {
            hash = hash * B + qs[i].M[j];
          }
          qs[i].ans =
            upper_bound(m[hash].begin(), m[hash].end(), qs[i].r - n + 1)
            -lower_bound(m[hash].begin(), m[hash].end(), qs[i].l);
        }
        i++;
      }
    }

    sort(qs.begin(), qs.end(), comp2);
    for (int i = 0; i < qs.size(); ++i) {
      cout << qs[i].ans << endl;
    }
  }
  return 0;
}
