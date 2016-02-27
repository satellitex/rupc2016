#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<string,string> PP;

int main() {
  int n,m;
  cin >> n >> m;
  vector<P> v[n];
  int c[n];
  for(int i=0,x,y; i<n; i++) {
    cin >> c[i] >> x >> y;
    v[x].push_back(P(i,0));
    v[y].push_back(P(i,1));
  }
  vector<PP> d[n];
  for(int k=0; k<n; k++) {
    PP s[n];
    for(int i=0; i<n; i++) s[i]=PP("","");
    queue<int> que;
    que.push(k);
    while(!que.empty()) {
      int x=que.front();que.pop();
      PP t=s[x];
      for(int i=0; i<v[x].size(); i++) {
        int y=v[x][i].first,z=v[x][i].second;
        if(s[y]!=PP("","")) continue;
        PP p=t;
        p.first+=(char)(c[x]+'0');
        p.second+=(char)(z+'0');
        s[y]=p;
        d[y].push_back(p);
        que.push(y);
      }
    }
    cout << k << endl;
    for(int i=0; i<n; i++) cout << i << " " << s[i].first << " " << s[i].second << endl;
  }
  for(int i=0; i<n; i++) sort(d[i].begin(),d[i].end());
  /*
  for(int i=0; i<n; i++) {
    if(i!=0&&i!=4) continue;
    for(int j=0; j<d[i].size(); j++) cout << i << " " << d[i][j].first << " " << d[i][j].second << endl;
  }
  */
  for(int i=0,x; i<m; i++) {
    cin >> x;
    int ans=0;
    for(int j=0; j<n; j++) {
      if(d[x]==d[j]) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
