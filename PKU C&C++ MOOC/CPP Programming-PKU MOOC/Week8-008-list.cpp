#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <set>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第8周测验(2019夏季)
 * 007:List
 *
 * 描述：
 * 写一个程序完成以下命令：
 * new id ——新建一个指定编号为id的序列(id<10000)
 * add id num——向编号为id的序列加入整数num
 * merge id1 id2——合并序列id1和id2中的数，并将id2清空
 * unique id——去掉序列id中重复的元素
 * out id ——从小到大输出编号为id的序列中的元素，以空格隔开
 *
 * 输入：
 * 第一行一个数n，表示有多少个命令(n<=200000)。以后n行每行一个命令。
 *
 * 输出：
 * 按题目要求输出。
 */
struct LIST{
    list<int> data;
};


int main(){
    vector<LIST> dict(10001);
    int in;
    cin >> in;
    while(in-- >= 0){
        string ins,line;
        int a,b;
        getline(cin,line);
        stringstream ss(line);
        ss >> ins;
        if(ins == "new"){
            ss >> a;

        }
        else if(ins == "add"){
            ss >> a >> b;
            dict[a].data.push_back(b);
        }
        else if(ins == "merge"){
            ss >> a >> b;
            dict[a].data.merge(dict[b].data);
        }
        else if(ins == "unique"){
            ss >> a;
            // 利用红黑树消除链表中的重复项
            set<int> shrink;
            for (auto it = dict[a].data.begin(); it != dict[a].data.end(); ++it) {
                shrink.insert(*it);
            }
            dict[a].data.clear();
            for (auto iter = shrink.begin(); iter != shrink.end(); ++iter) {
                dict[a].data.push_back(*iter);
            }
        }
        else if(ins == "out"){
            ss >> a;
            if(dict[a].data.size() > 1)
                dict[a].data.sort();
            for (auto it = dict[a].data.begin(); it != dict[a].data.end(); ++it) {
                if(it != dict[a].data.begin())
                    cout << ' ';
                cout << *it;
            }
            cout << endl;
        }
    }
    return 0;
}