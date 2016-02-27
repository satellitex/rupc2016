#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
  
int h,w,n;
int ax,ay,bx,by;

struct segtree{
  
  bool check(set< P > &T,int a,int b){
    set<P> :: iterator it;
    it=T.lower_bound(P(a,a)); 
    if(it!=T.end()&&it->first <= b)return true;
    if(it!=T.begin()&&a<=(--it)->second)return true;
    return false;
  }

  void insert(set<P> &T,int a,int b){
    set<P> :: iterator it;
    while(1){
      it=T.lower_bound(P(a,a));
      if(it!=T.end()&&it->first<=b){
        a=min(a,it->first);
        b=max(b,it->second);
        T.erase(it);      
      }else if(it!=T.begin()&&a<=(--it)->second){
        a=min(a,it->first);
        b=max(b,it->second);
        T.erase(it);
      }else break;
    }
    T.insert(P(a,b));
  }
  
  set< P > t[(1<<18)],u[(1<<18)];
  
  void init(){
    for(int i=0;i<(1<<18);i++)t[i].clear(),u[i].clear();
  }
  
  bool check(int a,int b,int c,int d,int k,int l,int r){
    if(b<=l||r<=a)return false;
    if(check(t[k],c,d))return true;
    if(a<=l&&r<=b)return check(u[k],c,d);
    int m=(l+r)/2;
    return check(a,b,c,d,k*2+1,l,m)||check(a,b,c,d,k*2+2,m,r);
  }

  void insert(int a,int b,int c,int d,int k,int l,int r){
    if(b<=l||r<=a)return;
    insert(u[k],c,d);
    if(a<=l&&r<=b){insert(t[k],c,d);return;}
    int m=(l+r)/2;
    insert(a,b,c,d,k*2+1,l,m);insert(a,b,c,d,k*2+2,m,r);
  }
};

segtree T;
  
int main(){
  scanf("%d %d %d",&w,&h,&n);
  long long sum=0;
  for(int i=0;i<n;i++){
    scanf("%d %d %d %d",&ax,&ay,&bx,&by);
    if(!T.check(ax,bx+1,ay,by,0,0,(1<<17))){
      T.insert(ax,bx+1,ay,by,0,0,(1<<17));
      sum+=(long long)(bx-ax+1)*(long long)(by-ay+1);
    }
    printf("%lld\n",sum);
  }
  return 0;
}
