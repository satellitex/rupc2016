#include <bits/stdc++.h>
using namespace std;

const int MAXM = 100005;
int n, m;
int a[MAXM];

int main() {
  while (cin >> n >> m) {
    for (int i = 1; i <= m; ++i) {
      cin >> a[i];
    }
    int res = max(a[1] - 1, n - a[m]);
    for (int i = 1; i+1 <= m; ++i) {
      int mid = (a[i] + a[i+1]) / 2;
      res = max(res, mid - a[i]);
    }
    cout << res << endl;
  }
  return 0;
}
