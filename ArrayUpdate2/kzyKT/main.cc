#include <bits/stdc++.h>
using namespace std;
struct P {int x,y,z;};

int main() {
  int a,d,n,m,k;
  cin >> n >> a >> d >> m;
  P p[m];
  for(int i=0; i<m; i++) cin >> p[i].x >> p[i].y >> p[i].z;
  cin >> k;
  for(int i=m-1; i>=0; i--) {
    if(!p[i].x&&p[i].y<=k&&k<=p[i].z) k=p[i].z+p[i].y-k;
  }
  int ans=a+d*(k-1);
  for(int i=0; i<m; i++) {
    if(k<p[i].y||p[i].z<k) continue;
    if(!p[i].x) k=p[i].z+p[i].y-k;
    else if(p[i].x==1) ans++;
    else ans/=2;
  }
  cout << ans << endl;
  return 0;
}
