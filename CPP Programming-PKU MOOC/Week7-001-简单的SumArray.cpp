#include <iostream>
#include <string>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第7周测验(2019夏季)
 * 001:简单的SumArray
 *
 * 描述：
 * 填写模板 PrintArray,使得程序输出结果是： TomJackMaryJohn 10 不得编写SumArray函数
 *
 * 输入：
 * 无
 *
 * 输出:
 * TomJackMaryJohn
 * 10
 */
template <class T>
T SumArray(
// 在此处补充你的代码
    T* array,T* end)
    {
    T sum;
    T* p = array;
    while (p!=end){
        if(p == array)
            sum = *array;
        else
            sum += *p;
        p++;
    }
    return sum;
// 结束
}
int main() {
    string array[4] = { "Tom","Jack","Mary","John"};
    cout << SumArray(array,array+4) << endl;
    int a[4] = { 1, 2, 3, 4};  //提示：1+2+3+4 = 10
    cout << SumArray(a,a+4) << endl;
    return 0;
}