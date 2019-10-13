#include <iostream>
#include <map>
using namespace std;

/**
 * 集合加法
 * 描述
 * 给出2个正整数集合A = {pi | 1 <= i <= a}，B = {qj | 1 <= j <= b}和一个正整数s。
 * 问题是：使得pi + qj = s的不同的(i, j)对有多少个。
 *
 * 输入
 * 第1行是测试数据的组数n，后面跟着n组测试数据。
 *
 * 每组测试数据占5行，第1行是和s (1 <= s <= 10000)，第2行是一个正整数a (1 <= a <= 10000)，表示A中元素的数目。
 * 第3行是a个正整数，每个正整数不超过10000，表示A中的元素。第4行是一个正整数b (1 <= b <= 10000)，表示B中元素的数目。
 * 第5行是b个正整数，每个正整数不超过10000，表示B中的元素。
 * 注意：这里的集合和数学书上定义的集合有一点点区别——集合内可能包含相等的正整数。
 * 输出
 * n行，每行输出对应一个输入。输出应是一个非负整数。
 */

int main() {
    int n;
    cin >> n;
    while (--n >= 0){
        int s,a,b,count = 0;
        cin >> s >> a;
        //map<int,int> memList,pairList;
        int A[10000],B[10000];
        for (int i = 0; i < a; ++i)
            cin >> A[i];
        cin >> b;
        for (int i = 0; i < b; ++i)
            cin >> B[i];
        for (int i = 1; i <= a; ++i) {
            for (int j = 1; j <= b; ++j) {
                if(A[i - 1] + B[j - 1] != s)
                    continue;
                /**
                auto it1 = memList.find(A[i - 1]);
                if(it1 == memList.end()){
                    memList[A[i - 1]] = B[j - 1];
                    memList[B[j - 1]] = A[i - 1];
                }
                pairList[i] = j;
                */
                else
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
