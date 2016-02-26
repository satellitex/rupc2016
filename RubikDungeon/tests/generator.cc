#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
  registerGen(argc, argv,1);
  for(int t=0; t<20; t++) {
    //ofstream ofs(format("03_random_%02d.in",t).c_str());
    ofstream ofs(format("05_random_%02d.in",t).c_str());
    int n;
    if(t<10) n=rnd.next(2,10);
    else n=rnd.next(2,100000);
    ofs << n << endl;
    int x=rnd.next(0,n-1),y=rnd.next(0,n-1),z=rnd.next(0,n-1);
    ofs << x << " " << y << " " << z << endl;
    int xx=x,yy=y,zz=z;
    while(xx==x&&yy==y&&zz==z) xx=rnd.next(0,n-1),yy=rnd.next(0,n-1),zz=rnd.next(0,n-1);
    ofs << xx << " " << yy << " " << zz << endl;
    ofs.close();
  }
  return 0;
}
