#include <bits/stdc++.h>
using namespace std;
#define MMAX 200000
#define NMAX 200000
#define rep(a,b) for(int a=0;a<b;a++)

int main(void){
  int N, M, a, d, K;
  int x[MMAX],y[MMAX],z[MMAX];
  int seq[NMAX];

  cin >> N >> a >> d >> M;
  rep(i, N){
    seq[i] = a + d*i;
  }
  rep(i, M){
    cin >> x[i] >> y[i] >> z[i];
    y[i]--; z[i]--;
  }
  cin >> K; K--;

  int init_ind = K;
  int tasu = 0, waru = 1;
  for(int i=M-1; i >= 0; i--){
    if(!(y[i] <= init_ind && init_ind <= z[i])) continue;
    if(x[i] == 0){
      if((z[i] - y[i]) % 2 == 0){
        int mid;
        mid = (z[i]+y[i])/2;
        d   = mid - init_ind;
        init_ind += 2*d;
      }else{
        int mid;
        mid = (z[i]+y[i])/2;
        d   = mid - init_ind;
        init_ind += 2*d+1;
      }
    }else if(x[i] == 1){
      tasu += 1;
    }else{
      waru *= 2;
    }
  }
  /*
  cout << "DEBUG" << endl;
  cout << init_ind << endl;
  cout << seq[init_ind] << endl;
  */
  cout << seq[init_ind] / waru + tasu << endl;

  return 0;
}
