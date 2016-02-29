/*
  データ生成に時間がかかります。
 */

#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    for (int t = 0; t < 10; t++) {
        ofstream of(format("03_random_%02d.in", t+1).c_str());
        int n, u, v = -1;
        n = rnd.next(2, 100000);
        u = rnd.next(1, n);
        v = u;
        while (u == v) {
            v = rnd.next(1, n);
        }
        of << n << " " << u << " " << v << endl;
        
        // 連結になるように入力しないといけない。
        vector<int> a(n-1), b(n-1);
        for (int i = 1; i < n; i++) {
            int par = rnd.next(0, i-1);
            a[i-1] = par; b[i-1] = i;
        }
        
        vector<int> node_num(n, -1);
        set<int> used; used.insert(-1);
        for (int i = 0; i < n; i++) {
            int v = -1;
            while (used.count(v) > 0) {
                v = rnd.next(1, n);
            }
            used.insert(v);
            node_num[i] = v;
        }
        
        for (int i = 0; i < n-1; i++) {
            of << node_num[a[i]] << " " << node_num[b[i]] << endl;
        }
        
        of.close();
    }
    return 0;
}
