#include<bits/stdc++.h>
using namespace std;

int N,M;
int G[3001][2];
vector<int> rG[3001][2];
int V[3001];
int dp[3001][3001];

typedef pair<int,int> P;

int main(){
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> V[i] >> G[i][0] >> G[i][1];
    rG[G[i][0]][0].push_back(i);
    rG[G[i][1]][1].push_back(i);
  }

  queue<P> ok, ng; 
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if( i == j ) {
	dp[i][j] = 1;
	ok.push( {i,j} );
      }
      if( V[i] != V[j] ) {
	dp[i][j] = -1;
	ng.push( {i,j} );
      }
    }
  }

  while( !ng.empty() ){
    P p = ng.front(); ng.pop();
    int u = p.first, v = p.second;
    for(int t=0;t<2;t++){
      for(int i=0;i<(int)rG[u][t].size();i++){
	for(int j=0;j<(int)rG[v][t].size();j++){
	  int nu = rG[u][t][i], nv = rG[v][t][j];
	  if( !dp[nu][nv] ){
	    dp[nu][nv] = -1;
	    ng.push( {nu,nv} );
	  }
	}
      }
    }
  }

  for(int i=0;i<M;i++){
    int q; cin >> q;
    int res = 0;
    for(int j=0;j<N;j++){
      res += (dp[q][j]==-1?0:1);
    }
    cout << res << endl;
  }

  
}
