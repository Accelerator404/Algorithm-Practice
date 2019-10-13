#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>

using namespace std;

/*
 * PKU 程序设计与算法慕课（三） C++面向对象 期末考试
 * 013:编程填空：三生三世
 *
 * 描述
 * 近年来，国内电视剧吸引了越来越多的关注；有的以当红的演员阵容而吸引观众，
 * 比如《三生三世十里桃花》（Life After Life，Blooms Over Blooms）；
 * 有的以贴近时代的剧情而备受关注，比如《人民的名义》（In the Name of People）；
 * 有的则以精湛的演技赢得观众的喜欢，比如《大明王朝：1566》（Ming Dynasty: 1566）。
 * 你的任务是根据电视剧的不同属性（演员、剧情和演技）对电视剧进行排行。
 *
 * 输入
 * 首先输入整数n，代表电视剧的个数。接下来，对于每个电视剧有两行输入：
 * 第一行一个字符串（可能含有空格，逗号，冒号等标点符号）作为电视剧的名字；
 * 第二行包括三个整数，分别为演员阵容、剧情和演技的评分。
 *
 * 输出
 * 输出包括三行，分别为电视剧按演员阵容、剧情和演技的排行榜（评分由高到低），电视剧名字之间以分号隔开
 */
class TV_Drama {
public:
    char name[100];
    int actor;
    int story;
    int acting_skill;

// 在此处补充你的代码
    TV_Drama(char _name[], int _actor, int _story, int _acting_skill) {
        strcpy(name, _name);
        actor = _actor;
        story = _story;
        acting_skill = _acting_skill;
    }

    friend bool operator<(TV_Drama &a, TV_Drama &b) {
        return a.actor > b.actor;
    }
};

bool comparator_1(TV_Drama &a, TV_Drama &b) {
    return a.story > b.story;
}

class comparator_2 {
public:
    bool operator()(TV_Drama &a, TV_Drama &b) {
        return a.acting_skill > b.acting_skill;
    }
};

void Printer(TV_Drama & target) {
    cout << target.name << ';';
}
// 结束
int main() {
    list<TV_Drama> lst;
    int n;

    cin >> n;
    char _name[100];
    int _actor, _story, _acting_skill;
    for (int i = 0; i < n; i++) {
        cin.ignore();
        cin.getline(_name, 100);
        cin >> _actor >> _story >> _acting_skill;
        lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
    }

    lst.sort();
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    lst.sort(comparator_1);
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    lst.sort(comparator_2());
    for_each(lst.begin(), lst.end(), Printer);
    cout << endl;

    return 0;
}