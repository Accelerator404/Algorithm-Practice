#include <iostream>
using namespace std;

//PAT Advanced No.1011 “A+B和C”

int main() {
	int T,i = 0;
	cin >> T;
	while (++i <= T) {
		//使用64bit
		long long int a, b, c;
		cin >> a >> b >> c;
		if (a + b > c)
			cout << "Case #" << i << ": true" << endl;
		else
			cout << "Case #" << i << ": false" << endl;
	}
	return 0;
}
