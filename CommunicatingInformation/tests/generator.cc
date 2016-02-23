#include "testlib.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    int n, m;
    for (int t = 0; t < 15; t++) {
        ofstream of(format("03_random_%02d.in", t+1).c_str());
        n = rnd.next(2, 100000);
        m = rnd.next(1, n);
        of << n << " " << m << endl;
        vector<int> a(m);
        bool used[100001] = {0};
        for (int i = 0; i < m; i++) {
            a[i] = rnd.next(1, n);
            if (used[a[i]]) {
                i--;                
            } else {
                used[a[i]] = 1;
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < m; i++) {
            if (i > 0) {
                of << " ";
            }
            of << a[i];
        }
        of << endl;
        of.close();
    }
    return 0;
}
