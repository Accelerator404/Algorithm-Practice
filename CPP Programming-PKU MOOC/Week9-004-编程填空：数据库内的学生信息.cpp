#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第9周测验(2019夏季)
 * 004:编程填空：数据库内的学生信息
 *
 * 描述：
 * 程序填空，使得下面的程序,先输出
 * (Tom,80),(Tom,70),(Jone,90),(Jack,70),(Alice,100),
 * (Tom,78),(Tom,78),(Jone,90),(Jack,70),(Alice,100),
 * (70,Jack),(70,Tom),(80,Tom),(90,Jone),(100,Alice),
 * (70,Error),(70,Error),(80,Tom),(90,Jone),(100,Alice),
 * ******
 *
 * 然后，再根据输入数据按要求产生输出数据
 *
 * 输入：
 * 输入数据的每一行，格式为以下之一：
 * A name score
 * Q name score
 *
 * name是个不带个空格的字符串，长度小于 20
 * score是个整数，能用int表示
 * A name score 表示往数据库中新增一个姓名为name的学生，其分数为score。
 * 开始时数据库中一个学生也没有。
 * Q name 表示在数据库中查询姓名为name的学生的分数
 * 数据保证学生不重名。
 * 输入数据少于200,000行。
 *
 * 输出：
 * 对于每个查询，输出学生的分数。如果查不到，则输出 "Not Found"
 */
// 在此处补充你的代码
// 就是重新包装一下STL::multimap，参考stl头文件写就行
template <class KEY,class VAL,class CMP = std::greater<KEY> >
class MyMultimap{
public:
    multimap<KEY,VAL,CMP> data;
    // 定义迭代器，前面需要加一个typename
    typedef typename multimap<KEY,VAL,CMP>::iterator _iter;
    typedef _iter iterator;
    _iter insert(pair<KEY,VAL> a){
        return data.insert(a);
    }
    _iter begin(){
        return data.begin();
    }
    _iter end(){
        return data.end();
    }
    _iter find(KEY t){
        return data.find(t);
    }
    void Set(KEY k,VAL v){
        // 没有key为输入值时，自然不需要重新赋值
        if(data.find(k) == data.end())
            return;
        _iter left = data.lower_bound(k);
        _iter right = data.upper_bound(k);
        for (auto iter = left; iter != right ; ++iter) {
            iter->second = v;
        }
    }
    void clear(){
        data.clear();
    };
    template <class _k,class _val>
    friend ostream &operator<<(ostream& os,const pair<_k,_val>& a);
};
// 这个模板子函数要在类外完成定义
template<class T1,class T2>
ostream & operator<< (ostream& os,const pair<T1,T2> & a){
    os << '(' << a.first << ',' << a.second << ")";
    return os;
}
// 结束
struct Student
{
    string name;
    int score;
};
template <class T>
void Print(T first,T last) {
    for(;first!= last; ++ first)
        cout << * first << ",";
    cout << endl;
}
int main()
{

    Student s[] = { {"Tom",80},{"Jack",70},
                    {"Jone",90},{"Tom",70},{"Alice",100} };

    MyMultimap<string,int> mp;
    for(int i = 0; i<5; ++ i)
        mp.insert(make_pair(s[i].name,s[i].score));
    Print(mp.begin(),mp.end()); //按姓名从大到小输出

    mp.Set("Tom",78); //把所有名为"Tom"的学生的成绩都设置为78
    Print(mp.begin(),mp.end());



    MyMultimap<int,string,less<int> > mp2;
    for(int i = 0; i<5; ++ i)
        mp2.insert(make_pair(s[i].score,s[i].name));

    Print(mp2.begin(),mp2.end()); //按成绩从小到大输出
    mp2.Set(70,"Error");          //把所有成绩为70的学生，名字都改为"Error"
    Print(mp2.begin(),mp2.end());
    cout << "******" << endl;

    mp.clear();

    string name;
    string cmd;
    int score;
    while(cin >> cmd ) {
        if( cmd == "A") {
            cin >> name >> score;
            if(mp.find(name) != mp.end() ) {
                cout << "erroe" << endl;
            }
            mp.insert(make_pair(name,score));
        }
        else if(cmd == "Q") {
            cin >> name;
            MyMultimap<string,int>::iterator p = mp.find(name);
            if( p!= mp.end()) {
                cout << p->second << endl;
            }
            else {
                cout << "Not Found" << endl;
            }
        }
    }
    return 0;
}