#include <iostream>
#include <string>
using namespace std;

//PAT Basic No.1016 “部分A+B”

int P(string K, int Dk) {
	int count = 0;
	for (int i = 0; i < K.length(); ++i) 
		if (K.at(i) - '0' == Dk)
			count++;
	if (count == 0)
		return 0;
	else {
		string Pk(count, Dk + '0');
		return strtol(Pk.c_str(), nullptr, 10);
	}
}

int main() {
	int Da,Db;
	string A, B;
	cin >> A >> Da >> B >> Db;
	cout << P(A, Da) + P(B, Db) << endl;;
	return 0;
}
