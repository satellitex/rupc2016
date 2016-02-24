#include<bits/stdc++.h>
using namespace std;
  
template<typename AlphaT>
static void sa_is_countingAlphabets(const AlphaT *str, int n, int AlphaSize, std::vector<int> &bucketOffsets, bool b = false) {
	if(b || (int)bucketOffsets.size() / 2 >= AlphaSize) {
		std::vector<int>::iterator alphabetCounts =
			b ? bucketOffsets.begin() : bucketOffsets.begin() + AlphaSize;
		std::fill(alphabetCounts, alphabetCounts + AlphaSize, 0);
		for(int i = 0; i < n; i ++)
			alphabetCounts[(int)str[i]] ++;
	}
}

template<typename AlphaT>
static void sa_is_getBucketOffsets(const AlphaT *str, int n, bool dir, int AlphaSize, std::vector<int> &bucketOffsets) {
	//AlphaSizeが大きい場合にはbucketOffset求めるたびにalphabetを数えてメモリ量を少なくし、
	//AlphaSizeが小さい場合にはbucketOffsetをalphabetCountsと別の場所に置くことにする。
	std::vector<int>::iterator alphabetCounts;
	if((int)bucketOffsets.size() / 2 < AlphaSize) {
		sa_is_countingAlphabets(str, n, AlphaSize, bucketOffsets, true);
		alphabetCounts = bucketOffsets.begin();
	}else alphabetCounts = bucketOffsets.begin() + AlphaSize;
	int cumsum = 1;	//'$'の分
	if(dir) {
		for(int i = 0; i < AlphaSize; i ++) {
			cumsum += alphabetCounts[i];
			bucketOffsets[i] = cumsum;
		}
	}else {
		for(int i = 0; i < AlphaSize; i ++) {
			int x = alphabetCounts[i];
			bucketOffsets[i] = cumsum;
			cumsum += x;
		}
	}
}


template<typename AlphaT>
static void sa_is_inducedSort(const AlphaT *str, int n, int AlphaSize, const std::vector<bool> &types, int *sa, std::vector<int> &bucketOffsets) {
	sa_is_getBucketOffsets(str, n, false, AlphaSize, bucketOffsets);
	for(int i = 0; i < n; i ++) {
		int j = sa[i] - 1;
		if(j >= 0 && !types[j]) sa[bucketOffsets[(int)str[j]] ++] = j;
	}

	sa_is_getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(int i = n; i >= 1; i --) {
		int j = sa[i] - 1;
		if(j >= 0 && types[j]) sa[-- bucketOffsets[(int)str[j]]] = j;
	}
}

