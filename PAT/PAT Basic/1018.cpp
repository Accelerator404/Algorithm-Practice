#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

//PAT Basic No.1018 “锤子剪刀布”

char bestChoice(int B, int C, int J) {
	if (B>=C && B>=J)
		return 'B';
	else if (C > B && C>=J)
		return 'C';
	else 
		return 'J';
}


int main() {
	int N,AcountW,countP,AcountL;
	int & BcountW = AcountL;
	int & BcountL = AcountW;
	int AB = 0, AC = 0, AJ = 0, BB = 0,BJ = 0,BC = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char A, B;
		cin >> A >> B;
		if (A == 'C' && B == 'J')
			AC++;
		else if (A == 'C' && B == 'B')
			BB++;
		else if (A == 'B' && B == 'C')
			AB++;
		else if (A == 'B' && B == 'J')
			BJ++;
		else if (A == 'J' && B == 'B')
			AJ++;
		else if (A == 'J' && B == 'C')
			BC++;
	}
	AcountW = AC + AB + AJ;
	BcountW = BC + BB + BJ;
	countP = N - AcountW - BcountW;
	cout << AcountW << ' ' << countP << ' ' << AcountL << endl;
	cout << BcountW << ' ' << countP << ' ' << BcountL << endl;
	cout << bestChoice(AB, AC, AJ) << ' ' << bestChoice(BB, BC, BJ) << endl;
	return 0;
}
