#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x1,y1,z1,x2,y2,z2;
  cin >> n >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
  int ans=1<<29;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      for(int k=0; k<4; k++) {
        int a[3]={0,1,2};
        do {
          int x=x1,y=y1,z=z1,d=0;
          for(int l=0; l<3; l++) {
            if(a[l]==0) {
              if(i&&x==x2) d+=2;
              for(int l=0; l<i; l++) {swap(y,z);z=n-z-1;}
            } else if(a[l]==1) {
              if(j&&y==y2) d+=2;
              for(int l=0; l<j; l++) {swap(z,x);x=n-x-1;}
            } else {
              if(k&&z==z2) d+=2;
              for(int l=0; l<k; l++) {swap(x,y);y=n-y-1;}
            }
          }
          d+=abs(x-x2)+abs(y-y2)+abs(z-z2)+(i<3?i:1)+(j<3?j:1)+(k<3?k:1);
          ans=min(ans,d);
        } while(next_permutation(a,a+3));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
