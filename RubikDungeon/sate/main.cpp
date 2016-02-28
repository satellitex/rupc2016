#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
void rotate_x(int &x,int &y,int &z){
  int ty = z, tz = N - 1 - y;
  y = ty; z = tz;
}
void rotate_y(int &x,int& y,int &z){
  int tx = z, tz = N - 1 - x;
  x = tx; z = tz;
}
void rotate_z(int &x,int &y,int &z){
  int tx = y, ty = N - 1 - x;
  x = tx; y = ty;
}

struct state{
  int x1,y1,z1,x2,y2,z2;
  state(int x1,int y1,int z1,int x2,int y2,int z2):
    x1(x1),y1(y1),z1(z1),x2(x2),y2(y2),z2(z2) {}
  bool operator<(const state& st) const {
    if( x1 == st.x1 )
      if( y1 == st.y1 )
	if( z1 == st.z1 )
	  if( x2 == st.x2 )
	    if( y2 == st.y2 )
	      return z2 < st.z2;
	    else
	      return y2 < st.y2;
	  else
	    return x2 < st.x2;
	else
	  return z1 < st.z1;
      else
	return y1 < st.y1;
    return x1 < st.x1;
  }
  void view() const{
    cout << "( " << x1 << ", " << y1 << ", " << z1 << " ) - ( " << x2 << ", " << y2 << ", " << z2 << " ) "  << endl;
  }
};

map<state,int> dp;
int dx[]={ 1,-1, 0, 0, 0, 0};
int dy[]={ 0, 0, 1,-1, 0, 0};
int dz[]={ 0, 0, 0, 0, 1,-1};

bool check(const state& st,const state&mt){
  if( dp.count(st) == 0 )
    return true;
  else if( dp[st] > dp[mt]+1 )
    return true;
  return false;
}

int solve(int x1,int y1,int z1,int x2,int y2,int z2,int cc){
  state st = state(x1,y1,z1,x2,y2,z2);
  queue<state> q;
  q.push( st );
  if( dp.count( st ) == 0 ) dp[st] = cc;
  else if( dp[st] > cc ) dp[st] = cc;
  else return 0;
  
  while( !q.empty() ){
    state st = q.front(); q.pop();
    int cnt = dp[st];
    //   st.view();

    if( st.x1 != st.x2 ){
      state ns = st;
      rotate_x(ns.x1,ns.y1,ns.z1);     
      if( check(ns,st) ){	
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_x(ns.x1,ns.y1,ns.z1);
      rotate_x(ns.x1,ns.y1,ns.z1);
      if( check(ns,st) ){	
	dp[ns] = cnt+1; q.push( ns );
      }
      
      ns = st;
      rotate_x(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_x(ns.x2,ns.y2,ns.z2);
      rotate_x(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }

    }
    
    if( st.y1 != st.y2 ){
      state ns = st;
      rotate_y(ns.x1,ns.y1,ns.z1);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_y(ns.x1,ns.y1,ns.z1);
      rotate_y(ns.x1,ns.y1,ns.z1);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }

      ns = st;
      rotate_y(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_y(ns.x2,ns.y2,ns.z2);
      rotate_y(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
    }

    if( st.z1 != st.z2 ){
      state ns = st;
      rotate_z(ns.x1,ns.y1,ns.z1);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_z(ns.x1,ns.y1,ns.z1);
      rotate_z(ns.x1,ns.y1,ns.z1);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }

      ns = st;
      rotate_z(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
      rotate_z(ns.x2,ns.y2,ns.z2);
      rotate_z(ns.x2,ns.y2,ns.z2);
      if( check(ns,st) ) {
	dp[ns] = cnt+1; q.push( ns );
      }
    }

  }
  return -1;
}

typedef long long ll;
const ll INF = 10000000000000009LL;

ll get(const state& st){
  ll x = abs( st.x1 - st.x2 );
  ll y = abs( st.y1 - st.y2 );
  ll z = abs( st.z1 - st.z2 );
  return x + y + z;
}

int main(){
  cin >> N;
  int x1,y1,z1;
  int x2,y2,z2;
  cin >> x1 >> y1 >> z1;
  cin >> x2 >> y2 >> z2;

  solve(x1,y1,z1,x2,y2,z2,0);
  for(int i=0;i<6;i++){
    int nx = x1 + dx[i], ny = y1 + dy[i], nz = z1 + dz[i];
    if( nx < 0 || nx >= N || ny < 0 || ny >= N || nz < 0 || nz>= N ) continue;    
    solve(nx,ny,nz,x2,y2,z2,1);
  }

  ll res = INF;
  for(map<state,int>::iterator it = dp.begin(); it != dp.end(); it++ ){
    res = min( res, get(it->first) + (ll)it->second );
  }
  cout << res << endl;
}
