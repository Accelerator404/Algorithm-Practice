#include <iostream>
#include <cstdlib>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第五周001
 * 001:全面的MyString
 * 描述
 * 程序填空，输出指定结果
 *
 * 输入：
 * 无
 *
 * 输出:
 * (略)
 */


int strlen(const char * s)
{	int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;

}
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i) {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}
class MyString
{
// 在此处补充你的代码
private:
    char *p;
    int len;
public:
    MyString(){
        p = new char[1];
        strcpy(p,"");
        len = 0;
    }
    MyString(const MyString & str){
        len = strlen(str.p);
        p = new char[len+1];
        strcpy(p,str.p);
    }
    MyString(const char str[]){
        // 此处不必写用string初始化的方法
        len = strlen(str);
        p = new char[len+1];
        strcpy(p,str);
    }
    friend ostream & operator<<(ostream & os,const MyString & str){
        os << str.p;
        return os;
    }
    MyString & operator+=(const MyString & b){
        // 注意已经分配了空间的原指针不能直接用strcat
        char * p2;
        int len2 = len + b.len;
        p2 = new char[len2+1];
        strcpy(p2,p);
        strcpy(p2 + len,b.p);
        len = len2;
        delete p;
        p = p2;
        return *this;
    }
    friend MyString operator+(const MyString & a,const MyString & b){
        MyString c;
        c += a;
        c += b;
        return c;
    }
    friend bool operator<(const MyString & a, const MyString & b){
        if(strcmp(b.p,a.p) == 1)
            return 1;
        return 0;
    }
    friend bool operator>(const MyString & a, const MyString & b){
        if(strcmp(a.p,b.p) == 1)
            return 1;
        return 0;
    }
    friend bool operator==(const MyString & a, const MyString & b){
        if(strcmp(a.p,b.p) == 0)
            return 1;
        return 0;
    }
    MyString operator()(int a,int l){
        MyString substr;
        if(a < 0 || l <= 0)
            return substr;
        substr = new char[l+1];
        int j = 0;
        for (int i = a; i < a+l && i < len; ++i,++j) {
            substr.p[j] = p[i];
        }
        // 参照strcpy写法，最后留一个终止符，这也是分配char数组的长度为len+1的原因
        substr.p[j] = 0;
        return substr;
    }
    char &operator[](int i){
        if(i >= len)
            return p[len];
        return p[i];
    }
// 结束
};


int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
        return -1;
    else if( *s1 == *s2)
        return 0;
    else if( *s1 > *s2 )
        return 1;
}
int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0;i < 4;i ++ )
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}