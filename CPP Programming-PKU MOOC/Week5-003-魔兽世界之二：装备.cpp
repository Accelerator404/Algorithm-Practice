#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
#include <cstdio>
#include <vector>
using namespace std;

/**
 * PKU 程序设计与算法慕课（三） C++面向对象 第五周003
 * 003:魔兽世界之二：装备
 *
 * 描述
 * 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
 * 红司令部，City 1，City 2，……，City n，蓝司令部
 * 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。
 * 每种武士都有编号、生命值这两种属性。
 * 有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
 * 双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
 *
 * 不同的武士有不同的特点。
 * dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
 * dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
 * ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
 * iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
 * lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
 * wolf没特点。
 * 请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，
 * 武士手中的武器随着使用攻击力也会发生变化。
 *
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
 * 如果造出的是dragon，那么还要输出一行，例：
 * It has a arrow,and it's morale is 23.34
 * 表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
 * 如果造出的是ninja，那么还要输出一行，例：
 * It has a bomb and a arrow
 * 表示该ninja降生时得到了bomb和arrow。
 * 如果造出的是iceman，那么还要输出一行，例：
 * It has a sword
 * 表示该iceman降生时得到了sword。
 * 如果造出的是lion，那么还要输出一行，例：
 * It's loyalty is 24
 * 表示该lion降生时的忠诚度是24。
 *
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
map<string,int> maxStrength;
class weapon{
protected:
    string name;
public:
    weapon():name(){}
    weapon(int no){
        no = no%3;
        if(no == 0)
            name = "sword";
        else if(no == 1)
            name = "bomb";
        else if(no == 2)
            name = "arrow";
    }
    string getName(){
        return name;
    }
};
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
    int getHP(){
        return HP;
    }
};
class unit{             //所有单位的基类
protected:
    string Faction;             //单位的派系
    int strength;               //单位的血量
    int No;                     //单位的序号
    string type;                //单位的类型
    int weaponSlotCount;        //武器槽数目
    vector<weapon> weaponSlot;  //武器槽
public:
    unit(){}
    unit(hq* masterHQ){
        Faction = masterHQ->getFaction(); //利用所属司令部的this指针初始化单位
        No = masterHQ->getNo();
        weaponSlotCount = 0;
    }
    int getStrength(){
        return strength;
    }
    int getUnitNo(){
        return No;
    }
    string getUnitType(){
        return type;
    }
    string getWeaponInfo(){
        if(weaponSlotCount == 0)
            return "It does not has weapon";
        else if(weaponSlotCount > 0){
            string output = "It has ";
            output += "a " + weaponSlot[0].getName();
            int next = 1;
            while (next < weaponSlotCount - 1){
                output += ",a " + weaponSlot[next].getName();
                next++;
            }
            if(weaponSlotCount > 1)
                output += " and a " + weaponSlot[next].getName();
            return output;
        } else
            return "";
    }
    virtual string getSpecialStatus() = 0;
};
class dragon: public unit{
private:
    float morale;
public:
    dragon(hq* masterHQ):unit(masterHQ){    //调用基类的构造函数
        type = "dragon";
        strength = maxStrength[type];
        weaponSlotCount = 1;
        weaponSlot.resize(1);
        weaponSlot[0] = weapon(No%3);
        morale = (float)(masterHQ->getHP() - strength)/maxStrength[type];
    }
    string getSpecialStatus(){
        string output = getWeaponInfo();
        std::stringstream ss;
        ss << std::setprecision(2) << fixed << morale;
        output += ",and it's morale is " + ss.str();
        return output;
    }
};
class ninja: public unit{
public:
    ninja(hq* masterHQ):unit(masterHQ){
        type = "ninja";
        strength = maxStrength[type];
        weaponSlotCount = 2;
        weaponSlot.resize(2);
        weaponSlot[0] = weapon(No%3);
        weaponSlot[1] = weapon((No+1)%3);
    }
    string getSpecialStatus(){
        return getWeaponInfo();
    }
};
class iceman: public unit{
public:
    iceman(hq* masterHQ):unit(masterHQ){
        type = "iceman";
        strength = maxStrength[type];
        weaponSlotCount = 1;
        weaponSlot.resize(1);
        weaponSlot[0] = weapon(No%3);
    }
    string getSpecialStatus(){
        return getWeaponInfo();
    }
};
class lion: public unit{
private:
    int loyalty;
public:
    lion(hq* masterHQ):unit(masterHQ){
        type = "lion";
        strength = maxStrength[type];
        loyalty = masterHQ->getHP() - strength;
    }
    string getSpecialStatus(){
        return "It's loyalty is " + to_string(loyalty);
    }
};
class wolf: public unit{
public:
    wolf(hq* masterHQ):unit(masterHQ){
        type = "wolf";
        strength = maxStrength[type];
    }
    string getSpecialStatus(){
        return "";
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
    return maxStrength[trainOrder[typeC]];
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
    string SpecialStat;     //输出特殊属性
    if(myType == "dragon"){
        newUnit = new dragon(this);
        SpecialStat = ((dragon*)newUnit)->getSpecialStatus();
    }
    else if(myType == "ninja"){
        newUnit = new ninja(this);
        SpecialStat = ((ninja*)newUnit)->getSpecialStatus();
    }
    else if(myType == "iceman"){
        newUnit = new iceman(this);
        SpecialStat = ((iceman*)newUnit)->getSpecialStatus();
    }
    else if(myType == "lion"){
        newUnit = new lion(this);
        SpecialStat = ((lion*)newUnit)->getSpecialStatus();
    }
    else if(myType == "wolf"){
        newUnit = new wolf(this);
        SpecialStat = ((wolf*)newUnit)->getSpecialStatus();
    }
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
    // 输出特殊属性
    if(SpecialStat.length() > 1)cout << SpecialStat << endl;
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
        maxStrength["dragon"] = primaryHP[0];
        maxStrength["ninja"] = primaryHP[1];
        maxStrength["iceman"] = primaryHP[2];
        maxStrength["lion"] = primaryHP[3];
        maxStrength["wolf"] = primaryHP[4];
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