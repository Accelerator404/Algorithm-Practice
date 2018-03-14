#include <iostream>
using namespace std;

//PAT Basic No.1022 “D进制的A+B”


int main() {
	int A, B, D,s[100],c,m=0;
	cin >> A >> B >> D;
	int p = A + B;
	if (p == 0) {
		cout << 0 << endl;
		return 0;
	}
	while (p != 0) {
		c = p % D;
		p = p / D;
		m++;
		s[m] = c;
	}
	for (int i = m; i > 0; i--) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}
