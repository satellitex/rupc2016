#include<bits/stdc++.h>
#include "testlib.h"
#include<fstream>
using namespace std;

const int MAXSUM = 2000000;

string toString(int n){
  stringstream ss;
  ss << n;
  string a;
  ss >> a;
  return a;
}

void gen(string name,int n,int q,bool sizek,int minmstr = 100000){
  ofstream of(name.c_str());
  string S = rnd.next("[a-z]{"+toString(n)+"}");
  of << S << " "<< q << endl;
  for(int i=0;i<q;i++){
    int l = rnd.next(0,n-1);
    int r = rnd.next(l,n-1);
    string m;
    if( sizek )
      m = rnd.next("[a-z]{"+toString(min(minmstr,MAXSUM/q))+"}");
    else
      m = rnd.next("[a-z]{1,"+toString(min(r-l+1,min(minmstr,MAXSUM/q)))+"}");
    of << l << " "<< r << " "<<m << endl;
  }
  of.close();
}

void gen2(string name,int n,int q,bool sizek,int minmstr = 100000){
  ofstream of(name.c_str());
  string S = rnd.next("[h-l]{"+toString(n)+"}");
  of << S << " "<< q << endl;
  for(int i=0;i<q;i++){
    int l = rnd.next(0,10);
    int r = rnd.next(n-10,n-1);
    string m;
    int see=rnd.next(1,1000);
    if( see == 1 ){
      m = "[a-c]{1,10}";
    } else if( see == 2 ){
      m = "[x-z]{1,10}";
    } else {
      if( sizek )
	m = rnd.next("[h-l]{"+toString(min(minmstr,MAXSUM/q))+"}");
      else
	m = rnd.next("[h-l]{1,"+toString(min(r-l+1,min(minmstr,MAXSUM/q)))+"}");   
    }
    of << l << " "<< r << " "<<m << endl;
  }
  of.close();
}

void gen3(string name,int n,int q,bool sizek,int minmstr=100000){
  ofstream of(name.c_str());
  string S = rnd.next("[h-i]{"+toString(n)+"}");
  of << S << " "<< q << endl;
  for(int i=0;i<q;i++){
    int l = rnd.next(0,1000);
    int r = rnd.next(n-1000,n-1);
    string m;
    int see=rnd.next(1,1000);
    if( see == 1 ){
      m = "[a-c]{1,10}";
    } else if( see == 2 ){
      m = "[x-z]{1,10}";
    } else {
      if( sizek )
	m = rnd.next("[h-i]{"+toString(min(minmstr,MAXSUM/q))+"}");
      else
	m = rnd.next("[h-i]{1,"+toString(min(minmstr,min(r-l+1,MAXSUM/q)))+"}");   
    }
    of << l << " "<< r << " "<<m << endl;
  }
  of.close();
}


int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);

    for (int t = 0; t < 20; t++) {
      if( t < 10 ) gen(format("01_small_%02d.in", t+1).c_str(),500,500,false,50);
      else gen2(format("01_small_%02d.in", t+1).c_str(),1000,1000,false,10);
    }
    
    for (int t = 0; t < 20; t++) {
      if( t < 10 ) gen(format("02_random_%02d.in", t+1).c_str(),rnd.next(1,100000),rnd.next(1,100000),false);
      else gen2(format("02_random_%02d.in", t+1).c_str(),rnd.next(1,100000),rnd.next(1,100000),false);
    }
    for (int t = 0; t < 10; t++) {
      if( t<5 ) gen(format("03_large_%02d.in", t+1).c_str(),100000,100000,false);
      else gen2(format("03_large_%02d.in", t+1).c_str(),100000,100000,false);
    }
    for (int t = 0; t < 5; t++) {
      gen2(format("04_large_%02d.in", t+1).c_str(),100000,50,false);
    }
    for (int t = 0; t < 5; t++) {
      gen2(format("05_large_%02d.in", t+1).c_str(),100000,1000,false);
    }
    gen3(format("06_corner_%02d.in", 1).c_str(),100000,100000,false);


    return 0;
}
