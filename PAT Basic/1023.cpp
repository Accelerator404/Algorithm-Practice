#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Basic No.1023 “组个最小数”

bool compare(int a, int b) {
	return a < b;
}

int main() {
	int num[10],count = 0;
	vector<int> list;
	for  (int i = 0;  i < 10;  i++)
	{
		cin >> num[i];
		count += num[i];
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] == 0) {
			continue;
		}
		else {
			for(int j =0;j<num[i];j++)
				list.push_back(i);
		}
	}
	sort(list.begin(), list.end(), compare);
	if (num[0] != 0) {
		for (int i = 0; i < count; i++)
			if (list[i] != 0) {
				int tmp = list[i];
				list[i] = list[0];
				list[0] = tmp;
				break;
			}
	}
	for (auto it = list.begin(); it != list.end();it++) {
		cout << *it;
	}
	cout << endl;

	return 0;
}
