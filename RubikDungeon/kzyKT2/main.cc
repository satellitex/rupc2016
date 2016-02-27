#include <bits/stdc++.h>
using namespace std;
int dx[7]={0,-1,1,0,0,0,0},dy[7]={0,0,0,-1,1,0,0},dz[7]={0,0,0,0,0,-1,1};
bool check(int n,int x,int y,int z) {return x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n;}
int main() {
  int n,x1,y1,z1,x2,y2,z2;
  cin >> n >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
  int ans=1<<29;
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      for(int k=0; k<4; k++) {
        int a[3]={0,1,2};
        do {
          for(int ii=0; ii<6; ii++) {
            int x=x1+dx[ii],y=y1+dy[ii],z=z1+dz[ii],d=0;
            if(!check(n,x,y,z)) continue;
            if(ii) d++;
            bool f=1;
            for(int l=0; l<3; l++) {
              if(a[l]==0) {
                if(i&&x==x2) f=0;
                for(int h=0; h<i; h++) {swap(y,z);z=n-z-1;}
              } else if(a[l]==1) {
                if(j&&y==y2) f=0;
                for(int h=0; h<j; h++) {swap(z,x);x=n-x-1;}
              } else {
                if(k&&z==z2) f=0;
                for(int h=0; h<k; h++) {swap(x,y);y=n-y-1;}
              }
            }
            if(!f) continue;
            d+=abs(x-x2)+abs(y-y2)+abs(z-z2)+(i<3?i:1)+(j<3?j:1)+(k<3?k:1);
            ans=min(ans,d);
          }
        } while(next_permutation(a,a+3));
      }
    }
  }
  cout << ans << endl;
  return 0;
}
