#include<bits/stdc++.h>
using namespace std;

int N;
int A[1001];
int dp[1001][1001];
int main(){
  cin >> N;
  for(int i=0;i<N;i++) cin >> A[i];

  for(int i=0;i<N-1;i++)
    dp[i][i+1] = A[i]*A[i+1];

  for(int k=3;k<N;k+=2){     
    for(int l=0;l<N;l++){
      int r = l + k;
      if( r >= N ) break;
      for(int i = l+2;i<r;i+=2)
	dp[l][r] = max( dp[l][r],
		        dp[l+1][i] + dp[i+1][r-1] + A[l] * A[r] );
      for(int i = l+1;i<r;i+=2)
	dp[l][r] = max( dp[l][r],
			dp[l][i] + dp[i+1][r] );
    }
  }
  
  cout << dp[0][N-1] << endl;
}
