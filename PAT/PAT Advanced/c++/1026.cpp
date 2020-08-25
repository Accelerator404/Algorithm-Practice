#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//PAT Advanced Level 1026 Table Tennis

struct person {
    int arrive, start, time;
    bool vip;
};

struct tableNode {
    int end = 8 * 3600, num;
    bool vip;
};

bool compare1(person a, person b) {
    return a.arrive < b.arrive;
}
bool compare2(person a, person b) {
    return a.start < b.start;
}

void allocTable(int personID, int tableID,vector<person> & player,vector<tableNode> & table) {
    //桌子空闲前到达，则开始游戏时间是桌子空闲时间，否则开始游戏时间就是该人到达时间
    if(player[personID].arrive <= table[tableID].end)
        player[personID].start = table[tableID].end;
    else
        player[personID].start = player[personID].arrive;
    //更新桌子空闲时间及桌子使用计数
    table[tableID].end = player[personID].start + player[personID].time;
    table[tableID].num++;
}
int findNextVIP(int vipID,vector<person> & player) {
    vipID++;
    while(vipID < player.size() && !player[vipID].vip)
        vipID++;
    return vipID;
}
int main() {
    int n, k, m, viptable;
    vector<person> player;
    vector<tableNode> table;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int hh, mm, ss, temptime, flag;
        person inputP;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &temptime, &flag);
        inputP.arrive = hh * 3600 + mm * 60 + ss;
        //默认开始游玩时间为21点，便于排除等到21点还玩不了的情况
        inputP.start = 21 * 3600;
        //晚于21点到达的人不计入
        if(inputP.arrive >= 21 * 3600)
            continue;
        //压缩游玩时间到2小时
        inputP.time = temptime <= 120 ? temptime * 60 : 7200;
        inputP.vip = ((flag == 1) ? true : false);
        player.push_back(inputP);
    }
    scanf("%d%d", &k, &m);
    table.resize(k + 1);
    for(int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    //按到达时间排序
    sort(player.begin(), player.end(), compare1);
    int i = 0, vipID = -1;
    //找到第一位VIP玩家
    vipID = findNextVIP(vipID,player);
    //逻辑：对队列中每一位选手找到空闲最早的桌子，是VIP桌则分配给下一位VIP（没有则给普通选手）
    //      如果是普通桌，普通选手直接分配，VIP选手则需要先寻找此时有没有同样空闲的VIP桌，没有空VIP桌再分配这张普通桌子
    while(i < player.size()) {
        int index = -1, minendtime = 999999999;
        //找到结束时间最早且序号最小的桌子
        for(int j = 1; j <= k; j++) {
            if(table[j].end < minendtime) {
                minendtime = table[j].end;
                index = j;
            }
        }
        //所有桌子结束时间都在21点以后则跳出
        if(table[index].end >= 21 * 3600)
            break;
        //之前已将该位VIP优先分配桌子，迭代到下一位
        if(player[i].vip && i < vipID) {
            i++;
            continue;
        }
        //等待时间最短的桌子是VIP桌
        if(table[index].vip) {
            if(player[i].vip) {
                allocTable(i, index,player,table);
                //迭代VIP与用户队列
                if(vipID == i)
                    vipID = findNextVIP(vipID,player);
                i++;
            } else {
                //优先分配VIP
                if(vipID < player.size() && player[vipID].arrive <= table[index].end) {
                    allocTable(vipID, index,player,table);
                    vipID = findNextVIP(vipID,player);
                } else {
                    allocTable(i, index,player,table);
                    i++;
                }
            }
        } else {
            if(!player[i].vip) {
                allocTable(i, index,player,table);
                i++;
            } else {
                int vipindex = -1, minvipendtime = 999999999;
                //找到空闲最早的VIP桌
                for(int j = 1; j <= k; j++) {
                    if(table[j].vip && table[j].end < minvipendtime) {
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                //如果该VIP桌空闲，分配给这位选手
                if(vipindex != -1 && player[i].arrive >= table[vipindex].end)
                    allocTable(i, vipindex,player,table);
                //否则分配该普通桌
                else
                    allocTable(i, index,player,table);
                if(vipID == i) vipID = findNextVIP(vipID,player);
                i++;
            }
        }
    }
    //按开始游玩时间重新排序
    sort(player.begin(), player.end(), compare2);
    for(i = 0; i < player.size() && player[i].start < 21 * 3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive / 3600, player[i].arrive % 3600 / 60, player[i].arrive % 60);
        printf("%02d:%02d:%02d ", player[i].start / 3600, player[i].start % 3600 / 60, player[i].start % 60);
        printf("%.0f\n", round((player[i].start - player[i].arrive) / 60.0));
    }
    for(int i = 1; i <= k; i++) {
        if(i != 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}
