#include <iostream>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;

/**
 *  PKU 程序设计与算法慕课（三） C++面向对象 第三周005
 *  005:魔兽世界之一：备战
 *  描述

 * 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
 * 红司令部，City 1，City 2，……，City n，蓝司令部
 * 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
 * 双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
 * 武士在刚降生的时候有一个生命值。
 * 在每个整点，双方的司令部中各有一个武士降生。
 * 红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
 * 蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
 * 制造武士需要生命元。制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
 * 如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。
 * 如果所有武士都不能制造了，则司令部停止制造武士。
 * 给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
 *
 * 一共有两种事件，其对应的输出样例如下：
 * 1) 武士降生
 * 输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
 * 表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。
 * （为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
 * 2) 司令部停止制造武士
 * 输出样例： 010 red headquarter stops making warriors
 * 表示在10点整，红方司令部停止制造武士
 *
 * 输出事件时：
 * 首先按时间顺序输出；
 * 同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。
 *
 * 输入：
 * 第一行是一个整数，代表测试数据组数。
 * 每组测试数据共两行。
 * 第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
 * 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。
 *
 * 输出:
 * 对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
 * 对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
 * 接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
 */
class unit;
// 司令部的定义
class hq{
private:
    int HP;
    unsigned iter,typecode;     //时间迭代器及单位类型迭代器
    bool trainning;             //标记位，表示仍可继续训练新单位
    string Faction;             //司令部所属派系的名字
    vector<string> trainOrder;  //本派系的训练顺序
    map<string,int> unitCount;  //本司令部已训练单位的数目
    vector<unit*> unitList;     //本司令部训练出的单位的指针列表
    void testMyHP(){
        //测试用函数
        cout << " Now " << Faction << " has " << HP << " HP." << endl;
    }
public:
    hq(int M,bool isRed);       //构造函数(初始生命值,是否红方)
    unit * train();             //训练一个新单位，加入unitList，打印训练信息，并返回其指针
    string getFaction();        //返回本司令部的派系
    int getNo();                //返回下一个训练中单位的编号(iter+1)
    int getUnitCost(int typecode);//按训练顺序和单位迭代器返回单位的训练消耗
};
class unit{             //所有单位的基类
protected:
    string Faction;     //单位的派系
    int strength;       //单位的血量
    int No;             //单位的序号
public:
    int getStrength(){
        return strength;
    }
    int getUnitNo(){
        return No;
    }
};
class dragon: public unit{
private:
    const string type = "dragon";       //该类型单位的名字
public:
    static int maxStrength;             //该类型单位的最大血量
    dragon(){}
    dragon(hq* masterHQ){               //利用所属司令部的this指针初始化单位
        Faction = masterHQ->getFaction();
        No = masterHQ->getNo();
        strength = maxStrength;         //刚训练完时单位血量等于最大血量
    }
    static void changeMaxStr(int h){
        maxStrength = h;
    }
};
class ninja: public unit{
private:
    const string type = "ninja";
public:
    static int maxStrength;
    ninja(){}
    ninja(hq* masterHQ){
        Faction = masterHQ->getFaction();
        No = masterHQ->getNo();
        strength = maxStrength;
    }
    static void changeMaxStr(int h){
        maxStrength = h;
    }
};
class iceman: public unit{
private:
    const string type = "iceman";
public:
    static int maxStrength;
    iceman(){}
    iceman(hq* masterHQ){
        Faction = masterHQ->getFaction();
        No = masterHQ->getNo();
        strength = maxStrength;
    }
    static void changeMaxStr(int h){
        maxStrength = h;
    }
};
class lion: public unit{
private:
    const string type = "lion";
public:
    static int maxStrength;
    lion(){}
    lion(hq* masterHQ){
        Faction = masterHQ->getFaction();
        No = masterHQ->getNo();
        strength = maxStrength;
    }
    static void changeMaxStr(int h){
        maxStrength = h;
    }
};
class wolf: public unit{
private:
    const string type = "wolf";
public:
    static int maxStrength;
    wolf(){}
    wolf(hq* masterHQ){
        Faction = masterHQ->getFaction();
        No = masterHQ->getNo();
        strength = maxStrength;
    }
    static void changeMaxStr(int h){
        maxStrength = h;
    }
};

