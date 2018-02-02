#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/**
 * 大整数的加减乘除
 *
 * 描述:
 * 给出两个正整数以及四则运算操作符（+ - * /），求运算结果。
 *
 * 输入:
 * 第一行：正整数a，长度不超过100
 * 第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
 * 第三行：正整数b，长度不超过100
 * 保证输入不含多余的空格或其它字符
 *
 * 输出
 * 一行：表达式“a o b”的值。
 *
 * 补充说明：
 * 1. 减法结果有可能为负数
 * 2. 除法结果向下取整
 * 3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符
 */

class bigInt{
private:
    string value;
    //flag表示大数符号
    bool flag;
public:
    bigInt():value(""),flag(true){};
    bigInt(string input):value(input),flag(true){}
public:
    inline int compareSize(string str1,string str2);
    friend ostream &operator <<(ostream & os,const bigInt & bigInt1);
    friend istream &operator >>(istream & is,bigInt & bigInt1);
    bigInt operator+(const bigInt & Num);
    bigInt operator-(const bigInt & Num);
    bigInt operator*(const bigInt & Num);
    bigInt operator/(const bigInt & Num);
};

inline int bigInt::compareSize(string str1, string str2) {
    if(str1.size() < str2.size())
        return -1;
    else if(str1.size() > str2.size())
        return 1;
    for (int i = 0; i < str1.size(); ++i) {
        if(str1.substr(i,1) > str2.substr(i,1))
            return 1;
        else if(str1.substr(i,1) < str2.substr(i,1))
            return -1;
    }
    return 0;
}

ostream & operator <<(ostream & os,const bigInt & bigInt1){
    if(!bigInt1.flag)
        os << '-';
    os << bigInt1.value;
    return os;
}

istream & operator >>(istream & is,bigInt & bigInt1){
    string inputStr;
    is >> inputStr;
    bigInt1.value = inputStr;
    bigInt1.flag = true;
    return is;
}

/**
 *  字符串加法实现的关键是直接加减每一位字符，相加完后然后再处理进位。
 *  如'1'+'2'-'0' = '3'，通过减去一个字符0来抹掉ASCII码头，而'9'+'9'-'0' = 'B'，
 *  就相当于把和18以字符B的形式储存在当前位而暂时不需要进位。
 *  同理，char型数字 减去'0'便是int型数字，便于处理进位。
 *  虽然题目已经表明两个数均为正整数，但我还是考虑了有0的情况来着，以下同。
 *  @return
 */

bigInt bigInt::operator+(const bigInt & Num){
    bigInt result;
    string rightNum = Num.value;
    string leftNum = value;
    //使较大数在左
    if(compareSize(leftNum,rightNum) < 0){
        string tmp;
        tmp = leftNum;
        leftNum = rightNum;
        rightNum = tmp;
    }
    reverse(leftNum.begin(),leftNum.end());
    reverse(rightNum.begin(),rightNum.end());

    //逐位相加
    int i = 0;
    //ASCII加减法,可以暂时在每一位储存超过9的和，之后处理进位
    for ( ; i < leftNum.length() && i < rightNum.length(); ++ i)
        result.value.push_back(leftNum.at(i) + rightNum.at(i) - '0') ;
    if (i < leftNum.length())
        for (; i < leftNum.length(); ++ i)
            result.value.push_back(leftNum.at(i)) ;
    else
        for (; i < rightNum.length(); ++ i)
            result.value.push_back(rightNum.at(i)) ;
    //处理进位
    int carry = 0;
    for (int i = 0; i < result.value.length(); ++ i)
    {
        int newValue = result.value.at(i) - '0' + carry ;
        carry = newValue/ 10 ;
        result.value.at(i) = newValue - carry * 10 + '0' ;
    }
    if (carry)
        result.value.push_back(carry + '0') ;

    //结果格式整理
    reverse(result.value.begin(), result.value.end()) ;
    i = result.value.find_first_not_of(" 0") ;
    //npos是string_find函数找不到目标时的返回值，找不到说明结果完全由0和空格组成，即为0
    if (i == string :: npos)
    {
        result.value = "0" ;
        result.flag = true ;
        return result ;
    }
    //去掉前面的空白和0
    result.value = string(result.value.begin() + result.value.find_first_not_of(" 0"), result.value.end()) ;
    return result;
}

/**
 *  减法就是加法的逆运算，所以基于加法的重载逻辑进行减法的重载
 *  首先基于减数和被减数的大小关系判断结果的正负性，然后调换顺序使被减数大于减数
 *  每一位进行减法运算后ASCII码小于'0'的ASCII码即当前位结果小于零，从上一位借10加上得退位结果，上一位结果减1
 *  @return
 */

