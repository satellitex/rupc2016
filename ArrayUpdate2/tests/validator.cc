#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 200000;
const int A_MIN = 1;
const int A_MAX = 5;
const int D_MIN = 1;
const int D_MAX = 5;
const int M_MIN = 1;
const int M_MAX = 200000;
const int X_MIN = 0;
const int X_MAX = 2;

// 入力変数
int N, a, d, M, K;
int x[M_MAX], y[M_MAX], z[M_MAX];

void input() {
  N = inf.readInt(N_MIN, N_MAX, "N");
  inf.readEoln();

  a = inf.readInt(A_MIN, A_MAX, "a");
  inf.readSpace();
  d = inf.readInt(D_MIN, D_MAX, "d");
  inf.readEoln();

  M = inf.readInt(M_MIN, M_MAX, "M");
  inf.readEoln();

  for (int i = 0; i < M; ++i) {
    x[i] = inf.readInt(X_MIN, X_MAX, format("x[%d]", i + 1));
    inf.readSpace();
    y[i] = inf.readInt(1, N, format("y[%d]", i + 1));
    inf.readSpace();
    z[i] = inf.readInt(1, N, format("z[%d]", i + 1));
    // y_i < z_i
    ensuref(y[i] < z[i], "'y[i]' must be less than 'z[i]'");
    inf.readEoln();
  }

  K = inf.readInt(1, N, "K");
  inf.readEoln();

  inf.readEof();
}

void check() {
  return;
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
