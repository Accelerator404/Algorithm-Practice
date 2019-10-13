#include <iostream>
using namespace std;

//最长单词2
//一个以'.'结尾的简单英文句子，单词之间用空格分隔，没有缩写形式和其它特殊形式
//输入:一个以'.'结尾的简单英文句子（长度不超过500），单词之间用空格分隔，没有缩写形式和其它特殊形式
//输出:该句子中最长的单词。如果多于一个，则输出第一个

int main() {
    char sentence[500] = "\0";
    int space[500] = {0},length[250] = {0};
    int temp, j = 0, max;
    cin.getline(sentence,500);
    for (int i = 0; i < 500; i++){
        if(sentence[i] == ' ') {
            space[j] = i;
            j++;    //j存储空格数
        }
        else if(sentence[i] == '.') {
            space[j] = i; //把句号位置存放在最后一个空格之后，也就是j+1
            goto part; //用goto代替break跳出循环后才通过poj打分，明明在本地gcc通过编译了，也是……
        }
    }

part:
    length[0] = space[0];  //第一个空格在第n位，首个单词的长度就等于n-1
    for (int i = 1; i < j+1; i++){   //此时j为空格个数
        length[i] = space[i] - space[i-1] - 1;
    }//共j+1个单词

    temp = length[0],max = 0;
    for (int i = 0; i < j+1; i++){
        if (length[i] > temp){
            temp = length[i];
            max = i; //最长单词在length数组的下标
        }
    }
    //此时space[max]即为最长单词后方空格在原句子中的坐标（max<j情况)
    if (max == 0){
        for (int i = 0; i < space[0]; i++)
            cout << sentence[i];
    }
    else {
        for (int i = space[max-1] + 1; i < space[max]; i++)
            cout << sentence[i];
    }
    return 0;
}
