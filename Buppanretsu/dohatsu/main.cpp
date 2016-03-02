#include<bits/stdc++.h>
using namespace std;
int W,H,N,p;
int ax=1,ay=1,bx=1,by=2,ans=0;

int main(){
  cin>>W>>H>>N;
  for(int i=0;i<N;i++){
    cin>>p;
    if(p==0){
      if(ay==1){
        if(ax<W)ax++;
        else ay++;
      }else  if(ay==H){
        ax--;
      }else{
        ay++;
      }
    }else{
      if(by==2){
        if(bx<W-1)bx++;
        else by++;
      }else if(by==H-1){
        bx--;
      }else{
        by++;
      }
    }
    if( abs(ax-bx)+abs(ay-by) == 1 ){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}
