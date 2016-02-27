#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;

const double eps = 1e-8;

bool equals(double a, double b) { return abs(a - b) < eps; }

struct L : public vector<P> {
  L(P a, P b) {
    push_back(a), push_back(b);
  }
};

struct C {
  P p;
  double r;
  C() {}
  C(P p, double r) : p(p), r(r) {}
};

double dot(P a, P b) {
  return a.real()*b.real() + a.imag()*b.imag();
}

double cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}

P project(P s1, P s2, P p) {
  P base = s2 - s1;
  double t = dot(p - s1, base)/norm(base);
  return s1 + base*t;
}

double getDistanceLP(P s1, P s2, P p) {
  return abs(cross(s2 - s1, p - s1)/abs(s2 - s1));
}

int isIntersect(P s1, P s2, C c) {
  double d = getDistanceLP(s1, s2, c.p);
  if(equals(d, c.r)) return 1;
  else if(d < c.r) return 2;
  else return 0;
}

vector<P> getCrossPLC(P s1, P s2, C c) {
  vector<P> v;
  P p = project(s1, s2, c.p);
  if(isIntersect(s1, s2, c) == 1) {
    v.push_back(p);
  } else {
    double h = abs(p - c.p);
    double d = sqrt(c.r*c.r - h*h);
    P base = s2 - s1;
    v.push_back(p + d*base/abs(base));
    v.push_back(p - d*base/abs(base));
  }
  return v;
}

int isIntersect(C a, C b) {
  double x = a.p.real() - b.p.real();
  double y = a.p.imag() - b.p.imag();
  double s = a.r + b.r;
  double d = x*x + y*y;
  s *= s;
  if(equals(d, s)) return 1;
  if(d > s) return 0;
  double r = abs(a.r - b.r);
  r *= r;
  if(equals(d, r)) return -1;
  if(d > r) return 2;
  return -2;
}

vector<P> getCrossP(C c1, C c2) {
  vector<P> v;
  int cp = isIntersect(c1,c2);
  if(cp == 0 || cp == -2) return v;
  
  double ll = norm(c1.p - c2.p);
  double A = ( c1.r * c1.r - c2.r * c2.r + ll ) / ( 2.0 * ll );
  P base = c2.p - c1.p;

  if(abs(cp) == 1) {
    v.push_back(c1.p + A*base);
  } else {
    P n(-base.imag(), base.real());
    n /= abs(n);
    double h = sqrt(c1.r * c1.r - A*A*ll);
    v.push_back(c1.p + A*base + h*n);
    v.push_back(c1.p + A*base - h*n);
  }
  return v;
}

vector<L> getLine(C a, C b) {
  vector<L> res;
  bool swapped = false;
  if (a.r > b.r) {
    swap(a, b);
    swapped = true;
  }
  int c = isIntersect(a, b);

  if (c == -2) {
    // there are no lines
  } else if (abs(c) == 1) {
    P cp = getCrossP(a, b)[0];
    P base = b.p - a.p;
    P n(-base.imag(), base.real());
    res.push_back(L(cp, cp + n));
  } else {
    {
      if (a.r == b.r) {
        P base = b.p - a.p;
        P n(-base.imag(), base.real());
        n /= abs(n);
        res.push_back(L(a.p + n * a.r, b.p + n * a.r));
        res.push_back(L(a.p - n * a.r, b.p - n * a.r));
      } else {
        double h = b.r - a.r;
        double x = sqrt(norm(a.p - b.p) - h * h);
        vector<P> ps = getCrossP(C(b.p, h), C(a.p, x));
        for (int i = 0; i < ps.size(); ++i) {
          P n = ps[i] - b.p;
          n /= abs(n);
          res.push_back(L(a.p + n * a.r, ps[i] + n * a.r));
        }
      }
    }
    {
      double h = b.r + a.r;
      double x = sqrt(norm(a.p - b.p) - h * h);
      vector<P> ps = getCrossP(C(b.p, h), C(a.p, x));
      for (int i = 0; i < ps.size(); ++i) {
        P n = b.p - ps[i];
        n /= abs(n);
        res.push_back(L(a.p + n * a.r, ps[i] + n * a.r));
      }
    }
  }

  if (swapped) {
    for (int i = 0; i < res.size(); ++i) {
      swap(res[i][0], res[i][1]);
    }
  }
  return res;
}

const int MAXN = 16;
const int INF = 1<<28;

int N;
C cs[MAXN];
int dp[1<<MAXN];

int getMask(P s, P t) {
  int res = 0;
  for (int i = 1; i < N; ++i) {
    vector<P> ps = getCrossPLC(s, t, cs[i]);
    if (ps.size() >= 1 && dot(t - s, ps[0] - s) > 0) {
      res |= 1 << i;
    }
  }
  return res;
}

int main() {
  while (cin >> N) {
    for (int i = 0; i < N; ++i) {
      cin >> cs[i].p.real() >> cs[i].p.imag() >> cs[i].r;
    }

    vector<L> ls;
    for (int i = 0; i < N; ++i) {
      for (int j = i+1; j < N; ++j) {
        vector<L> v = getLine(cs[i], cs[j]);
        for (int k = 0; k < v.size(); ++k) {
          ls.push_back(v[k]);
        }
      }
    }

    vector<int> mask;
    for (int i = 1; i < N; ++i) {
      mask.push_back(1 << i);
    }

    for (int i = 0; i < ls.size(); ++i) {
      vector<P> ps = getCrossPLC(ls[i][0], ls[i][1], cs[0]);
      if (ps.size() >= 1) {
        P base = ls[i][1] - ls[i][0];
        mask.push_back(getMask(ps[0], ps[0] + base));
        mask.push_back(getMask(ps[0], ps[0] - base));
      }
    }

    fill(dp, dp + (1<<MAXN), INF);
    dp[1] = 0;
    for (int i = 0; i < (1<<N); ++i) {
      for (int j = 0; j < mask.size(); ++j) {
        dp[i|mask[j]] = min(dp[i|mask[j]], dp[i] + 1);
      }
    }
    cout << dp[(1<<N)-1] << endl;
  }
  return 0;
}
