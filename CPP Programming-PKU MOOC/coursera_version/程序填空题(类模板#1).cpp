#include <iostream>
using namespace std;

/**
 *
 * 描述
 * 实现一个三维数组模版CArray3D，可以用来生成元素为任意类型变量的三维数组，使得下面程序输出结果是： 
 * 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
 * 注意，只能写一个类模版，不能写多个。
 * 
 * #include <iostream>
 * using namespace std;
 * // 在此处补充你的代码
 * int main()
 * {
 *     CArray3D<int> a(3,4,5);
 *     int No = 0;
 *     for( int i = 0; i < 3; ++ i )
 *         for( int j = 0; j < 4; ++j )
 *             for( int k = 0; k < 5; ++k )
 *                 a[i][j][k] = No ++;
 *    for( int i = 0; i < 3; ++ i )
 *        for( int j = 0; j < 4; ++j )
 *             for( int k = 0; k < 5; ++k )
 *                 cout << a[i][j][k] << ",";
 * return 0;
 * }
 *  
 * 输入
 * 无
 *  
 * 输出
 * 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,
 * 
 * 提示
 * 类里面可以定义类，类模版里面也可以定义类模版。例如：
 * 
 * class A
 * {
 *     class B {
 * 
 *     };
 * };
 * 
 * template
 * class S
 * {
 *    T x;
 *     class K {
 *         T a;
 *     };
 * };
 */
// 在此处补充你的代码
template<class T1>
class CArray3D{
public:
    template <class T2>
    class CArray2D{
    public:
        template <class T3>
        class CArray{
        private:
            T3 *a;
        public:
            CArray(){a = nullptr;}
            //建立一个一维数组
            void set(int length){
                a = new T1[length];
            }
            ~CArray(){if(a) delete []a;}
            //超载括号
            T3 &operator[](int index){return a[index];}
        };
        CArray2D(){a2 = nullptr;}
        //建立一个2维数组，因为不会在外部直接调用所以不需要写实际的构造函数
        void set(int col,int length){
            a2 = new CArray<T2>[col];
            for (int i = 0; i < col; ++i) {
                a2[i].set(length);
            }
        }
        ~CArray2D(){if(a2) delete []a2;}
        //超载括号
        CArray<T2> &operator[](int index){
            return a2[index];
        }
        //因为内部类的定义位置所以私有变量需要放在后面定义
    private:
        CArray<T2> * a2;
    };
    CArray3D(){a3 = nullptr;}
    //可在外部直接使用的构造函数
    CArray3D(int row,int col,int length){
        a3 = new CArray2D<T1>[row];//构造三维数组类型的二维数组
        for (int i = 0; i < row; ++i) {
            //对每个默认构造为nullptr的二维数组指针利用set函数初始化一个二维数组
            a3[i].set(col,length);
        }
    }
    ~CArray3D(){if(a3) delete []a3;}
    CArray2D<T1> &operator[](int index){
        return a3[index];
    }
private:
    CArray2D<T1> *a3;
};


int main()
{
    CArray3D<int> a(3,4,5);
    int No = 0;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                a[i][j][k] = No ++;
    for( int i = 0; i < 3; ++ i )
        for( int j = 0; j < 4; ++j )
            for( int k = 0; k < 5; ++k )
                cout << a[i][j][k] << ",";
    return 0;
}
