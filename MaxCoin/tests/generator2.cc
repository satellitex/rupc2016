#include "testlib.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n, x, y;
    for (int t = 15; t < 30; t++) {
        ofstream of(format("03_random_%02d.in", t+1).c_str());
        n = rnd.next(1, 100);
        of << n << endl;
        x = rnd.next(0, 300);
        y = rnd.next(0, 300);
        of << x << " " << y << endl;
        
        int a_rem = 300, b_rem = 300, c_rem = 300, d_rem = 300;
        vector<int> a(n), b(n), c(n), d(n);
        for (int i = 0; i < n; i++) {
            int amax = a_rem - n + i + 1;
            int bmax = b_rem - n + i + 1;
            int cmax = c_rem - n + i + 1;
            int dmax = d_rem - n + i + 1;
            a[i] = rnd.next(1, min(rnd.next(1, 50), amax)); a_rem -= a[i];
            b[i] = rnd.next(1, min(rnd.next(1, 50), bmax)); b_rem -= b[i];
            c[i] = rnd.next(1, min(rnd.next(1, 50), cmax)); c_rem -= c[i];
            d[i] = rnd.next(1, min(rnd.next(1, 50), dmax)); d_rem -= d[i];
        }
        for (int i = 0; i < n; i++) {
            of << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
        }
        
        of.close();
    }
    return 0;
}
