#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
const ll MAX = 210000;
typedef complex<double> P;
const P I(0, 1);

//要素数n (2^k), (a[i].real()に値), inv = true のとき逆変換
void fft(ll n, vector<P> &a, bool inv = false) {
  double theta = 2.0 * M_PI / n;
  if( inv ) theta *= -1.0;
  for (ll m = n; m >= 2; m >>= 1) {
    ll mh = m >> 1;
    for (ll i = 0; i < mh; i++) {
      P w = exp(i*theta*I);
      for (ll j = i; j < n; j += m) {
        ll k = j + mh;
        P x = a[j] - a[k];
        a[j] += a[k];
        a[k] = w * x;
      }
    }
    theta *= 2;
  }
  ll i = 0;
  for (ll j = 1; j < n - 1; j++) {
    for (ll k = n >> 1; k > (i ^= k); k >>= 1);
    if (j < i) swap(a[i], a[j]);
  }
  if( inv )
    for(ll i=0;i<n;i++) a[i]/=(double)n;
}


vector<ll> mult(vector<ll> a,vector<ll> b){
  ll n = 1;
  while( n < a.size()+b.size()-1 ) n*=2;
  vector<P> ai(n),bi(n);
  for(ll i=0;i<a.size();i++) ai[i]=P( a[i], 0 );
  for(ll i=0;i<b.size();i++) bi[i]=P( b[i], 0 );
  fft(n,ai);
  fft(n,bi);
  for(ll i=0;i<n;i++) ai[i] *= bi[i];
  fft(n,ai,true);
  vector<ll> ret(n);
  for(ll i=0;i<n;i++) ret[i] = round(ai[i].real());
  return ret;
}


ll N,M,Q;
ll A[40004];
ll B[40004];

vector<ll> rsk(ll *a,ll n){
  ll m = MAX;
  vector<ll> ra(m+1,0);
  ll sm = 0;
  ra[0] = 1;
  for(ll i=0;i<n;i++)
    ra[ sm+=a[i] ] = 1;
  vector<ll> rx = ra;
  reverse(rx.begin(),rx.end());

  
  vector<ll> v = mult(ra,rx);
  vector<ll> x;
  x.push_back(0);
  for(ll i=m-1;i>-1;i--){
    x.push_back( v[i] );    
  }    
  return x;
}

int main(){
  cin >> N >> M >> Q;
  for(ll i=0;i<N;i++) cin >> A[i];
  for(ll i=0;i<M;i++) cin >> B[i];

  vector<ll> va = rsk(A,N);
  vector<ll> vb = rsk(B,M);  
  
  reverse(vb.begin(),vb.end());

  vector<ll> v = mult(va,vb);
  int m = MAX;
  for(ll i=0;i<Q;i++){
    ll c; cin >> c;
    if( !c )  cout << v[m] << endl;
    else cout << v[c+m]+v[m-c] << endl;
  }
}
