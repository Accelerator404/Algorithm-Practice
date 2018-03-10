#include <iostream>
using namespace std;

//PAT Advanced No.1010 “一元多项式求导”

int main() {
	int c, i;
	bool flag = false;
	//利用输入动作触发输入循环
	while (cin >> c >> i) {
		if (c != 0 && i != 0) {
			if (flag)
				cout << ' ';
			else
				flag = true;
			cout << c * i << ' ' << i - 1;
		}
		//注意题设中的指数递降，也就是如果第一次就输入指数为0即触发零多项式判断
		else if (i == 0 && !flag) {
			cout << "0 0" << endl;
			return 0;
		}
	}
	return 0;
}
