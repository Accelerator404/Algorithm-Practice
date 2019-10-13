#include <iostream>
using namespace std;


//单词翻转
//输入一个句子（一行），将句子中的每一个单词翻转后输出。
//输入：只有一行，为一个字符串，不超过500个字符。单词之间以空格隔开。所谓单词指的是所有不包含空格的连续的字符。
//这道题请用cin.getline输入一行后再逐个单词递归处理。
//输出：翻转每一个单词后的字符串，单词之间的空格需与原文一致。


void mirror(int n,char word[]) {   //还没找到纯靠递归的算法，还需要一个枚举来识别单词
    if(word[n] != ' ' && word[n] != '\0'){
        mirror(n+1,word);
        cout << word[n];
    }
}

int main() {
    char stor[500] = {'\0'};
    cin.getline(stor,500);
    mirror(0,stor);
    for (int i = 1; i < 500;i++){
        if(stor[i] == ' '){
            cout << ' ';
        }
        else if(stor[i-1] == ' ' && stor[i] != ' '){
            mirror(i,stor);
        }
    }
    return 0;
}
