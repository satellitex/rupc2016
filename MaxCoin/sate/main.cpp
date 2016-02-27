#include<bits/stdc++.h>
using namespace std;

int N,X,Y;
int A[101],B[101],C[101],D[101];
int dp[2][1001][1001];
const int INF = (1<<29);
int main(){
  cin >> N;
  cin >> X >> Y;
  for(int i=0;i<N;i++) cin >> A[i] >> B[i] >> C[i] >> D[i];
  fill(dp[0][0],dp[0][901],-INF);
  dp[0][X+300][Y+300] = 0;
  for(int i=0;i<N;i++){
    int now = i&1;
    int nex = 1-now;
    fill(dp[nex][0],dp[nex][901],-INF);
    for(int x=0;x<X+601;x++){
      for(int y=0;y<Y+601;y++){
	if( dp[now][x][y]<0 ) continue;

	dp[nex][x-A[i]][y+B[i]] = max( dp[nex][x-A[i]][y+B[i]],
				       dp[now][x][y] );
	dp[nex][x][y-C[i]] = max( dp[nex][x][y-C[i]],
				  dp[now][x][y] + D[i] );
	dp[nex][x][y] = max( dp[nex][x][y],
			     dp[now][x][y] );
      }
    }
  }
  int res = 0;
  for(int x=300;x<=900;x++){
    for(int y=300;y<=900;y++){
      //      cout << dp[N&1][x][y] << endl;
      res = max( res, dp[N&1][x][y] );
    }
  }
  cout << res << endl;
}
