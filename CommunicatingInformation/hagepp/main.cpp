#include <iostream>
using namespace std;

int main(){
  int n,m,ans;
  cin>>n>>m;
  cin>>ans;
  int a,b=ans;
  b=ans,ans--;
  for(int i=1;i<m;i++){
    cin>>a;
    ans=max(ans,(a-b)/2);
    b=a;
  }
  cout <<max(ans,n-b)<<endl;
  return 0;
}
