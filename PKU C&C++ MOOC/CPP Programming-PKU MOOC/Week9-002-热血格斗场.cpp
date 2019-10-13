#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第9周测验(2019夏季)
 * 002:热血格斗场
 *
 * 描述：
 * 为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家热血格斗场。格斗场实行会员制，
 * 但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。
 * 我们假设格斗的实力可以用一个正整数表示，成为实力值。
 * 另外，每个人都有一个唯一的id，也是一个正整数。
 * 为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，
 * 如果有两个人的实力值与他差别相同，则他会选择比他弱的那个（显然，虐人必被虐好）。
 * 不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。
 * 现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。
 *
 * 输入：
 * 第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。
 * 以后n行每一行两个数，按照入会的时间给出会员的id和实力值。
 * 一开始，facer就算是会员，id为1，实力值1000000000。输入保证两人的实力值不同。
 *
 * 输出：
 * N行，每行两个数，为每场比赛双方的id，新手的id写在前面。
 */


int main(){
    map<int,int> member;
    member[1000000000] = 1;
    int n;
    cin >> n;
    int id,power;
    while(cin >> id >> power){
        int competID;
        // 获得比新人弱之会员的上界(该值亦是比新人略强一些的会员)
        auto compet1 = member.lower_bound(power);
        auto compet2 = compet1;
        if(compet1 != member.begin()){
            // 迭代器减小一个，指向比新人弱一点的会员
            compet1--;
            // 比较略弱于、略强于新人的两名会员，选差距最小者作为对手
            competID = ((power - compet1->first) <= (compet2->first - power))? compet1->second:compet2->second;
        }
        else{
            // 若所有会员都比新人强或一样强，选择最弱的一名会员
            competID = compet1->second;
        }
        cout << id  << ' ' << competID << endl;
        member[power] = id;
    }
    return 0;
}