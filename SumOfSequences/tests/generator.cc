#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  for(int t=0; t<10; t++) {
    ofstream ofs(format("03_random_%02d.in",t).c_str());
    int n=rnd.next(1,40000),m=rnd.next(1,40000),q=rnd.next(1,100000);
    ofs << n << " " << m << " " << q << endl;
    for(int i=0; i<n; i++) {
      if(i) ofs << " ";
      ofs << rnd.next(1,5);
    }
    ofs << endl;
    for(int i=0; i<m; i++) {
      if(i) ofs << " ";
      ofs << rnd.next(1,5);
    }
    ofs << endl;
    for(int i=0; i<q; i++) ofs << rnd.next(0,200000) << endl;
    ofs.close();
  }
  return 0;
}
