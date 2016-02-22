#include <bits/stdc++.h>
using namespace std;
double INF=1<<29;
typedef long long ll;
typedef complex<double> P;
typedef pair<int,int> PP;
namespace std {
  bool operator < (const P& a, const P& b) {
    return real(a)!=real(b)?real(a)<real(b):imag(a)<imag(b);
  }
}
int p[10],r[10];
void init(){for(int i=0;i<10;i++)p[i]=i,r[i]=0;}
int find(int x){return (p[x]==x)?x:(p[x]=find(p[x]));}
void unite(int x,int y) {
  x=find(x),y=find(y);
  if(x==y)return;
  if(r[x]<r[y])p[x]=y;
  else{p[y]=x;if(r[x]==r[y])r[x]++;}
}
bool same(int x,int y){return find(x)==find(y);}

P PerpendicularBisector(P a,P b) {
  double x,y;
  if(b.imag()-a.imag()) {
    x=-(b.real()-a.real())/(b.imag()-a.imag());
    y=-(a.real()+b.real())/2*x+(a.imag()+b.imag())/2;
  } else {
    x=INF;
    y=(a.imag()+b.imag())/2;
  }
  if(x==-0) x=0;
  return P(x,y);
}

P a[10];
int n,k,ans;
map<P,vector<PP> > m;
map<int,P> ma;
int c;
void dfs(int l, ll t) {
  bool f=1;
  for(int i=1; i<n; i++) {
    if(!same(0,i)) {
      f=0;
      break;
    }
  }
  int e=__builtin_popcount(t);
  if(f) ans=min(ans,e);
  if(e>=n-2) return;
  for(int i=l; i<k; i++) {
    int pp[n],rr[n];
    for(int j=0; j<n; j++) pp[j]=p[j],rr[j]=r[j];
    vector<PP> v=m[ma[i]];
    for(int j=0; j<v.size(); j++) unite(v[j].first,v[j].second);
    dfs(i+1,t|(1<<i));
    for(int j=0; j<n; j++) p[j]=pp[j],r[j]=rr[j];
  }
}

int main() {
  cin >> n;
  for(int i=0,x,y; i<n; i++) {
    cin >> x >> y;
    a[i]=P(x,y);
  }
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) m[PerpendicularBisector(a[i],a[j])].push_back(PP(i,j));
  }
  k=0;
  for(map<P,vector<PP> >::iterator it=m.begin();it!=m.end();it++) ma[k++]=it->first;
  init();
  ans=n-1;
  dfs(0,0);
  cout << ans << endl;
  return 0;
}
