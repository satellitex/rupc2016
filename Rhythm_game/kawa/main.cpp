#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>G[1001];
int n,m,a,b,an;
bool visited[1001];
void dfs(int p){
  visited[p]=1;
  for(int i=0;i<G[p].size();i++){
    if(!visited[G[p][i]])dfs(G[p][i]);
  }
}

int main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>a>>b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for(int i=1;i<=n;i++)
    if(!visited[i]){
      if(G[i].size())dfs(i),an++;
      else an--;
    }
  cout<<abs(an)<<endl;
  return 0;
}
