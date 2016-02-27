#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x1,y1,z1,e[3],ans=1<<29;
  cin >> n >> x1 >> y1 >> z1 >> e[0] >> e[1] >> e[2];
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      for(int k=0; k<4; k++) {
        int a[3]={0,1,2},b[3]={i,j,k};
        do {
          int c[3]={x1,y1,z1},d=0;
          for(int l=0; l<3; l++) {
            if(b[a[l]]&&c[a[l]]==e[a[l]]) d+=2;
            for(int h=0; h<b[a[l]]; h++) {swap(c[(a[l]+1)%3],c[(a[l]+2)%3]);c[(a[l]+2)%3]=n-c[(a[l]+2)%3]-1;}
          }
          for(int l=0; l<3; l++) d+=abs(c[l]-e[l])+(b[l]<3?b[l]:1);
          ans=min(ans,d);
        } while(next_permutation(a,a+3));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
