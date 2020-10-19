#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define _for_loop(i,a,b) for(int i = (a);i < (b);++i)

int readint(){
	int x;
	scanf("%d",&x);
	return x;
}

bool cmp(int a,int b){
	return a > b;
}

int main() {
	int n;
	n = readint();
	vector<int> seq(n);
	_for_loop(i,0,n)
		seq[i] = readint();
	int m;
	m = readint();
	_for_loop(z,0,m){
		int l,r,k;
		l = readint();
		r = readint();
		k = readint();
		vector<int> sub(seq.begin()+(l-1),seq.begin()+(r));
		sort(sub.begin(),sub.end(),cmp);
		cout << sub[k-1] << endl;	
	}
	return 0;
}