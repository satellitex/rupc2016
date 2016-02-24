// correct algorithm but O(n^4)
// O(n^4)だけど実際はもっと速く動作する

#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

#define DISTINCT 0
#define EQUIVALENT 1

const int MAX = 3000;

int n,m;
bool table[MAX][MAX];
bool state[MAX]; // false -> normal, true -> special
int G[MAX][2];
int answer[MAX];

void compute() {
  memset(table,EQUIVALENT,sizeof(table));
  rep(i,n) rep(j,n) if( state[i] != state[j] ) {
    table[i][j] = table[j][i] = DISTINCT;
  }
  bool update = true;
  while( update ) {
    update = false;
    rep(label,2) {
      rep(i,n) rep(j,n) {
        if( table[i][j] != EQUIVALENT ) continue;
        int next_i = G[i][label];
        int next_j = G[j][label];
        if( table[next_i][next_j] == DISTINCT ) {
          update = true;
          table[i][j] = table[j][i] = DISTINCT;
        }
      }
    }
  }
  /*
    rep(i,n) {
    rep(j,n) {
      cout << table[i][j] << " ";
    } puts("");
  }
  */
  memset(answer,0,sizeof(answer));
  rep(i,n) rep(j,n) if( table[i][j] == EQUIVALENT ) ++answer[i];
  int query;
  rep(i,m) {
    cin >> query;
    cout << answer[query] << endl;
  }
}

int main() {
  cin >> n >> m;
  rep(i,n) {
    int tmp;
    cin >> tmp;
    state[i] = (tmp?1:0);
    rep(j,2) cin >> G[i][j];
  }
  compute();
  return 0;
}
