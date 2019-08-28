#include <iostream>
#include <string>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第7周测验(2019夏季)
 * 005:山寨版istream_iterator
 * 
 * 描述：
 * 模仿C++标准模板库istream_iterator用法，实现CMyistream_iterator使得程序按要求输出
 *
 * 输入
 * 第一行是整数t，表示有t组数据
 * 每组数据一行，三个整数加两个字符串。字符串是不含空格的
 *
 * 输出
 * 对每组数据，输出二行 
 * 在第一行输出第一个数
 * 第二行原样输出输入的内容
 */

template <class T>
class CMyistream_iterator
{
// 在此补充你的代码
private:
    istream* a;
    T* p;
public:
    // 绑定输入装置，从输入流读入第一个输入值
    CMyistream_iterator<T>(istream & is){
        p = new T[5];
        a = &is;
        *a >> *p;
    }
    // 重载<<
    ostream&operator<<(ostream & os){
        os << *p;
        return os;
    }
    // 重载*，实现访问迭代器指向的数据
    friend T operator*(CMyistream_iterator<T> b){
        return *(b.p);
    }
    // 重载++，实现迭代器自增（参数中的int为重载后自增时的占位符）
    friend CMyistream_iterator operator++(CMyistream_iterator<T> &b,int u){
        b.p++;
        // 从流中读入下一个数值
        *b.a >> *b.p;
        return b;
    }
// 结束
};



int main()  
{ 
	int t;
	cin >> t;
	while( t -- ) {
		 CMyistream_iterator<int> inputInt(cin);
		 int n1,n2,n3;
		 n1 = * inputInt; //读入 n1
		 int tmp = * inputInt;
		 cout << tmp << endl;
		 inputInt ++;   
		 n2 = * inputInt; //读入 n2
		 inputInt ++;
		 n3 = * inputInt; //读入 n3
		 cout << n1 << " " << n2<< " " << n3 << " ";
		 CMyistream_iterator<string> inputStr(cin);
		 string s1,s2;
		 s1 = * inputStr;
		 inputStr ++;
		 s2 = * inputStr;
		 cout << s1 << " " << s2 << endl;
	}
	 return 0;  
}
