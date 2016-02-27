#include<bits/stdc++.h>
using namespace std;

int N,M;
int G[3001][2];
int V[3001];

int dp[3001][3001];
bool used[3001][3001];

int solve(int u, int v){
  if( dp[u][v] ) return dp[u][v];
  if( used[u][v] ) return 1;
  used[u][v] = true;
  if( u == v ) return dp[u][v] = 1;
  if( V[u] != V[v] ) return dp[u][v] = -1;  
  if( solve( G[u][0], G[v][0] ) == -1 ) 
    return dp[u][v] = -1;
  if( solve( G[u][1], G[v][1] ) == -1 )
    return dp[u][v] = -1;
  return dp[u][v] = 1;
}

int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> V[i] >> G[i][0] >> G[i][1];
  }
  for(int i=0;i<M;i++){
    int q; cin >> q;
    int res = 0;
    for(int j=0;j<N;j++)
      res += solve(q,j)==1?1:0;
    cout << res << endl;
  }
}
