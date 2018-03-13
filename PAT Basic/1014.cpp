#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//PAT Basic No.1014 “福尔摩斯的约会”
string str1, str2, str3, str4;


void dayHour() {
	vector<int> data;
	bool first = true;
	//首先找出第一对相同的A-G字母，然后继续往下寻找一对相同的0-9或A-N字符
	for ( int i = 0; i < str1.length() && i < str2.length(); i++) {
		if (first&& str1.at(i) - 'A' >= 0 && str1.at(i) - 'G' <= 0 && 
			str1.at(i) == str2.at(i)) {
				data.push_back(str1.at(i));
				first = false;
				continue;
		}
		if (!first&& str1.at(i) == str2.at(i) && (str1.at(i)>='A' && str1.at(i) <= 'N'
			|| str1.at(i) >= '0' && str1.at(i) <= '9')) {
			data.push_back(str1.at(i));
			break;
		}
	}
	data[0] -= 'A';
	data[0] += 1;
	if (data[0] == 1)
		cout << "MON";
	else if (data[0] == 2)
		cout << "TUE";
	else if (data[0] == 3)
		cout << "WED";
	else if (data[0] == 4)
		cout << "THU";
	else if (data[0] == 5)
		cout << "FRI";
	else if (data[0] == 6)
		cout << "SAT";
	else if (data[0] == 7)
		cout << "SUN";
	cout << ' ';
	//个位数前面要补个0
	if (data[1] - '0' <= 9)
		cout <<'0'<< (char)data[1];
	else
		cout << data[1] - 'A' + 10 ;
}

void minute() {
	int min;
	for (int i = 0; i < str3.length() && i < str4.length(); i++)
		if (str3.at(i) - 'A' >= 0 && str3.at(i) - 'Z' <= 0 
			|| str3.at(i) - 'a' >= 0 && str3.at(i) - 'z' <= 0) {
			if (str3.at(i) == str4.at(i)) {
				min = i;
				break;
			}
		}
	cout << ':';
	if (min <= 9)
		cout << '0';
	cout << min << endl;
}

int main() {
	cin >> str1 >> str2 >> str3 >> str4;
	dayHour();
	minute();
	return 0;
}
