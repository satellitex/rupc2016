#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

#define DISTINCT 0
#define EQUIVALENT 1

typedef pair<int,int> ii;

const int MAX = 3000;

int n,m;
int DFA[MAX][2], answer[MAX], sum[MAX];
bool state[MAX]; // 0 -> normal, 1 -> special
bool table[MAX][MAX];
ii decode[MAX * MAX];
vector<int> rG[MAX * MAX];

int encode(int i,int j) {
  if( i > j ) swap(i,j);
  return sum[i] + (j-i);
}

void init_graph() {
  rep(i,n) REP(j,i,n) {
    int curID = encode(i,j);
    assert( curID < n*n );
    rep(label,2) {
      int next_i = DFA[i][label];
      int next_j = DFA[j][label];
      int nextID = encode(next_i,next_j);
      assert( nextID < n*n );
      rG[nextID].push_back(curID);
    }
  }
}

void dfs(int cur) {
  rep(i,(int)rG[cur].size()) {
    int next = rG[cur][i];
    ii a = decode[next];
    if( table[a.first][a.second] == DISTINCT ) continue;
    table[a.first][a.second] = table[a.second][a.first] = DISTINCT;
    dfs(next);
  }
}

void compute() {

  memset(table,EQUIVALENT,sizeof(table));
  memset(sum,0,sizeof(sum));
  rep(i,n*n) decode[i] = ii(-1,-1);
  REP(i,1,n) sum[i] = sum[i-1] + (n-(i-1));
  rep(i,n) REP(j,i,n) {
    assert( encode(i,j) < n*n );
    decode[encode(i,j)] = ii(i,j);
  }
  
  init_graph();

  deque<int> deq;
  rep(i,n) REP(j,i+1,n) if( state[i] != state[j] ) {
    table[i][j] = table[j][i] = DISTINCT;
    //deq.push_back(encode(i,j));
    dfs(encode(i,j));
  }
  /*
  while( !deq.empty() ) {
    int ID = deq.front(); deq.pop_front();
    rep(i,(int)rG[ID].size()) {
      int nextID = rG[ID][i];
      ii tmp = decode[nextID];
      assert(tmp.first != -1 && tmp.second != -1);
      if( table[tmp.first][tmp.second] == DISTINCT ) continue;
      table[tmp.first][tmp.second] = table[tmp.second][tmp.first] = DISTINCT;
      deq.push_back(nextID);
    }
  }
  */
  /*
  rep(i,n) {
    rep(j,n) {
      cout << table[i][j] << " ";
    } puts("");
  }
  */
  rep(i,n) rep(j,n) answer[i] += table[i][j];
  
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
    rep(j,2) cin >> DFA[i][j];
  }
  compute();
  return 0;
}
