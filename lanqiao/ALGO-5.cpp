#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define _for_loop(i,a,b) for(int i = (a);i < (b);++i)


long long int readint(){
	long long int x;
	scanf("%lld",&x);
	return x;
}

int main() {
	int n,m;
	vector<int> dis(200002,(int)(pow(2,30)+1));
	vector<int> u(200001,0);
	vector<int> v(200001,0);
	vector<int> l(200001,0);
	n = readint();
	m = readint();
	bool get_first = false;
	_for_loop(i,1,m+1){
		scanf("%d %d %d",&u[i],&v[i],&l[i]);
		if(u[i]==1){
			dis[v[i]] = l[i];
		}
	}
	_for_loop(k,1,n){
		bool loose = false;
		_for_loop(i,1,m+1){
			if(dis[v[i]] > dis[u[i]] + l[i]){
				dis[v[i]] = dis[u[i]] + l[i];
				loose = true;
			}
		}
		if(!loose)
			break;
	}
	_for_loop(i,2,n+1){
		printf("%d\n",dis[i]);
	}
	
	return 0;
}