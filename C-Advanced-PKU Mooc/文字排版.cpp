#include <iostream>
#include <cstring>
using namespace std;

/**
文字排版
给一段英文短文，单词之间以空格分隔（每个单词包括其前后紧邻的标点符号）。请将短文重新排版，要求如下：
每行不超过80个字符；每个单词居于同一行上；在同一行的单词之间以一个空格分隔；行首和行尾都没有空格。

输入：
第一行是一个整数n，表示英文短文中单词的数目. 其后是n个以空格分隔的英文单词
（单词包括其前后紧邻的标点符号，且每个单词长度都不大于40个字母）。

输出：
排版后的多行文本，每行文本字符数最多80个字符，单词之间以一个空格分隔，每行文本首尾都没有空格。

*/

int main() {
    int n,count = 0;
    cin >> n;
    //为了过oj限定了300单词的上限
    char word[300][40] = {"\0"};
    //输入矩阵数据
    for(int i = 0;i < n;i++){
        cin >> word[i];
    }
    cout << word[0];
    count += strlen(word[0]);
    for(int i = 1;i < n;i++){
        if(count + strlen(word[i]) + 1 <= 80){
            cout << " " << word[i];
            count += strlen(word[i]) + 1;
        }
        else{
            cout << endl;
            count = 0;
            cout << word[i];
            count += strlen(word[i]);
        }
    }
    return 0;
}
