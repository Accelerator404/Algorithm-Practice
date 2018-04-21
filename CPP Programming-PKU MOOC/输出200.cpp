/**
 * 输出200
 *
 * 描述
 * 使以下程序输出200
 *
 */


#include<iostream>
using namespace std;
class Number {
public:
    int num;
    Number(int n=0): num(n) {}
// 在此处补充你的代码
    //最简单的运算符超载，返回同类型
    inline Number operator*(const Number & num1){
        Number sol(num*num1.num);
        return sol;
    }
    //赋值超载前面要加上&，操作this指针
    Number &operator=(const Number & num1){
        this->num = num1.num;
        return *this;
    }
    //强制类型转换只需要按照operator TypeName() const{ //Description; }格式来编写
    operator int() const{
        return num;
    }

//end
};

int main() {
    Number n1(10), n2(20);
    Number n3;n3 = n1*n2;
    cout << int(n3) << endl;
    return 0;
}
