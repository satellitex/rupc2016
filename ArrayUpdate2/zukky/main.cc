#include <bits/stdc++.h>
using namespace std;

const int MAXM = 200000;
int N, a, d, M, K;
int x[MAXM], y[MAXM], z[MAXM];

int main() {
  while (cin >> N) {
    cin >> a >> d;
    cin >> M;
    for (int i = 0; i < M; ++i) {
      cin >> x[i] >> y[i] >> z[i];
    }
    cin >> K;
    stack<int> op;
    for (int i = M-1; i >= 0; --i) {
      if (y[i] <= K && K <= z[i]) {
	if (x[i] == 0) {
	  K = y[i] + (z[i] - K);
	} else {
	  op.push(x[i]);
	}
      }
    }
    int ans = a + d * (K - 1);
    while (op.size()) {
      int x = op.top();
      op.pop();
      if (x == 1) {
	ans++;
      } else {
	ans /= 2;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
