#include <iostream>
#include <cstring>
using namespace std;

/**
 *  字符串中次数第2多的字母
 *
 *  描述
 *  输入一串长度不超过500个符号的字符串，输出在串中出现第2多的英语字母(大小写字母认为相同)和次数
 *  （如果串中有其它符号，则忽略不考虑）。如果有多个字母的次数都是第2多，则按串中字母出现的顺序输出第1个。
 *  例 ab&dcAab&c9defgb
 *  这里，a 和 b都出现3次，c和d都出现2次，e、f 和 g 各出现1次，其中的符号&和9均忽略不考虑。
 *  因此，出现第2多的应该是 c 和 d，但是 d 开始出现的位置在 c 的前面，因此，输出为
 *      D+d:2
 *  (假定在字符串中，次数第2多的字母总存在)
 *
 *  输入
 *  一个字符串
 *
 *  输出
 *  大写字母+小写字母:个数
 *
*/

struct sheet{
    char name = '\0';
    int count = 0;
    int query = -1;
};

char getit(char foo){
    if(foo >=65 && foo <= 90){
        foo += 32;
        return foo;
    }
    else if(foo >= 97 && foo <= 122)
        return foo;
    else
        return '\0';
}

int main() {
    char str[500] = {'\0'};
    sheet letter[26];
    for(int i = 0;i < 26;i++){
        letter[i].name = i + 65;
    }
    cin >> str;
    //对每个字符进行统计，大小写合并
    for(int i = 0;i < strlen(str);i++){
        char temp = getit(str[i]);
        if(temp == '\0')
            continue;
        else{
            letter[temp - 97].count++;
            if(letter[temp -97].query == -1)
                letter[temp -97].query = i;
        }
    }
    //按出现频率排序
    for(int i = 0;i < 25;i++){
        for (int j = i + 1; j < 26; j++) {
            if(letter[i].count < letter[j].count){
                sheet temp = letter[j];
                letter[j] = letter[i];
                letter[i] = temp;
            }
        }
    }
    //按出现顺序排序
    for(int i = 0;i < 25;i++){
        for (int j = i + 1; j < 26; j++) {
            if(letter[i].count == letter[j].count && letter[i].query > letter[j].query){
                sheet temp = letter[j];
                letter[j] = letter[i];
                letter[i] = temp;
            }
        }
    }
    //取出排行第2多且第一次出现的字符
    int k = 1;
    for(int i = 0;i < 26;i++){
        if(letter[i].count < letter[0].count){
            k = i;
            break;
        }
    }
    char dletter = letter[k].name + 32;
    cout << letter[k].name << '+' << dletter << ':' << letter[k].count << endl;
    return 0;
}
