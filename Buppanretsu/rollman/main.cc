#include <iostream>
#define L 0
#define R 1

bool check(int l, int r, int W, int H){
  if(l < W){
    if(l == r) return true;
    else return false;
  }else if(W < l && l < W+H-1){
    if(l-2 == r) return true;
    else return false;
  }else{
    if(l-4 == r) return true;
    else return false;
  }
}

int main(void){
  int W, H, N;
  int ans = 0;
  std::cin >> W >> H;
  std::cin >> N;
  int l, r;
  l = r = 1;

  for(int i=0; i < N; i++){
    int p; std::cin >> p;
    if(p == L){
      l++;
      if(check(l, r, W, H)) ans++;
    }else{
      r++;
      if(check(l, r, W, H)) ans++;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
