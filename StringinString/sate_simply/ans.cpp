#include<bits/stdc++.h>
using namespace std;

string S;
int Q;

int solve(int l,int r,const string &m){
  int n = m.size();
  int res = 0;
  for(int i=l;i<=r-n+1;i++){
    if( S.substr(i,n) == m ) res++;
  }
  return res;
}

int main(){
  cin >> S >> Q; 
  for(int i=0;i<Q;i++){
    int l,r; string m;
    cin >> l >> r >> m;
    cout << solve(l,r,m) << endl;        
  }
}
