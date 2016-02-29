/*
  銅->銀の効率 - 銀->金の効率
  の大きい順からxがなくなるまで選んでいき、
  
  その後、
  銅->銀の効率 - 銀->金の効率
  の小さい順からyがなくなるまで選んでいく。
  
  サンプルは通るが、01_small_01.inで落ちる。
 */

#include <bits/stdc++.h>

using namespace std;

class Cocoa {
  public:
    int idx, a, b, c, d;
    double eff;
};

bool cmp(Cocoa a, Cocoa b)
{
    return a.eff < b.eff;
}

bool cmp_r(Cocoa a, Cocoa b)
{
    return a.eff > b.eff;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<Cocoa> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].a >> c[i].b >> c[i].c >> c[i].d;
        c[i].idx = i;
        c[i].eff = (double)c[i].b/c[i].a - (double)c[i].d/c[i].c;
    }
    vector<bool> used(n, 0);
    sort(c.begin(), c.end(), cmp_r);
    for (int i = 0; i < n; i++) {
        if (c[i].a <= x) {
            x -= c[i].a;
            y += c[i].b;
            used[c[i].idx] = 1;
        }        
    }
    sort(c.begin(), c.end(), cmp);
    int z = 0;
    for (int i = 0; i < n; i++) {
        if (!used[c[i].idx] && c[i].c <= y) {
            y -= c[i].c;
            z += c[i].d;
        }
    }
    cout << z << endl;
    return 0;
}
