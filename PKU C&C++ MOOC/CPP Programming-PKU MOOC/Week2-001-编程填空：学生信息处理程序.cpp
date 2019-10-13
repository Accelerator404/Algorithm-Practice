#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>

using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第二周001
 *  001:编程填空：学生信息处理程序
 *  描述
 *  实现一个学生信息处理程序，计算一个学生的四年平均成绩。
 *  要求实现一个代表学生的类，并且类中所有成员变量都是【私有的】。
 *  补充下列程序中的 Student 类以实现上述功能。
 *
 *  输入
 *  输入数据为一行，包括：
 *  姓名,年龄,学号,第一学年平均成绩,第二学年平均成绩,第三学年平均成绩,第四学年平均成绩。
 *  其中姓名为由字母和空格组成的字符串（输入保证姓名不超过20个字符，并且空格不会出现在字符串两端），
 *  年龄、学号和学年平均成绩均为非负整数。信息之间用逗号隔开。
 *
 *  输出
 *  输出一行数据，包括：
 *  姓名,年龄,学号,四年平均成绩。
 *  信息之间用逗号隔开。
 */


class Student {
// 在此处补充你的代码
private:
    string name;
    int age,ID,scoreY1,scoreY2,scoreY3,scoreY4;
    double avgScore;
    string splitSTR(string & input){
        string firstWord;
        int p = input.find_first_of(',');
        if(p != string::npos){
            firstWord = input.substr(0,p);
            if(p == input.length())
                input = "";
            else
                input = input.substr(p+1);
        }
        else{
            firstWord = input;
            input = "";
        }
        return firstWord;
    }
public:
    Student(){
        name = "";
        age = ID = scoreY1 = scoreY2 = scoreY3 = scoreY4 = avgScore = 0;
    }
    void input(){
        string raw_input;
        getline(cin,raw_input);
        if(raw_input.find_first_of(',') == string::npos)
            return;
        name = splitSTR(raw_input);
        age = stoi(splitSTR(raw_input));
        ID = stoi(splitSTR(raw_input));
        scoreY1 = stoi(splitSTR(raw_input));
        scoreY2 = stoi(splitSTR(raw_input));
        scoreY3 = stoi(splitSTR(raw_input));
        scoreY4 = stoi(splitSTR(raw_input));
    }
    void  calculate(){
        avgScore = (scoreY1 + scoreY2 +scoreY3 +scoreY4)/4.0;
    }
    void output(){
        cout << name << ',' << age << ',' << ID << ',';
        if(avgScore - (int)avgScore < 0.2)
            cout << (int)avgScore << endl;
        else
            cout << avgScore << endl;
    }
    // 结束
};

int main() {
    Student student;        // 定义类的对象
    student.input();        // 输入数据
    student.calculate();    // 计算平均成绩
    student.output();       // 输出数据
}