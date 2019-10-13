#include<iostream>
#include<cstdio>
#define CLK_TCK 100;
using namespace std;
//PATest Basic Level : No.1026 程序运行时间

int main() {
	int C1, C2;
	cin >> C1 >> C2;
	// 50 用于实现四舍五入
	float d = C2 - C1 + 50;
	int hour = d / 360000;
	d = d - hour * 360000;
	int minute = d / 6000;
	d = d - minute*6000;
	int second = d / CLK_TCK;
	printf("%02d:%02d:%02d\n", hour, minute, second);
	return 0;
}
