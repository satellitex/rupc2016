#include <iostream>
#include <vector>
#define NMAX 1000
using namespace std;

int N, M;
vector< vector<int> > g;
vector<bool> visited;
//Solution with adjacency list

void dfs(int node){
  visited[node] = true;
  for(int i=0; i < g[node].size(); i++){
    if(visited[g[node][i]] == true) continue;
    dfs(g[node][i]);
  }
}

int main(void){
  int ans = 0;
  cin >> N >> M;
  g = vector< vector<int> >(N);
  visited = vector<bool>(N, false);
  for(int i=0; i < M; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i=0; i < N; i++){
    if(visited[i] == true) continue;
    if(g[i].size() == 0) ans++;
    else{
      ans--;
      dfs(i);
    }
  }
  if(ans < 0)
    cout << -ans << endl;
  else
    cout << ans << endl;
  return 0;
}
