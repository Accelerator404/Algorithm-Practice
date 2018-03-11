#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//PAT Advanced No.1012 “数字分类”
vector<int> A2E, A4E;
int A1 = 0,A2 = 0,A3 = 0,A5 = 0;
float A4 = 0;
bool ID[5] = { false,false,false,false,false };
void inputNum(int N) {
	for (int i = 0; i < N; i++)
	{
		int Num;
		cin >> Num;
		if (Num % 10 == 0)
			A1 += Num;
		else if (Num % 5 == 1)
			A2E.push_back(Num);
		else if (Num % 5 == 2)
			A3++;
		else if (Num % 5 == 3)
			A4E.push_back(Num);
		else if (Num % 5 == 4 && Num > A5)
			A5 = Num;
	}
	if (A1 > 0)
		ID[0] = true;
	if (A2E.size() > 0)
		ID[1] = true;
	if (A3 > 0)
		ID[2] = true;
	if (A4E.size() > 0)
		ID[3] = true;
	if (A5 > 0)
		ID[4] = true;
}

void output() {
	if (ID[0]) {
		cout << A1 << ' ';
	}
	else {
		cout << "N ";
	}

	if (ID[1]) {
		for (auto it = A2E.begin(); it != A2E.end(); ) {
			A2 += *it;
			if (++it != A2E.end()) {
				A2 -= *it;
				it++;
			}
		}
		cout << A2 << ' ';
	}
	else {
		cout << "N ";
	}

	if(ID[2]){
		cout << A3 << ' '; 
	}
	else {
		cout << "N ";
	}

	if (ID[3]) {
		int count = 0;
		for (auto it = A4E.begin(); it != A4E.end(); ++it) {
			A4 += *it;
			count++;
		}
		A4 /= (float)count;
		cout << setiosflags(ios::fixed) << setprecision(1) << A4 << ' ';
	}
	else {
		cout << "N ";
	}
	if (ID[4]) {
		cout << A5 << endl;
	}
	else {
		cout << "N" << endl;
	}
}

int main() {
	int N;
	cin >> N;
	inputNum(N);
	output();


	return 0;
}
