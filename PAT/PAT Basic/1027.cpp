#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
//PATest Basic Level : No.1027 打印沙漏


//实际上，容易看出沙漏所需字符数为(1+3+5+....)*2-1=n*(1+(2*n-1))/2*2-1=n*(2*n)-1=2*n*n-1
int main() {
	int N,n=0,sum=0,diff;
	char p;
	cin >> N >> p;
	while (true) {
		n++;
		sum = 2 * n * n - 1;
		if (sum > N) {
			n--;
			break;
		}
	}
	sum = 2 * n * n - 1;
	diff = N - sum;
	for (int i = n; i > 1; i--) {
		string blank(n - i, ' ');
		string tmp(2 * i - 1, p);
		tmp = blank + tmp ;
		cout << tmp << endl;
	}
	for (int i = 1; i <= n; i++) {
		string blank(n - i, ' ');
		string tmp(2 * i - 1, p);
		tmp = blank + tmp ;
		cout << tmp << endl;
	}
	cout << diff << endl;
	return 0;
}
