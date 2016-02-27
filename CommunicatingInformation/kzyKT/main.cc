#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,m;
  cin >> n >> m;
  int d[n],d2[n],ans=0;
  fill(d,d+n,1<<29);
  fill(d2,d2+n,1<<29);
  for(int i=0,x; i<m; i++) {
    cin >> x;
    d[x-1]=d2[x-1]=0;
  }
  for(int i=1; i<n; i++) d[i]=min(d[i],d[i-1]+1);
  for(int i=n-2; i>=0; i--) d2[i]=min(d2[i],d2[i+1]+1);
  for(int i=0; i<n; i++) ans=max(ans,min(d[i],d2[i]));
  cout << ans << endl;
  return 0;
}
