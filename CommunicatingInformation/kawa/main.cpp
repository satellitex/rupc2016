#include<iostream>
using namespace std;
int main(){
  int n,m,a,b=1,c;
  cin>>n>>m>>c;
  b=c;
  c--;
  for(int i=1;i<m;i++){
    cin>>a;
    c=max((a-b)/2,c);
    b=a;
  }
  cout<<max(c,n-b)<<endl;;
  return 0;
}
