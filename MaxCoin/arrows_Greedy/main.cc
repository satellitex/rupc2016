/*
  銅->銀で交換効率の良いものから優先で選んでいき、
  銀->金で交換効率の良いものから優先で選んでいく。
  
  サンプルは通るが、01_small_01.inで落ちる
 */

#include <bits/stdc++.h>

using namespace std;

class Cocoa {
  public:
    int idx, a, b, c, d;
    double cs_eff, sg_eff;
};

bool cmp_cs(Cocoa a, Cocoa b)
{
    if (a.cs_eff != b.cs_eff) {
        return a.cs_eff > b.cs_eff;
    }
    return a.sg_eff < b.sg_eff;
}

bool cmp_sg(Cocoa a, Cocoa b)
{
   if (a.sg_eff != b.sg_eff) {
        return a.sg_eff > b.sg_eff;
    }
    return a.cs_eff < b.cs_eff;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<Cocoa> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i].a >> c[i].b >> c[i].c >> c[i].d;
        c[i].idx = i;
        c[i].cs_eff = (double)c[i].b/c[i].a;
        c[i].sg_eff = (double)c[i].d/c[i].c;
    }
    vector<bool> used(n, 0);
    sort(c.begin(), c.end(), cmp_cs);
    for (int i = 0; i < n; i++) {
        if (c[i].a <= x) {
            x -= c[i].a;
            y += c[i].b;
            used[c[i].idx] = 1;
        }        
    }
    sort(c.begin(), c.end(), cmp_sg);
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
