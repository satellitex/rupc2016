#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<19;
const double th=2*M_PI/N;
typedef complex<double> P;
 
void FFT(P a[],double t) {
  for(int m=N;m>=2;m>>=1,t*=2) {
    int mh=m>>1;
    for(int i=0;i<mh;i++) {
      P w=exp(t*i*P(0,1));
      for(int j=i;j<N;j+=m) {int k=j+mh;P x=a[j]-a[k];a[j]+=a[k];a[k]=w*x;}
    }
  }
  for(int j=1,i=0;j<N-1;j++){for(int k=N>>1;k>(i^=k);k>>=1);if(j<i)swap(a[i],a[j]);}
}

ll a[N],b[N],aa[N],bb[N];P c[N],d[N];
void solve() {
  for(int i=0;i<N;i++)c[i]=P(a[i],0),d[i]=P(b[i],0);
  FFT(c,th);FFT(d,th);
  for(int i=0;i<N;i++)c[i]*=d[i];
  FFT(c,-th);
  for(int i=0;i<N;i++)a[i]=round(c[i].real()/N);
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int n,m,q,M=210000;
  cin >> n >> m >> q;
  int x[n],y[m];
  for(int i=0; i<n; i++) cin >> x[i];
  for(int i=0; i<m; i++) cin >> y[i];
  int cc[n+1],dd[n+1];
  cc[0]=dd[0]=0;
  for(int i=0; i<n; i++) cc[i+1]=cc[i]+x[i];
  for(int i=0; i<m; i++) dd[i+1]=dd[i]+y[i];
  for(int i=0; i<=n; i++) {
    a[cc[i]]++;
    b[M-cc[i]]++;
  }
  solve();
  for(int i=0; i<M; i++) aa[i]=a[M-i];
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  for(int i=0; i<=m; i++) {
    a[dd[i]]++;
    b[M-dd[i]]++;
  }
  solve();
  for(int i=0; i<M; i++) bb[i]=a[M-i];
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  for(int i=0; i<M; i++) {
    a[i]=aa[i];
    b[M-i]=bb[i];
  }
  a[0]=b[M]=0;
  solve();
  while(q--) {
    int k;
    cin >> k;
    if(k) cout << a[M-k]+a[M+k] << endl;
    else cout << a[M] << endl;
  }
  return 0;
}
