#include<bits/stdc++.h>
using namespace std;


typedef complex<double> P;
typedef pair<P,P> L;

const double EPS = 1e-8;

double dot(P a, P b){ return a.real() * b.real() + a.imag() * b.imag(); }
double cross(P a, P b){ return   a.real() * b.imag() - a.imag() * b.real(); }

//円
struct Circle{
  P c; //中心点
  double r; //半径
  Circle(P c=P(0,0), double r=0):c(c),r(r){}
};

//射影
P proj(P p, L l){
  return l.first + dot(p - l.first, l.second - l.first) / norm(l.second - l.first) * (l.second - l.first);
}

//点から円に引いた接線の交点
vector<P> tangent(Circle c, P p){
  vector<P> res;
  double a = abs(p - c.c);
  if(a < c.r - EPS);
  else if(a < c.r + EPS) res.push_back(p);
  else {
    double b = sqrt(a*a-c.r*c.r);
    double psi = arg(p - c.c);
    double phi = M_PI - acos(b/a);
    res.push_back(p + b * P(cos(psi+phi), sin(psi+phi)));
    res.push_back(p + b * P(cos(psi-phi), sin(psi-phi)));
  }
  return res;
}


//円と円の共通接線
//return vector<L> :: L ( p の接線との交点, q の接線との交点 )
vector<L> tangentCC (Circle p, Circle q) {
    double pr = p.r, qr = q.r;
    P pc = p.c, qc = q.c;
    double d = abs(pc - qc), dr = abs(pr - qr), sr = abs(pr + qr);

    vector<L> ret;
    if (d > sr) {
        // cross pair
        P cp = (pc * qr + qc * pr) / sr;
        vector<P> pts = tangent(p, cp), qts = tangent(q, cp);
        ret.push_back(L(pts[0], qts[0]));
        ret.push_back(L(pts[1], qts[1]));
    } else if (abs(d - sr) < EPS) {
      // cross pair coinside
      P cp = (pc * qr + qc * pr) / sr;
      ret.push_back(L(cp, cp));
    } 

    if (d > dr) {
        // outer pair
      if (abs(pr - qr) < EPS ){
	P v = (qc - pc) / d;
	v *= P(0, 1);
	ret.push_back(L(pc + v, qc + v));
	ret.push_back(L(pc - v, qc - v));
      } else {
	P cp = pc + (qc - pc) * pr / (pr - qr);
	vector<P> pts = tangent(p, cp), qts = tangent(q, cp);
	ret.push_back(L(pts[0], qts[0]));
	ret.push_back(L(pts[1], qts[1]));
      }
    } else if (abs(d - dr) < EPS) {
      // outer pair coinside
      P cp = (qc - pc) * pr / (pr - qr);
      ret.push_back(L(cp, cp));
    } 
    
    return ret;
}

// 線分と点の交差判定
bool isIntersectSP(L s, P p){
  return abs(s.first-p) + abs(s.second-p) - abs(s.second-s.first) < EPS; 
}

//円と線分の交点
vector<P> getIntersectCS(Circle c, L s){
  vector<P> res;
  P h = proj(c.c, s);
  double d = abs(c.c - h);
  if(d > c.r + EPS);
  else if(d > c.r - EPS){
    if(isIntersectSP(s,h)) res.push_back(h);
  }
  else {
    P v = s.second - s.first;
    v = (sqrt(c.r*c.r - d*d) / abs(v)) * v;
    if(isIntersectSP(s, h+v)) res.push_back(h+v);
    if(isIntersectSP(s, h-v)) res.push_back(h-v);
  }
  return res;
}

//円と直線の交点
vector<P> getIntersectCL(Circle c, L l){
  vector<P> res;
  P h = proj(c.c, l);
  double d = abs(c.c - h);
  if(d > c.r + EPS);
  else if(d > c.r - EPS) res.push_back(h);
  else{
    P v = l.second - l.first;
    v = (sqrt(c.r*c.r - d*d) / abs(v)) * v;
    res.push_back(h+v);
    res.push_back(h-v);
  }
  return res;
}


int N;
int getBit(const vector<Circle>& c, L s ){
  int bit = 0;
  for(int k=1;k<N;k++){
    if( !(getIntersectCS( c[k], s ).empty()) ){
      bit |= (1<<(k-1));
    }
  }
  return bit;
}

int dp[(1<<16)];

int main(){
  cin >> N;
  vector<Circle> c;
  for(int i=0;i<N;i++){
    int x,y,r;
    cin >> x >> y >> r;
    c.push_back( Circle(P(x,y),r) );
  }

  vector<int> ss;
  for(int l=0;l<N;l++){
    for(int i=l+1;i<N;i++){
      vector<L> ret = tangentCC( c[l],c[i] );
      ret.push_back(L(c[l].c,c[i].c));
      for(int j=0;j<(int)ret.size();j++){
	//   cout << ret[j].first << " -> " << ret[j].second << endl;
	vector<P> g = getIntersectCL(c[0],ret[j]);
	if( g.empty() ) continue;

	P v = ret[j].first - g[0];
	v*=200.0;
	P nv = g[0] + v;
	ss.push_back( getBit(c,L(g[0],nv)) );

	v = ret[j].second - g[0];
	v*=200.0;
	nv = g[0] + v;
	ss.push_back( getBit(c,L(g[0],nv)) );
      }
    }
  }
    

  int n = N-1;
  fill(dp,dp+(1<<n),100);
  dp[0] = 0;
  for(int i=0;i<(1<<n);i++){
    for(int j = 0;j<(int)ss.size();j++){
      dp[i|ss[j]] = min( dp[i|ss[j]], dp[i] + 1);
    }
  }
  cout << dp[(1<<n)-1] << endl;
  
}