bigInt bigInt::operator-(const bigInt & Num){
    bigInt result;
    string rightNum = Num.value;
    string leftNum = value;
    //判断大小，确定结果符号，交换以保证绝对值较大的数在左（此处两个运算数都是非负数(flag == true)所以大数在左即可）
    //默认情况result已初始化为空字符串非负
    if(compareSize(leftNum,rightNum) < 0){
        string tmp;
        tmp = leftNum;
        leftNum = rightNum;
        rightNum = tmp;
        result.flag = false;
    }
    else if(compareSize(leftNum,rightNum) == 0){
        result.value = "0";
        return result;
    }

    reverse(leftNum.begin(),leftNum.end());
    reverse(rightNum.begin(),rightNum.end());
    //逐位相加
    int i = 0;
    //ASCII加减法,可以暂时在每一位储存超过9的和差，之后处理进位
    for ( ; i < leftNum.length() && i < rightNum.length(); ++ i)
        result.value.push_back(leftNum.at(i) - rightNum.at(i) + '0') ;
    //此处完全确定左数大于右数，若左数位数大于右数则继续打出长出部分
    if (i < leftNum.length())
        for (; i < leftNum.length(); ++ i)
            result.value.push_back(leftNum.at(i)) ;

    //处理退位
    int carry = 0;
    for (int i = 0; i < result.value.length(); ++ i)
    {
        int newValue = result.value.at(i) - '0' + carry ;
        //当前位值为0~9时不退位，-1~-9时退位
        carry = (newValue - 9)/ 10 ;
        result.value.at(i) = newValue - carry * 10 + '0' ;
    }

    //结果格式整理
    reverse(result.value.begin(), result.value.end()) ;
    i = result.value.find_first_not_of(" 0") ;
    //npos是string_find函数找不到目标时的返回值，找不到说明结果完全由0和空格组成，即为0
    if (i == string :: npos)
    {
        result.value = "0" ;
        result.flag = true ;
        return result ;
    }
    //去掉前面的空白和0
    result.value = string(result.value.begin() + result.value.find_first_not_of(" 0"), result.value.end()) ;
    return result;
}

/**
 * 乘法就是依照竖式计算原理。
 * @return
 */

bigInt bigInt::operator*(const bigInt & Num){
    bigInt result;
    string rightNum = Num.value;
    string leftNum = value;
    int l = leftNum.find_first_not_of(" 0") ;
    int r = rightNum.find_first_not_of(" 0") ;
    //若两个数有任意一个是0，则结果为0
    if (l == string :: npos || r == string :: npos){
        result.value = "0" ;
        return result ;
    }
    reverse(leftNum.begin(),leftNum.end());
    reverse(rightNum.begin(),rightNum.end());
    result.value.resize(leftNum.length()+rightNum.length(),'0');
    //逐位相乘，基于左数每一位进行先乘后加循环
    for (int i = 0; i < leftNum.length(); ++ i) {
        for (int j = 0; j < rightNum.length(); ++j) {
            int newValue = result.value.at(i + j) + (leftNum.at(i) - '0') * (rightNum.at(j) - '0') - '0';
            int carry = newValue / 10;
            result.value.at(i + j) = newValue % 10 + '0';
            //处理进位，防止溢出
            for (int k = i + j + 1; carry != 0 && k < result.value.length(); ++k) //处理进位
            {
                result.value.at(k - 1) = newValue % 10 + '0';
                newValue = result.value.at(k) + carry - '0';
                result.value.at(k) = newValue % 10 + '0';
                carry = newValue / 10;
            }
        }
    }
    reverse(result.value.begin(), result.value.end()) ;
    //去掉前面的空白和0
    result.value = string(result.value.begin() + result.value.find_first_not_of(" 0"), result.value.end()) ;
    return result;
}

/**
 * 除法的原理也是竖式计算，
 * 通过多次调用前面定义的大整数减法，实现“商 < 10”的的大整数除法，由此重复来实现大整数除法。
 * 每一次这样的除法，余数去掉头部可能存在的0，尾部补上大整数除法运算被除数（左输入数）的下一位，就是下一次除法运算的被除数 。
 * @return
 */

bigInt bigInt::operator/(const bigInt &Num) {
    bigInt result;
    string rightNum = Num.value;
    string leftNum = value;
    int l = leftNum.find_first_not_of(" 0") ;
    int r = rightNum.find_first_not_of(" 0") ;
    //若左数是0，则结果为0；右数是0，输入错误
    if ( r == string :: npos){
        result.value = "ERROR:Divided by 0" ;
        return result ;
    }
    else if (l == string::npos){
        result.value = "0" ;
        return result ;
    }
    leftNum = string(leftNum.begin() + leftNum.find_first_not_of(" 0"), leftNum.end());
    rightNum = string(rightNum.begin() + rightNum.find_first_not_of(" 0"), rightNum.end());
    if(leftNum == rightNum){
        result.value = "1";
        return result;
    }
    else if(compareSize(leftNum,rightNum) < 0){
        result.value = "0" ;
        return result ;
    }
    //以下只存在两个数均为正整数，且左数大于右数之情况。
    bigInt temp(leftNum.substr(0,rightNum.length())),divide(rightNum);
    for (int i = 0; i < (leftNum.length() - rightNum.length() + 1); ++i) {
        int pValue = 0;
        while ((temp - divide).flag){
            temp = temp - divide;
            pValue++;
        }
        if(pValue == 0 && i == 0){
            temp.value.push_back(leftNum.at(i+rightNum.length()));
            continue;
        }
        result.value.push_back(pValue + '0');
        if(i < leftNum.length() - rightNum.length())
            temp.value.push_back(leftNum.at(i+rightNum.length()));
    }
    return result;
}

int main() {
    bigInt a,b;
    char operatorX;
    cin >> a >> operatorX >> b;
    if(operatorX == '+')
        cout << a + b << endl;
    else if(operatorX == '-')
        cout << a - b << endl;
    else if(operatorX == '*')
        cout << a * b << endl;
    else if(operatorX == '/')
        cout << a / b << endl;
    return 0;
}
