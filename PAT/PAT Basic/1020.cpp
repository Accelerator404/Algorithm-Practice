#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//PAT Basic No.1020 “月饼”

struct bind {
	float storage;
	float totalprice;
	float price;
};

bool compare(bind a, bind b) {
	return a.price > b.price;
}

int main() {
	int N;
	float D,earning = 0;
	vector<bind> mooncake;
	cin >> N >> D;
	mooncake.resize(N);
	for (int i = 0; i < N; i++) 
		cin >> mooncake[i].storage;
	for (int i = 0; i < N; i++) {
		cin >>mooncake[i].totalprice;
		mooncake[i].price = mooncake[i].totalprice / mooncake[i].storage;
	}
	sort(mooncake.begin(), mooncake.end(), compare);
	int ptr = 0;
	while (D > 0 && ptr<N) {
		if (D >= mooncake[ptr].storage) {
			D -= mooncake[ptr].storage;
			earning += mooncake[ptr].totalprice;
			mooncake[ptr].storage = 0;
		}
		else {
			earning += (mooncake[ptr].price * D);
			mooncake[ptr].storage -= D;
			D == 0;
			break;
		}
		ptr++;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << earning << endl;
	return 0;
}
