#include "testlib.h"
using namespace std;

// 制約
const int W_MIN = 4;
const int W_MAX = 100;
const int H_MIN = 4;
const int H_MAX = 100;
const int N_MIN = 0;
int N_MAX = 100;
const int N_MAX_MAX = W_MAX*2+H_MAX-2 - 1;
const int P_MIN = 0;
const int P_MAX = 1;

// 入力変数
int W, H, N;
int p[N_MAX_MAX];

void input() {
  W = inf.readInt(W_MIN, W_MAX, "W");
  inf.readSpace();
  H = inf.readInt(H_MIN, H_MAX, "H");
  inf.readEoln();

  N_MAX = (W*2 + H - 2) - 1;

  N = inf.readInt(N_MIN, N_MAX, "N");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    p[i] = inf.readInt(P_MIN, P_MAX, format("p[%d]", i + 1));
  }
  inf.readEoln();

  inf.readEof();
}

void check() {
  // ただし、島村卯明くんまたは目黒凛くんが列から出ることはない。
  int left_num  = W * 2 + H - 2;
  int right_num = left_num - 4;
  int zero_num = 0;
  int one_num = 0;
  for (int i = 0; i < N; ++i) {
    if (p[i] == 0) {
      zero_num++;
    }
    if (p[i] == 1) {
      one_num++;
    }
  }
  ensuref(zero_num < left_num, "Shimamura can't go out");
  ensuref(one_num < right_num, "Meguro can't go out");
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
