#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 1;
const int N_MAX = 40000;
const int M_MIN = 1;
const int M_MAX = 40000;
const int Q_MIN = 1;
const int Q_MAX = 100000;
const int A_MIN = 1;
const int A_MAX = 5;
const int B_MIN = 1;
const int B_MAX = 5;
const int C_MIN = 0;
const int C_MAX = 200000;

// 入力変数
int n, m, q;
int a[N_MAX], b[M_MAX], c[Q_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  m = inf.readInt(M_MIN, M_MAX, "m");
  inf.readSpace();
  q = inf.readInt(Q_MIN, Q_MAX, "q");
  inf.readEoln();

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    a[i] = inf.readInt(A_MIN, A_MAX, format("a[%d]", i));
  }
  inf.readEoln();

  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    b[i] = inf.readInt(B_MIN, B_MAX, format("b[%d]", i));
  }
  inf.readEoln();

  for (int i = 0; i < q; ++i) {
    c[i] = inf.readInt(C_MIN, C_MAX, format("c[%d]", i));
    inf.readEoln();
  }

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
