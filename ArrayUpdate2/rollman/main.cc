#include <bits/stdc++.h>
using namespace std;
#define MMAX 200000
#define NMAX 200000
#define rep(a,b) for(int a=0;a<b;a++)
#define TASU 0
#define WARU 1

int main(void){
  int N, M, a, d, K;
  int x[MMAX],y[MMAX],z[MMAX];
  int seq[NMAX];

  //cin >> N >> a >> d >> M;
  scanf("%d %d %d %d", &N, &a, &d, &M);
  rep(i, N){
    seq[i] = a + d*i;
  }
  rep(i, M){
    //cin >> x[i] >> y[i] >> z[i];
    scanf("%d %d %d", &x[i], &y[i], &z[i]);
    y[i]--; z[i]--;
  }
  scanf("%d", &K);
  //cin >> K;
  K--;

  int init_ind = K;
  list<int> l;
  int tasu = 0, waru = 0;
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
      l.push_front(TASU);
      //tasu += 1;
    }else{
      l.push_front(WARU);
      //waru += 1;
    }
  }
  /*
  cout << "DEBUG" << endl;
  cout << init_ind << endl;
  cout << seq[init_ind] << endl;
  */
  int ans = seq[init_ind];

  for(list<int>::iterator it = l.begin(); it != l.end(); it++){
    if(*it == TASU) ans++;
    if(*it == WARU) ans /= 2;
  }

  printf("%d\n", ans);
  //cout << ans << endl;

  return 0;
}
