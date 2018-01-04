#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

//扩号匹配问题
//在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；
// 规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。
// 写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。
// 不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注.
//输入：输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
//注意：cin.getline(str,100)最多只能输入99个字符！
//输出：对每组输出数据，!!!输出两行，第一行包含原始输入字符!!!，
// 第二行由"$","?"和空格组成，"$"和"?"表示与之对应的左括号和右括号不能匹配。


int main() {
    char data[100] = {'\0'};
    while(cin.getline(data, 101)) {
        char tag[100] = {'\0'};
        stack<int> Hop;
        for(int i = 0; i < strlen(data);i++){
            if(data[i] == '('){
                Hop.push(i);  //将左括号位置入栈
                tag[i] = ' ';
            }
            else if(data[i] == ')'){
                if(Hop.empty())
                    tag[i] = '?'; //由于堆栈特性，栈顶若是左括号就可以和右括号匹配
                else{
                    tag[i] = ' ';
                    Hop.pop(); //出栈
                }
            }
            else
                tag[i] = ' ';
        }
        while(!Hop.empty()){
            tag[Hop.top()] = '$';  //标记栈顶无法匹配的左括号
            Hop.pop();
        }
        puts(data);
        puts(tag);
        memset(data,'\0',100);
    }
    return 0;
}
