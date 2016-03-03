#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef pair<P,int> PP;
int n,dx[6]={0,0,0,0,-1,1},dy[6]={0,0,-1,1,0,0},dz[6]={-1,1,0,0,0,0};
bool check(int x, int y, int z) {return x>=0&&x<n&&y>=0&&y<n&&z>=0&&z<n;}

int main() {
  int x1,y1,z1,x2,y2,z2;
  cin >> n >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
  map<PP,int> d;
  d[PP(P(x1,y1),z1)]=0;
  queue<PP> que;
  que.push(PP(P(x1,y1),z1));
  while(!que.empty()) {
    PP p=que.front();que.pop();
    if(d[p]>=4) continue;
    int x=p.first.first,y=p.first.second,z=p.second;
    for(int i=0; i<6; i++) {
      int nx=x+dx[i],ny=y+dy[i],nz=z+dz[i];
      if(!check(nx,ny,nz)||d.count(PP(P(nx,ny),nz))) continue;
      d[PP(P(nx,ny),nz)]=d[p]+1;
      que.push(PP(P(nx,ny),nz));
    }
    {
      int nx=x,ny=y,nz=z;
      swap(ny,nz);nz=n-nz-1;
      if(nx!=x2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
    {
      int nx=x,ny=y,nz=z;
      swap(ny,nz);ny=n-ny-1;
      if(nx!=x2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
    {
      int nx=x,ny=y,nz=z;
      swap(ny,nx);ny=n-ny-1;
      if(nz!=z2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
    {
      int nx=x,ny=y,nz=z;
      swap(ny,nx);nx=n-nx-1;
      if(nz!=z2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
    {
      int nx=x,ny=y,nz=z;
      swap(nx,nz);nz=n-nz-1;
      if(ny!=y2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
    {
      int nx=x,ny=y,nz=z;
      swap(nx,nz);nx=n-nx-1;
      if(ny!=y2&&!d.count(PP(P(nx,ny),nz))) {
        d[PP(P(nx,ny),nz)]=d[p]+1;
        que.push(PP(P(nx,ny),nz));
      }
    }
  }
  int ans=1<<29;
  for(map<PP,int>::iterator it=d.begin(); it!=d.end(); it++) {
    PP p=it->first;
    int x=p.first.first,y=p.first.second,z=p.second;
    ans=min(ans,abs(x-x2)+abs(y-y2)+abs(z-z2)+it->second);
  }
  cout << ans << endl;
  return 0;
}
