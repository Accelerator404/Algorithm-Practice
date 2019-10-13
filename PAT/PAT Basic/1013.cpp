#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//PAT Basic No.1013 “数素数”
vector<int> primes;

bool prime(int & i) {
	if (i < 2)
		return false;
	else if (i == 2)
		return true;
	int sqrti = sqrt(i) + 1;
	int greatestPrimeListed;
	int & gP = greatestPrimeListed;
	if (primes.size() > 0)
		gP = *(primes.end() - 1);
	else
		gP = 0;
  //当待判断数的平方根小于等于已求出最大素数时，枚举所有小于等于平方根的素数
	if (sqrti <= gP) {
		for (auto it = primes.begin(); it != primes.end() && *it <= sqrti; it++) 
			if (i % *it == 0)
				return false;
		return true;
	}
  //当至少有一部分小于等于待判断数平方根的素数没有列入以求表时（本程序实际不会发生这种情况），枚举所有这部分区间内的整数
	else {
		for (auto it = primes.begin(); it != primes.end(); it++)
			if (i % *it == 0)
				return false;
		int start;
		if (primes.size() == 0)
			start = 2;
		else 
			start = *(primes.end() - 1);
		for (int k = start; k <= sqrti; k++) 
			if (i % k == 0)
				return false;
		return true;
	}
}

int main() {
	int M, N,count = 0,i = 0;
	bool flag = false;
	cin >> M >> N;
  //保证N >= 2
	if (M == N && M == 1) {
		cout << 2 << endl;
		return 0;
	}
  //求出前N位所有素数
	while (count < N) {
		i++;
		if (prime(i)) {
			primes.push_back(i);
			count++;
		}
	}
	for (int k = M - 1; k < N;k++) {
		int ki = k - (M - 1) + 1;
		if (ki % 10 != 1)
			cout << ' ';
		cout << primes[k];
		if (ki % 10 == 0)
			cout << endl;
	}


	return 0;
}
