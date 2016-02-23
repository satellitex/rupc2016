#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 8;
const int X_MIN = -100;
const int X_MAX = 100;
const int Y_MIN = -100;
const int Y_MAX = 100;

// 入力変数
int n;
int x[N_MAX], y[N_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readEoln();

  for (int i = 0; i < n; ++i) {
    x[i] = inf.readInt(X_MIN, X_MAX, format("x[%d]", i));
    inf.readSpace();
    y[i] = inf.readInt(Y_MIN, Y_MAX, format("y[%d]", i));
    inf.readEoln();
  }

  inf.readEof();
}

void check() {
  // (xi,yi) ≠ (xj,yj)
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      ensuref(!(x[i] == x[j] && y[i] == y[j]),
              "%dth star and %dth star are at the same location (%d, %d)",
              i, j, x[i], y[i]);
    }
  }
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
