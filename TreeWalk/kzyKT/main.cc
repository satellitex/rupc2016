#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
vector<P> v[100001];
int n;
int solve(int i,int p) {
  if(v[i].size()==1&&v[i][0].first==p) {
    v[i][0].second=n-1;
    return 1;
  }
  int sum=0,k=-1;
  for(int j=0; j<v[i].size(); j++) {
    if(v[i][j].first!=p) {
      if(v[i][j].second==0) {
        v[i][j].second=solve(v[i][j].first,i);
        sum+=v[i][j].second;
      } else sum+=v[i][j].second;
    } else k=j;
  }
  if(k!=-1) v[i][k].second=n-1-sum;
  return sum+1;
}
int d[11111],d2[11111],f2;
void dfs(int x,int k,int y) {
  d[x]=k;
  for(int i=0; i<v[x].size(); i++) {
    if(d[v[x][i].first]==-1&&v[x][i].first!=y) dfs(v[x][i].first,k+1,y);
  }
}
void D(int s,int t) {
  memset(d,-1,sizeof(d));
  dfs(s,0,t);
  int M=-1,x,f=0;
  for(int i=1; i<=n; i++) {
    if(d[i]>M) M=d[i],x=i;
  }
  memset(d,-1,sizeof(d));
  dfs(x,0,t);
  for(int i=1; i<=n; i++) f|=d[i]==n/2-1;
  if(!f) f2=0;
}
bool check(int s, int t, int n) {return (!d2[s]||d2[s]==n/2-1)&&(!d2[t]||d2[t]==n/2-1);}

int main() {
  int s,t;
  cin >> n >> s >> t;
  for(int i=0,x,y; i<n-1; i++) {
    cin >> x >> y;
    v[x].push_back(P(y,0));
    v[y].push_back(P(x,0));
  }
  for(int i=1; i<=n; i++) {
    if(v[i].size()==1) {
      solve(i,-1);
      break;
    }
  }
  int x=-1,y=-1;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<v[i].size(); j++) {
      if(v[i][j].second==n/2) {x=i,y=v[i][j].first;break;}
    }
  }
  if(x!=-1) {
    memset(d2,-1,sizeof(d2));f2=1;
    D(x,y);
    for(int i=1; i<=n; i++) d2[i]=max(d2[i],d[i]);
    if(d2[s]!=-1&&d2[t]!=-1||d2[s]==-1&&d2[t]==-1) f2=0;
    D(y,x);
    for(int i=1; i<=n; i++) d2[i]=max(d2[i],d[i]);
  }
  if(n%2==0&&f2&&check(s,t,n)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
