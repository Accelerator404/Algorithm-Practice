#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/**
 * PKU 程序设计与算法慕课（三） 第9周测验(2019夏季)
 * 003:冷血格斗场
 *
 * 描述：
 * 为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。
 * 格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。
 * 我们假设格斗的实力可以用一个正整数表示，成为实力值，两人的实力值可以相同。
 * 另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，
 * 即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。
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
    multimap<int,int> member;
    map<int,int> minIDs;
    member.insert(pair<int,int>(1000000000,1));
    minIDs[1000000000] = 1;
    int n;
    cin >> n;
    int id,power;
    while(cin >> id >> power){
        // 查询同样实力之会员
        int competID;
        auto pivot1 = member.find(power);
        auto lb = member.begin();
        auto ub = member.end();
        if(pivot1 != member.end()){
            competID = minIDs[power];
        }
        else{
            pivot1 = member.lower_bound(power);
            // 如果所有会员都比新人强
            if(pivot1 == member.begin()){
                competID = minIDs[member.begin()->first];
            }
            // 如果所有会员都比新人弱
            else if(pivot1 == member.end()){
                competID = minIDs[(--pivot1)->first];
            }
            else{
                int power1 = pivot1->first;
                int power2 = (--pivot1)->first;
                int diff1 = abs(power - power1);
                int diff2 = abs(power - power2);
                // 若强于/弱于新人的会员实力差距相当，从二类人中选id最小者
                if(diff1 == diff2){
                    competID = min(minIDs[power1],minIDs[power2]);
                }
                else{
                    competID = diff1 < diff2 ? minIDs[power1] : minIDs[power2];
                }
            }
        }
        cout << id  << ' ' << competID << endl;
        member.insert(pair<int,int>(power,id));
        if(minIDs.find(power) == minIDs.end() || minIDs[power] > id)
            minIDs[power] = id;
    }
    return 0;
}