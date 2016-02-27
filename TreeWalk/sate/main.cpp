#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> G[100001];
bool used[100001];
bool dfs(int id,int cnt){
  used[id] = true;
  if( cnt == 0 ) return true;
  for(int i=0;i<(int)G[id].size();i++){
    if( used[G[id][i]] ) continue;
    return dfs(G[id][i],cnt-1);
  }
  return false;
}

bool check(){
  for(int i=0;i<N;i++)
    if( !used[i] ) 
      return false;
  return true;
}

int main(){
  int u,v;
  cin >> N;
  cin >> u >> v; --u;--v;
  for(int i=0;i<N-1;i++){
    int a,b; cin >> a >> b; --a; --b;
    G[a].push_back( b );
    G[b].push_back( a );
  }

  used[u] = used[v] = true;
  int m = N/2-1;
  if( G[v].size() == 1 ) swap(u,v);
  if( G[v].size() == 1 ){//u->o o <-v
    dfs(u,m);
    dfs(v,m);
    if( !check() ){
      memset(used,0,sizeof(used));
      used[u] = used[v] = true;
      dfs(v,m);
      dfs(u,m);
      if( !check() ){
	cout << "No" << endl;
	return 0;
      }
    }
  } else {
    if( !dfs(u,m) ||
	!dfs(v,m) ||
	!check() ){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  
}
