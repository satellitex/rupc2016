#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

vector<int> v[11111];
int d[11111];
void dfs(int x,int k) {
  d[x]=k;
  for(int i=0; i<v[x].size(); i++) {
<<<<<<< HEAD
    int y=v[x][i];
    if(d[y]==-1) dfs(y,k+1);
  }
}

bool check(int s, int t, int n) {
  if(d[s]==0&&d[t]==n/2) return 1;
  if(d[s]==0&&d[t]==n-1) return 1;
  if(d[s]==n/2-1&&d[t]==n/2) return 1;
  if(d[s]==n/2-1&&d[t]==n-1) return 1;
  return 0;
}
=======
    if(d[v[x][i]]==-1) dfs(v[x][i],k+1);
  }
}
bool check(int s, int t, int n) {return !d[s]&&(d[t]==n/2||d[t]==n-1)||d[s]==n/2-1&&(d[t]==n/2||d[t]==n-1);}
>>>>>>> 414c9dadf3ae0059d2eaaa34dcaa9397699f6942

int main() {
  int n,s,t;
  cin >> n >> s >> t;
<<<<<<< HEAD
  for(int i=0; i<n-1; i++) {
    int x,y;
=======
  for(int i=0,x,y; i<n-1; i++) {
>>>>>>> 414c9dadf3ae0059d2eaaa34dcaa9397699f6942
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  memset(d,-1,sizeof(d));
  dfs(1,0);
<<<<<<< HEAD
  int M=-1,x;
  for(int i=1; i<=n; i++) {
    if(d[i]>M) {
      M=d[i];
      x=i;
    }
  }
  memset(d,-1,sizeof(d));
  dfs(x,0);
  bool f=0;
=======
  int M=-1,x,f=0;
  for(int i=1; i<=n; i++) {
    if(d[i]>M) M=d[i],x=i;
  }
  memset(d,-1,sizeof(d));
  dfs(x,0);
>>>>>>> 414c9dadf3ae0059d2eaaa34dcaa9397699f6942
  for(int i=0; i<=n; i++) f|=d[i]==n-1;
  if(f&&(check(s,t,n)||check(t,s,n))) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
