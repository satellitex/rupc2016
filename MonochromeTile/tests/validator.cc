#include "testlib.h"
using namespace std;

// 制約
const int W_MIN = 1;
const int W_MAX = 100000;
const int H_MIN = 1;
const int H_MAX = 100000;
const int N_MIN = 1;
const int N_MAX = 200000;

// 入力変数
int W, H, N;
int ax[N_MAX], ay[N_MAX], bx[N_MAX], by[N_MAX];

void input() {
  W = inf.readInt(W_MIN, W_MAX, "W");
  inf.readSpace();
  H = inf.readInt(H_MIN, H_MAX, "H");
  inf.readEoln();

  N = inf.readInt(N_MIN, N_MAX, "N");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    ax[i] = inf.readInt(1, W, format("ax[%d]", i + 1));
    inf.readSpace();
    ay[i] = inf.readInt(1, H, format("ay[%d]", i + 1));
    inf.readSpace();
    bx[i] = inf.readInt(1, W, format("bx[%d]", i + 1));
    inf.readSpace();
    by[i] = inf.readInt(1, H, format("by[%d]", i + 1));
    inf.readEoln();
    // ax_i <= bx_i
    ensuref(ax[i] <= bx[i],
            "ax[i] must be less than or equal to bx[i]");
    // ay_i <= by_i
    ensuref(ay[i] <= by[i],
            "ay[i] must be less than or equal to by[i]");
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