hq::hq(int M,bool isRed){
        HP = M;
        iter = 0;           //初始化时迭代器置零
        typecode = 0;
        trainning = true;   //状态为可训练
        if(isRed){          //按派系初始化训练顺序
            Faction = "red";
            trainOrder = {"iceman","lion","wolf","ninja","dragon"};
        }
        else{
            Faction = "blue";
            trainOrder = {"lion","dragon","ninja","iceman","wolf"};
        }
        for (int i = 0; i < 5; ++i) {
            unitCount[trainOrder[i]] = 0;   //已训练单位数目置零
        }
}
int hq::getUnitCost(int typeC) {
    typeC = typeC%5;
    if(trainOrder[typeC] == "dragon")
        return dragon::maxStrength;
    else if(trainOrder[typeC] == "ninja")
        return ninja::maxStrength;
    else if(trainOrder[typeC] == "iceman")
        return iceman::maxStrength;
    else if(trainOrder[typeC] == "lion")
        return lion::maxStrength;
    else if(trainOrder[typeC] == "wolf")
        return wolf::maxStrength;
    else
        return 999999;  //防止意外情况
}

unit * hq::train(){
    if(!trainning)      //不可训练状态时直接返回空指针
        return nullptr;
    unit * newUnit;     //待训练单位
    bool ableToTrain = false;   //以下检查剩余血量是否可以继续训练单位
    for(int i = 0;i < 5;i++){
        typecode = typecode%5;
        //可以训练该单位则停止轮询
        if(HP - getUnitCost(typecode) >= 0){
            ableToTrain = true;
            break;
        }
        else
            typecode++;
    }
    if(!ableToTrain){
        //剩余司令部血量无法训练任一新单位
        trainning = false;      //可训练标记改为“不可训练”
        typecode = 0;
        printf("%03d ",iter); //打印时间
        cout << Faction << " headquarter stops making warriors" << endl; //输出停止训练信息
        return nullptr;     //不可训练，返回空指针
    }
    string myType = trainOrder[typecode]; //训练一个新单位
    if(myType == "dragon")
        newUnit = new dragon(this);
    else if(myType == "ninja")
        newUnit = new ninja(this);
    else if(myType == "iceman")
        newUnit = new iceman(this);
    else if(myType == "lion")
        newUnit = new lion(this);
    else if(myType == "wolf")
        newUnit = new wolf(this);
    else{
        cout << "uninitalized type" << endl;    //防止意外情况
        return nullptr;
    }
    HP -= newUnit->getStrength();   //扣除新训练单位的消耗
    unitCount[myType]++;            //新单位计入司令部
    unitList.push_back(newUnit);    //新单位归入司令部待命单位的序列
    printf("%03d ",iter);           //打印训练成功信息
    cout << Faction << ' ' << myType << ' ' << newUnit->getUnitNo()
            << " born with strength " << newUnit->getStrength() << ','
            << unitCount[myType] << ' ' << myType << " in " << Faction << " headquarter" << endl;
    iter++;     //时间进一
    typecode++;     //准备按顺序训练下一种单位
    return newUnit;
}
string hq::getFaction(){
        return Faction;
}
int hq::getNo() {
    // iter既用来计时又用来单位的计数，计数时加1；
    return iter + 1;
}
//初始化单位最大HP这一静态变量
int dragon::maxStrength = 0,ninja::maxStrength = 0,iceman::maxStrength = 0,lion::maxStrength = 0;
int wolf::maxStrength = 0;

int main(){
    int caseNum,u = 0;
    cin >> caseNum;
    while(++u <= caseNum){
        int M;
        vector<int> primaryHP(5);
        cin >> M;
        for (int i = 0; i < 5; ++i) {
            cin >> primaryHP[i];
        }
        //更新各类单位最大HP
        dragon::changeMaxStr(primaryHP[0]);
        ninja::changeMaxStr(primaryHP[1]);
        iceman::changeMaxStr(primaryHP[2]);
        lion::changeMaxStr(primaryHP[3]);
        wolf::changeMaxStr(primaryHP[4]);
        hq red(M,true);
        hq blue(M,false);
        cout << "Case:" << u << endl;
        while(true){
            unit * a = red.train();
            unit * b = blue.train();
            if( a == nullptr && b == nullptr)
                break;
        }
    }
    return 0;
}