#include <iostream>
#include <string>

using namespace std;

//PAT Basic No.1017 “A除以B”

int main() {
	string A,Q;
	int B, R = 0;
	cin >> A >> B;

	if (A.length() < 10) {
		long long int Ai = strtol(A.c_str(), nullptr, 10);
		R = Ai % B;
		long int Qi = (Ai - R) / B;
		cout << Qi << ' ' << R << endl;
	}
	else {
		unsigned int ptr = 0;
		int Rp = 0;
		bool first = false;
		while (ptr < A.length()) {
			int tmp = Rp * 10 + (A.at(ptr) - '0');
			Rp = tmp % B;
			int Qp = (tmp - Rp) / B;
			if(first)
			Q.push_back(Qp + '0');
			else if(Qp !=0){
				Q.push_back(Qp + '0');
				first = true;
			}
			ptr++;
		}
		R = Rp;
		cout << Q << ' ' << R << endl;
	}
	return 0;
}
