#include<bits/stdc++.h>
using namespace std;

int N;
typedef complex<double> P;
typedef pair<P,P> L;
P p[10];
const double EPS = 1e-8;
bool used[10][10];
int res;

double dot(P a,P b){ return a.real() * b.real() + a.imag() * b.imag(); }

// 射影
P proj(P p, L l){
  return l.first + dot(p - l.first, l.second - l.first) / norm(l.second - l.first) * (l.second - l.first);
}

// 反射（線対称な点）
P reflect(P p, L l){
  return p + (proj(p,l) - p) * 2.0;
}


struct uni{
  int d[10];
  void init(){
    memset(d,-1,sizeof(d));
  }
  int find(int a){ return d[a]<0?a:(d[a]=find(d[a])); }
  void merge(int a,int b){
    a = find(a); b = find(b);
    if( a == b ) return ;
    if( d[a] > d[b] ) swap(a,b);
    d[a] += d[b]; d[b] = a;
  }
  int size(int a){
     return -d[find(a)];
  }
};

vector<vector<pair<int,int> > > nex;
void solve(uni u,int bi,int cnt){
  if( u.size(0) == N ) {
    res = cnt;
    return;
  }
  if( cnt >= res-1 ) return;
  for(int i=0;i<(int)nex.size();i++){
    if( bi & (1<<i) ) continue;
    uni nu = u;
    for(int j=0;j<(int)nex[i].size();j++)
      nu.merge(nex[i][j].first, nex[i][j].second);      
    solve(nu,bi|(1<<i),cnt+1);
  }  
}

int main(){
  cin >> N;
  for(int i=0;i<N;i++){
    int x,y;
    cin >> x >> y;
    p[i] = P(x,y);
  }

  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){      
      if( used[i][j] ) continue;
      used[i][j] = true;
      vector<pair<int,int> > pv;
      P c = (p[j] - p[i])/2.0 + p[i];
      P v = p[j]-p[i];
      v = P( -v.imag() , v.real() );
      L s = L(c, c + v);
      pv.push_back( make_pair(i,j) );
      for(int k=0;k<N;k++){
	for(int l=k+1;l<N;l++){
	  if( used[k][l] ) continue;
	  if( abs(reflect( p[k], s ) - p[l]) < EPS ) {
	    used[k][l] = true;
	    pv.push_back( make_pair(k,l) );
	  }
	}
      }
      nex.push_back( pv );
    }
  }
  
  if( (int)nex.size() == N * (N-1) / 2 ){
    cout << N-1 << endl;
  } else {
    res = N-2;
    uni U;
    U.init();
    solve(U,0,0);
    cout << res << endl;
  }

  
  
}
