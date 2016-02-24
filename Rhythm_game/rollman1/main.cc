#include <iostream>
#include <vector>
#define NMAX 1000

void dfs(int N, int node, bool (*g)[NMAX], bool* visited){
  if(visited[node]) return;
  visited[node] = true;
  for(int i=0; i < N; i++){
    if(g[node][i] == true){
      dfs(N, i, g, visited);
    }
  }
}

int main(void){
  int N, M;
  bool g[NMAX][NMAX];
  bool visited[NMAX];
  std::cin >> N >> M;
  int tap = 0;
  int slide = 0;
  for(int i=0; i < NMAX; i++) for(int j=0; j < NMAX; j++) g[i][j] = false;
  for(int i=0; i < NMAX; i++) visited[i] = false;
  for(int i = 0; i < M; i++){
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    g[a][b] = true;
    g[b][a] = true;
  }
  for(int i = 0; i < N; i++){
    bool is_there_edge = false;
    if(visited[i]) continue;
    for(int j=0; j < N; j++){
      if(g[i][j] == true){
        is_there_edge = true;
        break;
      }
    }
    if(is_there_edge){
      dfs(N, i, g, visited);
      slide++;
    }else{
      tap++;
    }
  }
  int ans = tap - slide;
  if(ans < 0) ans*=-1;
  std::cout << ans << std::endl;
  return 0;
}
