#include <iostream>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第7周测验(2019夏季)
 * 007:排序，又见排序!
 *
 * 描述：
 * 自己编写一个能对任何类型的数组进行排序的mysort函数模版。只能写一个mysort模板，不能写mysort函数！
 *
 * 输入：
 * 无
 *
 * 输出：
 * 4,8,10,11,123,
 * 123,11,10,8,4,
 * 1.4,1.2,1.8,3.1,3.2,2.1,
 */
bool Greater2(int n1,int n2)
{
    return n1 > n2;
}
bool Greater1(int n1,int n2)
{
    return n1 < n2;
}
bool Greater3(double d1,double d2)
{
    return d1 < d2;
}

template <class T1,class T2>
void mysort(
// 在此处补充你的代码
T1* a,T1* a1,bool comp(T2 a,T2 b)
){
    // 简单的冒泡排序
    for (auto i = a; i < a1; ++i) {
        for (auto j = i; j < a1; ++j) {
            if(i==j&&i==a1-1)
                break;
            if(!comp(*i,*j)){
                T1 tmp = *i;
                *i = *j;
                *j = tmp;
            }
        }
    }
}
// 结束
#define NUM 5
int main()
{
    int an[NUM] = { 8,123,11,10,4 };
    mysort(an,an+NUM,Greater1); //从小到大排序
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ",";
    mysort(an,an+NUM,Greater2); //从大到小排序
    cout << endl;
    for( int i = 0;i < NUM; i ++ )
        cout << an[i] << ",";
    cout << endl;
    double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1};
    mysort(d+1,d+5,Greater3); //将数组从下标1到下标4从小到大排序
    for( int i = 0;i < 6; i ++ )
        cout << d[i] << ",";
    return 0;
}