//strは[0,n)が有効で番兵は含まれない。saは[0,n]が有効
template<typename AlphaT>
static void sa_is_rec(const AlphaT *str, int n, int AlphaSize, int *sa, std::vector<int> &bucketOffsets) {
	std::vector<bool> types(n+1);
	types[n-1] = 0; types[n] = 1;
	for(int i = n-2; i >= 0; i --)
		types[i] = str[i] < str[i+1] || (str[i] == str[i+1] && types[i+1]);

	sa_is_countingAlphabets(str, n, AlphaSize, bucketOffsets);
	sa_is_getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	std::fill(sa, sa + n + 1, -1);
	for(int i = 1; i < n; i ++)
		if(types[i] && !types[i-1]) sa[-- bucketOffsets[(int)str[i]]] = i;
	sa[0] = n;
	sa_is_inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);

	int n1 = 0;
	for(int i = 0; i <= n; i ++) {
		int j = sa[i];
		if(j > 0 && types[j] && !types[j-1]) sa[n1 ++] = j;
	}

	//LMS substringsを番号付けする。sa[0..n1-1]にソートされている。
	//メモリのためにsaの右半分をバッファに利用する。
	//さらにそこでposの順序で整数ソートすることを同時に行う。
	//ここでLMS substringが連続して現れないことやLMS substringの数がn/2以下であることを利用してなんとか1つの配列でやる
	int *buffer = sa + n1;
	std::fill(buffer, sa + n + 1, -1);
	int uniqueLMSCount = 0, prevPos = -1;
	assert(sa[0] == n);
	buffer[sa[0] / 2] = uniqueLMSCount ++;	//'$'
	for(int i = 1; i < n1; i ++) {
		int pos = sa[i]; bool diff = false;
		if(prevPos == -1) diff = true;
		else for(int j = pos, k = prevPos; ; j ++, k ++) {
				if(str[j] != str[k] || types[j] != types[k]) {
					diff = true;
					break;
				}else if(j != pos && ((types[j] && !types[j-1]) || (types[k] && !types[k-1])))
					break;
			}
		if(diff) {
			uniqueLMSCount ++;
			prevPos = pos;
		}
		buffer[pos / 2] = uniqueLMSCount - 1;
	}
	for(int i = n, j = n; i >= n1; i --)
		if(sa[i] >= 0) sa[j --] = sa[i];

	int *sa1 = sa, *s1 = sa + n + 1 - n1;
	if(uniqueLMSCount == n1)
		for(int i = 0; i < n1; i ++) sa1[s1[i]] = i;
	else
		sa_is_rec<int>(s1, n1 - 1, uniqueLMSCount, sa1, bucketOffsets);

	sa_is_countingAlphabets(str, n, AlphaSize, bucketOffsets);
	sa_is_getBucketOffsets(str, n, true, AlphaSize, bucketOffsets);
	for(int i = 1, j = 0; i <= n; i ++)
		if(types[i] && !types[i-1]) s1[j ++] = i;
	for(int i = 0; i < n1; i ++) sa1[i] = s1[sa1[i]];
	std::fill(sa + n1, sa + n + 1, -1);
	for(int i = n1-1; i >= 1; i --) {
		int j = sa[i]; sa[i] = -1;
		sa[-- bucketOffsets[(int)str[j]]] = j;
	}
	sa_is_inducedSort(str, n, AlphaSize, types, sa, bucketOffsets);
}

//suffixArrayは(n+1)のサイズ
static void buildSuffixArray(const char *str, int n, int charSize, int *suffixArray) {
	if(n == 0) suffixArray[0] = 0;
	else {
		//I = sizeof(int) * CHAR_BITS として
		//suffixArray + bucketOffsets + types + 関数ローカル変数
		//= n*I + max(charSize, n/2)*I + 2*n + O(log n) bits
		//I = 4 * 32でcharSizeが十分小さいとすると:
		//(6+1/16) * n + O(log n) bytes
		std::vector<int> bucketOffsets(std::max(charSize, (n+1) / 2) + 1);
		sa_is_rec<char>(str, n, charSize, &suffixArray[0], bucketOffsets);
	}
}

static void buildSuffixArray(const char *str, int n, int *suffixArray) {
	char maxElem = *std::max_element(str, str + n);
	assert(maxElem+0 < std::numeric_limits<int>::max());
	buildSuffixArray(str, n, (int)maxElem+1, suffixArray);
}

//一致しないギリギリの上
int upper_bound(const string& str, int *surffix_array,const string &cs){
  int ok = 0, ng = str.size()+1;
  while( ng - ok > 1  ){
    int mid = (ok+ng)/2;
    if( str.substr(surffix_array[mid],cs.size()) <= cs ){
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ng;
}

//一致するギリギリの下
int lower_bound(const string& str, int *surffix_array,const string &cs){
  int ng = -1, ok = str.size()+1;
  while( ok - ng >  1 ){
    int mid = (ok+ng)/2;
    if( str.substr(surffix_array[mid],cs.size()) < cs )
      ng = mid;
    else
      ok = mid;
  }
  return ok;
}
//個数 upper_boud - lower_bound

int A[100001];
int main(){
  string s;
  cin >> s;
  buildSuffixArray(s.c_str(),s.size(),A);
  for(int i=0;i<=s.size();i++) {
    cout << A[i] << " : " << s.substr(A[i]) << endl;    
  }
  string m;
  while( cin >> m ){
    cout << upper_bound(s,A,m) << " - " << lower_bound(s,A,m) << endl;
  }
}
