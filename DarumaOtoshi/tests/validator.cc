#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 500;
const int A_MIN = 1;
const int A_MAX = 1000;

// 入力変数
int N;
int A[N_MAX];

void input() {
  N = inf.readInt(N_MIN, N_MAX, "N");
  // N は 2 の倍数
  ensuref(N % 2 == 0, "Input 'N' must be even");
  inf.readEoln();

  for (int i = 0; i < N; ++i) {
    if (i > 0) {
      inf.readSpace();
    }
    A[i] = inf.readInt(A_MIN, A_MAX, format("A[%d]", i));
  }
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
