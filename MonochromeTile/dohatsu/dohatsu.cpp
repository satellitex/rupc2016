#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define MAX_N 100000
  
int n;
int ax[MAX_N],ay[MAX_N],bx[MAX_N],by[MAX_N];

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
  while(scanf("%d",&n)!=EOF){
    long long sum=0;
    for(int i=0;i<n;i++)scanf("%d %d %d %d",&ax[i],&ay[i],&bx[i],&by[i]);
    T.init();
    for(int i=0;i<n;i++){
      if(T.check(ax[i],bx[i]+1,ay[i],by[i],0,0,(1<<17))){
        printf("%lld\n",sum);
      }else{
        T.insert(ax[i],bx[i]+1,ay[i],by[i],0,0,(1<<17));
        sum+=(long long)(bx[i]-ax[i]+1)*(long long)(by[i]-ay[i]+1);
        printf("%lld\n",sum);
      }
    }
  }
  return 0;
}

