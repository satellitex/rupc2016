#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 1;
const int N_MAX = 100;
const int X_MIN = 0;
const int X_MAX = 300;
const int Y_MIN = 0;
const int Y_MAX = 300;
const int A_MIN = 1;
const int A_MAX = 300;
const int B_MIN = 1;
const int B_MAX = 300;
const int C_MIN = 1;
const int C_MAX = 300;
const int D_MIN = 1;
const int D_MAX = 300;
const int SUM_OF_A_MIN = 1;
const int SUM_OF_A_MAX = 300;
const int SUM_OF_B_MIN = 1;
const int SUM_OF_B_MAX = 300;
const int SUM_OF_C_MIN = 1;
const int SUM_OF_C_MAX = 300;
const int SUM_OF_D_MIN = 1;
const int SUM_OF_D_MAX = 300;

// 入力変数
int n, x, y;
int a[N_MAX], b[N_MAX], c[N_MAX], d[N_MAX];

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readEoln();

  x = inf.readInt(X_MIN, X_MAX, "x");
  inf.readSpace();
  y = inf.readInt(Y_MIN, Y_MAX, "y");
  inf.readEoln();

  for (int i = 0; i < n; ++i) {
    a[i] = inf.readInt(A_MIN, A_MAX, format("a[%d]", i + 1));
    inf.readSpace();
    b[i] = inf.readInt(B_MIN, B_MAX, format("b[%d]", i + 1));
    inf.readSpace();
    c[i] = inf.readInt(C_MIN, C_MAX, format("c[%d]", i + 1));
    inf.readSpace();
    d[i] = inf.readInt(D_MIN, D_MAX, format("d[%d]", i + 1));
    inf.readEoln();
  }

  inf.readEof();
}

void check() {
  // 1 ≦ Σai, Σbi, Σci, Σdi ≦ 300
  int sum_of_a = 0;
  int sum_of_b = 0;
  int sum_of_c = 0;
  int sum_of_d = 0;

  for (int i = 0; i < n; ++i) {
    sum_of_a += a[i];
    sum_of_b += b[i];
    sum_of_c += c[i];
    sum_of_d += d[i];
  }

  ensuref(SUM_OF_A_MIN <= sum_of_a && sum_of_a <= SUM_OF_A_MAX,
          "Sum of a[i] equals to %d, violates the range [%d, %d]",
          sum_of_a, SUM_OF_A_MIN, SUM_OF_A_MAX);
  ensuref(SUM_OF_B_MIN <= sum_of_b && sum_of_b <= SUM_OF_B_MAX,
          "Sum of b[i] equals to %d, violates the range [%d, %d]",
          sum_of_b, SUM_OF_B_MIN, SUM_OF_B_MAX);
  ensuref(SUM_OF_C_MIN <= sum_of_c && sum_of_c <= SUM_OF_C_MAX,
          "Sum of c[i] equals to %d, violates the range [%d, %d]",
          sum_of_c, SUM_OF_C_MIN, SUM_OF_C_MAX);
  ensuref(SUM_OF_D_MIN <= sum_of_d && sum_of_d <= SUM_OF_D_MAX,
          "Sum of d[i] equals to %d, violates the range [%d, %d]",
          sum_of_d, SUM_OF_D_MIN, SUM_OF_D_MAX);
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
