#include<bits/stdc++.h>
using namespace std;


const double PI = 4.0*atan(1.0);
const int MAX = 200000;
typedef complex<double> P;
const P I(0, 1);

//要素数n (2^k), (a[i].real()に値), inv = true のとき逆変換
void fft(int n, vector<P> &a, bool inv = false) {
  double theta = 2.0 * PI / n;
  if( inv ) theta *= -1.0;
  for (int m = n; m >= 2; m >>= 1) {
    int mh = m >> 1;
    for (int i = 0; i < mh; i++) {
      P w = exp(i*theta*I);
      for (int j = i; j < n; j += m) {
        int k = j + mh;
        P x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  int i = 0;
  for (int j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
  if( inv )
    for(int i=0;i<n;i++) a[i]/=n;
}

vector<int> mult(vector<int> a,vector<int> b){
  int n = 1;
  while( n < a.size()+b.size() ) n*=2;
  vector<P> ai(n,{0,0}),bi(n,{0,0});
  for(int i=0;i<a.size();i++) ai[i].real( a[i] );
  for(int i=0;i<b.size();i++) bi[i].real( b[i] );
  fft(n,ai);
  fft(n,bi);
  for(int i=0;i<n;i++) ai[i] = ai[i]*bi[i];
  fft(n,ai,true);
  vector<int> ret(n);
  for(int i=0;i<n;i++) ret[i] = (int)(ai[i].real()+0.5);
  return ret;
}


int N,M,Q;
int A[20004];
int B[20004];

vector<int> rsk(int *a,int n){
  int max = 0;
  for(int i=0;i<n;i++) max+=a[i];
  //cout << max << endl;
  //max = MAX;
  vector<int> ra(max+1);
  int sm = 0;
  ra[0] = 1;
  for(int i=0;i<n;i++)
    ra[ sm+=a[i] ] = 1;
  vector<int> rx = ra;
  reverse(rx.begin(),rx.end());
  vector<int> v = mult(ra,rx);
  vector<int> x;
  /*
  for(int i=0;i<=MAX;i++) cout << ra[i] << " ";
  cout << endl;
  for(int i=0;i<=MAX;i++) cout << rx[i] << " ";
  cout << endl;
  
  for(int i=0;i<=2*MAX;i++) cout << v[i] << " ";
  cout << endl;
  */
  x.push_back(0);
  for(int i=max+1;i<=2*max;i++){
    x.push_back( v[i] );    
  }
  
  
  return x;
}

int main(){
  cin >> N >> M >> Q;
  for(int i=0;i<N;i++) cin >> A[i];
  for(int i=0;i<M;i++) cin >> B[i];

  vector<int> va = rsk(A,N);
  vector<int> vb = rsk(B,M);
  /*
  for(int i=0;i<(int)va.size();i++)
    cout << va[i] << " ";
  cout << endl;
  for(int i=0;i<(int)vb.size();i++)
    cout << vb[i] << " ";
  cout << endl;
  */
  
  reverse(vb.begin(),vb.end());

  vector<int> v = mult(va,vb);

  
  for(int i=0;i<Q;i++){
    int c; cin >> c;
    cout << v[c+va.size()-1]+v[va.size()-1-c] << endl;
  }
}
