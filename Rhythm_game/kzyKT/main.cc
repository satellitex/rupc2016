#include <bits/stdc++.h>
using namespace std;
bool u[1010];
vector<int> v[1010];
int dfs(int x,bool f) {
  u[x]=1;
  for(int i=0; i<v[x].size(); i++) {
    if(!u[v[x][i]]) f=0,dfs(v[x][i],f);
  }
  return f;
}

int main() {
  int n,m;
  cin >> n >> m;
  for(int i=0,x,y; i<m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  int x=0,y=0;
  for(int i=1; i<=n; i++) {
    if(!u[i]) dfs(i,1)?x++:y++;
  }
  cout << abs(x-y) << endl;
  return 0;
}
