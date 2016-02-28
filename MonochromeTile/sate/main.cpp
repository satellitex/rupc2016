#include<bits/stdc++.h>
using namespace std;

int H,W,N;
typedef pair<int,int> P;
const int MAX = (1<<18);
struct seg{
  set<P> S[MAX],T[MAX];
  int n;
  void init(int _n){
    n = 1; while( n < _n ) n*=2;
  }
  bool check(const set<P>& s,int u,int d){
    set<P>::iterator it = s.lower_bound(P(u,u));
    if( it != s.end() ){
      //  cout << "not end " << it->first << " < "<< d << " < " << it->second << endl;
      if( it->first < d ) return false;
    }
    if( it != s.begin() ){
      --it;
      //cout << "not begin " << it->first<< " < " << u << " < " << it->second << endl;
      if( u < it->second ) return false;
    }
    return true;
  }

  void insert(set<P> &s,int u,int d){
    bool loop = true;
    while(loop){ 
      set<P>::iterator it = s.lower_bound(P(u,u));      
      if( it != s.end() ){      
	if( it->first < d ) {
	  d = max( d, it->second );
	  s.erase(it);
	  continue;
	}
      }
      if( it != s.begin() ){
	it--;
	if( u < it->second ) {
	  u = min( u, it->first );
	  d = max( d, it->second );
	  s.erase(it);
	  continue;
	}
      }
      break;
    }
    s.insert(P(u,d));
  }
  
  bool check(int a,int b,int k,int l,int r,int u,int d){
    if( b <= l || r <= a ) return true;
    if( !check(S[k],u,d) ) return false;
    if( a <= l && r <= b ){
      return check( T[k], u, d );
    }
    return check(a,b,2*k+1,l,(l+r)/2,u,d) && check(a,b,2*k+2,(l+r)/2,r,u,d);    
  }
  void query(int a,int b,int k,int l,int r,int u,int d){
    if( b <= l || r <= a ) return;
    insert(T[k],u,d);
    if( a <= l && r <= b ){
      insert(S[k],u,d);
    } else {
      query(a,b,2*k+1,l,(l+r)/2,u,d);
      query(a,b,2*k+2,(l+r)/2,r,u,d);
    }
  }
  //[xs,xe)-[ys,ye)
  bool check(int xs,int xe,int ys,int ye){
    return check(xs,xe,0,0,n,ys,ye);
  }
  void query(int xs,int xe,int ys,int ye){
    query(xs,xe,0,0,n,ys,ye);
  }
};

seg S;
typedef long long ll;
int main(){
  cin >> W >> H >> N;
  S.init(W);
  ll res = 0;
  for(int i=0;i<N;i++){
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1;
    if( S.check( x1, x2, y1, y2 ) ){
      S.query(x1,x2,y1,y2);
      res += (ll)(x2-x1) * (ll)(y2-y1);
    }
    cout << res << endl;
  }
}
