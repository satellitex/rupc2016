#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
struct Seg{ P p,v; };

double eps=1e-10;
double distLP(P a,P b,P c){
  b-=a;c-=a;
  return abs(imag(c*conj(b)/abs(b)));
}
double distLP2(P a,P b,P c){
  b-=a;c-=a;
  return real(c*conj(b)/abs(b));
}

vector<Seg> getLine(P a,double ra,P b,double rb,double flg=1.0){
  double e=norm(b-a),f=rb-ra*flg;
  P base=(b-a)*P(-f*flg,sqrt(e-f*f))/e;
  vector<Seg> res;
  res.push_back((Seg){a+base*ra,b+base*rb*flg});
  base=conj(base);
  res.push_back((Seg){a+base*ra,b+base*rb*flg});
  return res;
}

int n;
vector< P > t;
vector<double> r;
set<int> E;
int dp[(1<<15)];

void solve(){
  memset( dp , 1 , sizeof(dp) );
  dp[0]=0;
  vector<int> e;
  set<int> :: iterator it;
  for(it=E.begin();it!=E.end();it++)e.push_back(*it);
  for(int S=0;S<(1<<n);S++){
    for(int i=0;i<(int)e.size();i++){
      int bit=e[i];
      dp[S|bit]=min(dp[S|bit],dp[S]+1);
    }
  }
  cout<<dp[(1<<n)-1]<<endl;
}

void calc(Seg se){
  if(distLP(se.p,se.v,t[n])>r[n]+eps)return;
  int S=0,T=0;
  double key=distLP2(se.p,se.v,t[n]);
  for(int i=0;i<n;i++){
    if(distLP(se.p,se.v,t[i])<=r[i]+eps){
      if(distLP2(se.p,se.v,t[i])<key)S|=(1<<i);
      else T|=(1<<i);
    }
  }
  E.insert(S);E.insert(T);
}


int main(){
  cin>>n;n--;
  t.resize(n+1);
  r.resize(n+1);

  double px,py;
  cin>>px>>py>>r[n];
  t[n]=P(px,py);
  for(int i=0;i<n;i++){
    cin>>px>>py>>r[i];
    t[i]=P(px,py);
  }
  
  vector<Seg> vec;
  for(int i=0;i+1<=n;i++){
    for(int j=i+1;j<=n;j++){
      for(int k=-1;k<=1;k+=2){
        vec=getLine(t[i],r[i],t[j],r[j],k);
        calc(vec[0]);calc(vec[1]);
      }
    }
  }
  solve();
  return 0;
}
