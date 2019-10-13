#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//PATest Basic Level : No.1030 完美数列

int main() {
	int N,num=0,len=0;
	//p大于32bit
	long long int p;
	vector<int> list;
	cin >> N>> p;
	list.resize(N);
	for (int i = 0; i < N; i++) {
		cin>> list[i];
	}
	sort(list.begin(), list.end(),less<int>());
	//注意，固定最大值与最小值都不可取，最长数列最大值最小值完全可能不是输入数的最大值最小值
	//所以双循环，最大值与最小值都可以动，当前最小值取得最长数列后就取更大的最小值重新判断
	//从+目前最长数列长度开始判断，节约时间
	for (int i = 0; i < N; i++) {
		for (int j = i + num; j < N; j++) {
			if (list[j]<=list[i]*p) {
				len = j - i + 1;
				if (len > num)
					num = len;
			}
			else
				break;
		}
	}
	cout << num << endl;
	return 0;
}
