#include "testlib.h"
#include<bits/stdc++.h>

using namespace std;

const int MAXSUM = 2000000;

string toString(int n){
  stringstream ss;
  ss << n;
  string a;
  ss >> a;
  return a;
}

void gen(string name,int n,int q,bool sizek){
  ofstream of(name);
  string S = rnd.next("[a-z]{"+toString(n)+"}");
  of << S << " "<< q << endl;
  for(int i=0;i<q;i++){
    int l = rnd.next(0,n-1);
    int r = rnd.next(l,n-1);
    string m;
    if( sizek )
      m = rnd.next("[a-z]{"+toString(MAXSUM/q)+"}");
    else
      m = rnd.next("[a-z]{1,"+toString(min(r-l+1,MAXSUM/q))+"}");
    of << l << " "<< r << " "<<m << endl;
  }
  of.close();
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (int t = 0; t < 10; t++) {
      gen(format("02_random_%02d.in", t+1).c_str(),rnd.next(1,100000),rnd.next(1,100000),false);
    }
    for (int t = 0; t < 10; t++) {
      gen(format("02_large_%02d.in", t+1).c_str(),100000,100000,true);
    }
    for (int t = 0; t < 5; t++) {
      gen(format("03_large_%02d.in", t+1).c_str(),100000,10,true);
    }
    for (int t = 0; t < 5; t++) {
      gen(format("04_large_%02d.in", t+1).c_str(),100000,1000,true);
    }


    return 0;
}
