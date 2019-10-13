#include <iostream>
#include <string>
#include <map>
using namespace std;

//PAT Basic No.1021 “个位数统计”


int main() {
	string N;
	map<char, int> stat;
	cin >> N;
	for (int i = 0; i < 10; i++)
		stat[i + '0'] = 0;
	for (int i = 0; i < N.length(); i++) 
		stat[N[i]]++;
	for (int i = 0; i < 10; i++) {
		if (stat[i + '0'] > 0)
			cout << i << ':' << stat[i + '0'] << endl;
	}
	return 0;
}
