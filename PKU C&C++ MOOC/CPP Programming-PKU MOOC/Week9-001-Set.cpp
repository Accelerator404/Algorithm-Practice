#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第9周测验(2019夏季)
 * 001:Set
 *
 * 描述：
 * 现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
 * add x 把x加入集合
 * del x 把集合中所有与x相等的元素删除
 * ask x 对集合中元素x的情况询问
 * 对每种操作，我们要求进行如下输出。
 * add 输出操作后集合中x的个数
 * del 输出操作前集合中x的个数
 * ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。
 *
 * 输入：
 * 第一行是一个整数n，表示命令数。0<=n<=100000。
 * 后面n行命令，如Description中所述。
 *
 * 输出：
 * 共n行，每行按要求输出。
 *
 * 提示:
 * Please use STL’s set and multiset to finish the task
 */

typedef multiset<int> setm;

int main(){
    int n;
    cin >> n;
    setm s;
    set<int> log;
    while (n-- > 0){
        string ins;
        int x;
        cin >> ins >> x;
        if(ins == "add"){
            s.insert(x);
            log.insert(x);
            cout << s.count(x) << endl;
        }
        else if(ins == "del"){
            cout << s.count(x) << endl;
            while (s.find(x) != s.end()){
                s.erase(s.find(x));
            }
        }
        else if(ins == "ask"){
            int c = s.count(x);
            cout << (log.find(x)!=log.end()?1:0) << ' ' << c << endl;
        }
    }
    return 0;
}