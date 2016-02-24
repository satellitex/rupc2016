#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 16;
const int XY_MIN = -100;
const int XY_MAX = 100;
const int R_MIN = 1;
const int R_MAX = 100;

// 入力変数
int N;
int x[N_MAX], y[N_MAX], r[N_MAX];

void input() {
  N = inf.readInt(N_MIN, N_MAX, "N");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    x[i] = inf.readInt(XY_MIN, XY_MAX, format("x[%d]", i + 1));
    inf.readSpace();
    y[i] = inf.readInt(XY_MIN, XY_MAX, format("y[%d]", i + 1));
    inf.readSpace();
    r[i] = inf.readInt(R_MIN, R_MAX, format("r[%d]", i + 1));
    inf.readEoln();
  }

  inf.readEof();
}

void check() {
  // Nつの円はそれぞれ互いに共通部分をもっていない
  // 接しているのもNG
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      ensuref(dist > (r[i] + r[j]) * (r[i] + r[j]),
              "Two circles must not have a common part");
    }
  }
  return;
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
