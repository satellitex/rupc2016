#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;
const int M_MIN = 1;
const int A_MIN = 1;

// 入力変数
int n, m;
int a[N_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readSpace();
  m = inf.readInt(M_MIN, n, "m");
  inf.readEoln();

  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    a[i] = inf.readInt(A_MIN, n, format("a[%d]", i + 1));
  }
  inf.readEoln();

  inf.readEof();
}

void check() {
  // aiの値は全て異なる。
  // aiは昇順で与えられる。
  for (int i = 0; i+1 < m; ++i) {
    ensuref(a[i] < a[i+1], "a[i] must be the ascending order");
  }
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
