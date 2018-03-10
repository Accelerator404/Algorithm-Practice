#include <iostream>
#include <string>
#include <vector>


using namespace std;

//PAT Advanced No.1009 “说反话！”

int main() {
	string a,aSub;
	vector<string> words;
	int count = 0;
	getline(cin, a);
	aSub = a;
	while (aSub.length() > 0) {
		count++;
		int space;
		if (aSub.find_first_of(' ') == string::npos) {
			words.push_back(aSub);
			break;
		}
		space = aSub.find_first_of(' ');
		words.push_back(aSub.substr(0, space));
		aSub = aSub.substr(space + 1, a.length());
	}
	for (int i = count - 1;i >= 0; --i)
	{
		if (i != count - 1)
			cout << ' ';
		cout << words[i];
	}
	cout << endl;
	return 0;
}
