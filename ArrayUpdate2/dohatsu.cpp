#include<bits/stdc++.h>
using namespace std;
#define MAX 200005

int N,M,K,a,d;
int x[MAX],y[MAX],z[MAX];

int main(){
  scanf("%d %d %d %d",&N,&a,&d,&M);
  for(int i=0;i<M;i++)scanf("%d %d %d",&x[i],&y[i],&z[i]);
  scanf("%d",&K);
  stack<int> st;
  for(int i=M-1;i>=0;i--){
    if(K<y[i]||z[i]<K)continue;
    if(x[i]==0)K=z[i]+y[i]-K; 
    else st.push(x[i]);
  }
  int ans=a+d*(K-1);
  while(!st.empty()){
    if(st.top()==1)ans++;
    else ans/=2;
    st.pop();
  }
  printf("%d\n",ans);
  return 0;
}

