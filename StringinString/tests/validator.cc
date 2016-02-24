#include "testlib.h"
#include <string>
using namespace std;

// 制約
const int S_LENGTH_MIN = 1;
const int S_LENGTH_MAX = 100000;
const int Q_MIN = 1;
const int Q_MAX = 100000;
const int M_LENGTH_MIN = 1;
const int M_LENGTH_MAX = 100000;
const int SUM_OF_M_LENGTH_MAX = 2000000;

// 入力変数
string S;
int Q;
int l[Q_MAX], r[Q_MAX];
string M[Q_MAX];

void input() {
  S = inf.readToken(format("[a-z]{%d,%d}", S_LENGTH_MIN, S_LENGTH_MAX), "S");
  inf.readSpace();
  Q = inf.readInt(Q_MIN, Q_MAX, "Q");
  inf.readEoln();

  int sum_of_m_length = 0;
  for (int i = 0; i < Q; ++i) {
    l[i] = inf.readInt(0, S.size() - 1, format("l[%d]", i));
    inf.readSpace();
    r[i] = inf.readInt(l[i], S.size() - 1, format("r[%d]", i));
    inf.readSpace();
    M[i] = inf.readToken(format("[a-z]{%d,%d}", M_LENGTH_MIN, M_LENGTH_MAX),
                         format("M[%d]", i));
    inf.readEoln();

    // 文字列Mの合計文字数は2000000を越えない。
    sum_of_m_length += M[i].size();
    ensuref(sum_of_m_length <= SUM_OF_M_LENGTH_MAX,
            "The total number of characters in 'M' must not be greater than %d",
            SUM_OF_M_LENGTH_MAX);
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
