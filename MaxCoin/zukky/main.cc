#include <bits/stdc++.h>
using namespace std;

const int MAXN = 111;
const int MAXA = 333;
const int MAXB = 666;
const int OFFSET = MAXB / 2;

int n;
int x, y;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int dp[MAXA][MAXB];

int main() {
  while (cin >> n) {
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    memset(dp, -1, sizeof(dp));
    dp[x][OFFSET+y] = 0;
    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < MAXA; ++i) {
        for (int j = 0; j < MAXB; ++j) {
          if (dp[i][j] == -1) continue;
          if (i - a[k] >= 0 && j + b[k] < MAXB) {
            dp[i-a[k]][j+b[k]] = max(dp[i-a[k]][j+b[k]],
                                     dp[i][j]);
          }
          if (j - c[k] >= 0) {
            dp[i][j-c[k]] = max(dp[i][j-c[k]],
                                dp[i][j] + d[k]);
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < MAXA; ++i) {
      for (int j = OFFSET; j < MAXB; ++j) {
        res = max(res, dp[i][j]);
      }
    }
    cout << res << endl;
  }
  return 0;
}
