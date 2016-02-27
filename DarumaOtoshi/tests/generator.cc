#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

void gen(string name,int n,int maxa){
  ofstream of(name.c_str());
  of << n << endl;
  for(int i=0;i<n;i++){
    if( i ) of << " ";
    of << rnd.next(1,maxa);
  }
  of << endl;
  of.close();
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (int t = 0; t < 10; t++) {
      gen(format("01_small_%02d.in", t+1).c_str(),20,10);
    }
    for (int t = 0; t < 20; t++) {
      gen(format("02_large_%02d.in", t+1).c_str(),500,1000);
    }

    return 0;
}
