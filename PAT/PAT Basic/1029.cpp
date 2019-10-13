#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
//PATest Basic Level : No.1029 旧键盘

int main() {
	string goal, fact;
	map<char, int> alphabet;
	map<int, char> result;
	cin >> goal >> fact;
	//小写字母转为大写字母（可以用isupper函数）
	for (int i = 0; i < goal.length(); i++) 
		if (goal[i] - 'a' >= 0 && 'z' - goal[i] >= 0) 
			goal[i] = goal[i] - 'a' + 'A';
	for (int i = 0; i < fact.length(); i++) 
		if (fact[i] - 'a' >= 0 && 'z' - fact[i] >= 0) 
			fact[i] = fact[i] - 'a' + 'A';
	//激活字母表
	for (int i = 0; i < goal.length(); i++) 
		alphabet[goal.at(i)] = -1;
	//记录第一次出现位置
	for (int i = 0; i < goal.length(); i++) 
		if(alphabet[goal.at(i)] == -1)
			alphabet[goal.at(i)] = i;
	//标记能正确打出的字符
	for (int i = 0; i < fact.length(); i++) 
		alphabet[fact.at(i)] = -1;
	//反转key与value，按出现顺序储存结果（利用map自带key排序）
	for (auto it = alphabet.begin(); it != alphabet.end(); it++) 
		if (it->second > -1) 
			result[it->second] = it->first;
	//输出
	for (auto it = result.begin(); it != result.end(); it++) 
		cout << it->second;
	cout << endl;
	return 0;
}
