#include<bits/stdc++.h>
using namespace std;
typedef complex<double> P;
struct Seg{ P p,v; };

double eps=1e-5;
double PI=acos(-1);

bool eq(double a,double b){return (b-a<eps&&a-b<eps);}
bool eq(P a,P b){return (abs(a-b)<eps);}

double dot(P a,P b){return real(b*conj(a));}
double cross(P a,P b){return imag(b*conj(a));}

double distLP(P a,P b,P c){
  b-=a;c-=a;
  return abs(imag(c*conj(b)/abs(b)));
}
double distLP2(P a,P b,P c){
  b-=a;c-=a;
  return real(c*conj(b)/abs(b));
}


vector<Seg> getLineA(P a,double ra,P b,double rb){
  double e=abs(b-a);
  double f=rb-ra;
  double g=sqrt(e*e-f*f);
  double cosF=g/e;
  double sinF=f/e;
  P base=(b-a)*P(-sinF,cosF)/e;
  vector<Seg> res;
  res.push_back((Seg){a+base*ra,b+base*rb});
  base=conj(base);
  res.push_back((Seg){a+base*ra,b+base*rb});
  return res;
}

vector<Seg> getLineB(P a,double ra,P b,double rb){
  double e=abs(b-a);
  double f=ra+rb;
  double g=sqrt(e*e-f*f);
  double cosG=f/e;
  double sinG=g/e;
  P base=(b-a)*P(cosG,sinG)/e;
  vector<Seg> res;
  res.push_back((Seg){a+base*ra,b-base*rb});
  base=conj(base);
  res.push_back((Seg){a+base*ra,b-base*rb});
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

typedef pair<double,int> Pair;

void calc(Seg se){

  
  if( distLP(se.p,se.v,t[n]) > r[n] +eps)return;
  
  vector< Pair > vec;
  for(int i=0;i<=n;i++)
    if( distLP(se.p,se.v,t[i]) <= r[i] +eps)
      vec.push_back( Pair(distLP2(se.p,se.v,t[i]),i) );

  int S=0;
  sort(vec.begin(),vec.end());
  for(int i=0;i<(int)vec.size();i++){
    int id=vec[i].second;
    if(id==n){
      E.insert(S);
      S=0;
    }else{
      S|=(1<<id);
    }
  }
  E.insert(S);
}


int main(){
  cin>>n;n--;
  t.resize(n+1);
  r.resize(n+1);
  for(int i=n;i>=n;i--){
    double px,py;
    cin>>px>>py>>r[i];
    t[i]=P(px,py);
  }
  for(int i=0;i<n;i++){
    double px,py;
    cin>>px>>py>>r[i];
    t[i]=P(px,py);
  }
  
  vector<Seg> vec;
  for(int i=0;i+1<=n;i++){
    for(int j=i+1;j<=n;j++){
      vec=getLineA(t[i],r[i],t[j],r[j]);
      calc(vec[0]);calc(vec[1]);
      vec=getLineB(t[i],r[i],t[j],r[j]);
      calc(vec[0]);calc(vec[1]);
    }
  }
  solve();
  return 0;
}

