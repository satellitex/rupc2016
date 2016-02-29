#include<iostream>
using namespace std;
int main(){
  int w,h,n,a=0,b=0,p,an=0,k=0;
  cin>>w>>h>>n;
  while(n--){
    cin>>p;
    if(p)a++;
    else b++;
    if(b==w-1&&k==0)b=1000,k=1;
    if(b==w+h-4&&k==1)b=2000,k=2;
    if(b==1001)b=w-2;
    if(b==2001)b=w+h-5;
    if(a==b)an++;
  }
  cout<<an<<endl;
  return 0;
}
