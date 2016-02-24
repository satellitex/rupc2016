#include <iostream>
#include <vector>
#define NMAX 1000

void dfs(int N, int node, int (*g)[NMAX], bool* visited){
  if(visited[node]) return;
  visited[node] = true;
  for(int i=0; i < N; i++){
    if(g[node][i] == 1){
      dfs(N, i, g, visited);
    }
  }
}

int main(void){
  int N, M;
  int g[NMAX][NMAX];
  bool visited[NMAX];
  std::cin >> N >> M;
  int tap = 0;
  int slide = 0;
  for(int i = 0; i < M; i++){
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    g[a][b] = 1;
  }
  for(int i = 0; i < N; i++){
    bool is_there_edge = false;
    if(visited[i]) continue;
    for(int j=0; j < N; j++){
      if(g[i][j] == 1){
        is_there_edge = true;
      }
    }
    if(is_there_edge){
      dfs(N, i, g, visited);
      slide++;
    }else{
      tap++;
    }
  }
  std::cout << (tap > slide) ? (tap-slide) : (slide-tap) << '\n';
  return 0;
}
