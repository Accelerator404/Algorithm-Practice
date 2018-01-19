#include <iostream>
using namespace std;

/**
 * 简单的学生信息处理程序实现
 *
 * 描述:
 * 在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
 *
 * 输入：
 * 姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
 * 其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
 * 各部分内容之间均用单个英文逗号","隔开，无多余空格。
 *
 * 输出:
 * 一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
 * 各部分内容之间均用单个英文逗号","隔开，无多余空格。
 */

class student{
private:
    char name[15] = {'\0'};
    int age = 0;
    char studentID[15] = {'\0'};
    int score1 = 0,score2 = 0,score3 = 0,score4 = 0;
public:
    void getInfo(){
        cin.getline(name,15,',');
        cin >> age;cin.get();
        cin.getline(studentID,15,',');
        cin >> score1;cin.get();cin >> score2;cin.get();
        cin >> score3;cin.get();cin >> score4;
    }
    char * Name(){
        return name;
    }
    char * ID(){
        return studentID;
    }
    int Age(){
        return age;
    }
    int avgScore(){
        return (score1 + score2 + score3 + score4)/4;
    };
    //可以直接调用此函数输出
    void outputInfo(){
        cout << name << ',' << age << ',' << studentID << ',' << avgScore();
    }
};

int main() {
    student dude;
    dude.getInfo();
    cout << dude.Name() << ',' << dude.Age() << ',' << dude.ID() << ',' << dude.avgScore() << endl;
    return 0;
}
