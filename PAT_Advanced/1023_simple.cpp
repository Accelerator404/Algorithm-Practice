#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//PAT Advanced 1023 Have Fun with Numbers

/*
 * 采用更简单的方法
 */
int main(){
    vector<int> book(10,0);
    string s;
    cin >> s;
    bool flag = false;
    int len = strlen(s.c_str());
    //一次循环，先统计原数，再翻倍该位数字，在出现次数中减去新的该位数
    for(int i = len - 1; i >= 0; i--) {
        int temp = s[i] - '0';
        book[temp]++;
        temp = temp * 2 + flag;
        flag = false;
        if(temp >= 10) {
            temp = temp - 10;
            flag = true;
        }
        s[i] = (temp + '0');
        book[temp]--;
    }
  bool flag1 = false;
    for (int i = 0; i < 10; ++i) {
        if(book[i] != 0){
            flag1 = true;
        }
    }
    printf("%s",(flag||flag1)?"No\n":"Yes\n");
    if(flag)
        cout<<1;
    cout << s << endl;
    return 0;
}
