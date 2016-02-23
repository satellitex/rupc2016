#include "testlib.h"
using namespace std;

// 制約
const int N_MIN = 2;
const int N_MAX = 100000;
const int X_MIN = 0;
const int Y_MIN = 0;
const int Z_MIN = 0;

// 入力変数
int n, x_1, y_1, z_1, x_2, y_2, z_2;

void input() {
  n = inf.readInt(N_MIN, N_MAX, "n");
  inf.readEoln();

  x_1 = inf.readInt(X_MIN, n - 1, "x_1");
  inf.readSpace();
  y_1 = inf.readInt(Y_MIN, n - 1, "y_1");
  inf.readSpace();
  z_1 = inf.readInt(Z_MIN, n - 1, "z_1");
  inf.readEoln();

  x_2 = inf.readInt(X_MIN, n - 1, "x_2");
  inf.readSpace();
  y_2 = inf.readInt(Y_MIN, n - 1, "y_2");
  inf.readSpace();
  z_2 = inf.readInt(Z_MIN, n - 1, "z_2");
  inf.readEoln();

  inf.readEof();
}

void check() {
  // (x1,y1,z1) ≠ (x2,y2,z2)
  ensuref(!(x_1 == x_2 && y_1 == y_2 && z_1 == z_2),
          "Current location and treasure location are the same (%d, %d, %d)",
          x_1, y_1, z_1);
}

int main() {
  registerValidation();

  input();

  check();

  return 0;
}
