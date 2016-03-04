#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef pair<int,int> P;
const int INF=1<<29;
set<P> s;

int main(int argc, char* argv[]) {
  registerGen(argc, argv,1);
  for(int t=0; t<10; t++) {
    s.clear();
    //ofstream ofs(format("03_random_%02d.in",t).c_str());
    ofstream ofs(format("05_random_%02d.in",t).c_str());
    int n=rnd.next(2, 8);
    ofs << n << endl;
    s.insert(P(INF,INF));
    for(int i=0; i<n; i++) {
      P p=P(INF,INF);
      while(s.count(p)) p=P(rnd.next(-100,100),rnd.next(-100,100));
      //while(s.count(p)) p=P(rnd.next(0,5),rnd.next(0,5));
      ofs << p.first << " " << p.second << endl;
      s.insert(p);
    }
    ofs.close();
  }
  return 0;
}
