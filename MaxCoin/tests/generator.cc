#include "testlib.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n, x, y;
    for (int t = 0; t < 30; t++) {
        ofstream of(format("03_random_%02d.in", t+1).c_str());
        n = rnd.next(1, 100);
        of << n << endl;
        x = rnd.next(0, 300);
        y = rnd.next(0, 300);
        of << x << " " << y << endl;
        
        vector<int> a(n), b(n), c(n), d(n);
        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(1, 300/n);
            b[i] = rnd.next(1, 300/n);
            c[i] = rnd.next(1, 300/n);
            d[i] = rnd.next(1, 300/n);
        }
        for (int i = 0; i < n; i++) {
            of << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << endl;
        }
        
        of.close();
    }
    return 0;
}
