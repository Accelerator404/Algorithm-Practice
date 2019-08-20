#include <iostream>
#include <iomanip>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define inf 1145141919
/**
 * PKU 程序设计与算法慕课（三） 魔兽世界3
 *
 */
class unit;
map<string,int> maxStrength;
// 司令部与城市的定义
class city{
protected:
    bool isHQ;
    unsigned No;
    unit * warriorRed;
    unit * warriorBlue;
    city * nextCity;
    city * prevCity;
public:
    city(){}
    city(bool HQ,int NoOfCity){
        HQ = isHQ;
        No = NoOfCity;
    }
    city(bool HQ,bool isRed,int N){
        if(HQ&&isRed){
            isHQ = true;
            No = 0;
        }
        else if(HQ && isRed == false){
            isHQ = true;
            No = N + 1;
        }
        else{
            isHQ = false;
        }
    }
    void linkCity(city * prev,city * next){
        nextCity = next;
        prevCity = prev;
    }
    void blueUnitMoveForward(){
        // 为了避免指针位被占用，从city0~cityN+1的顺序调用此函数
        if(warriorBlue && prevCity){
            prevCity->warriorBlue = warriorBlue;
            warriorBlue = nullptr;
        }
    }
    void redUnitMoveForward(){
        // 同理，从cityN+1~city0调用此函数
        if(warriorRed){
            nextCity->warriorRed = warriorRed;
            warriorRed = nullptr;
        }
    }
    void battle(){
        if(warriorRed && warriorBlue){
            bool isOddNoCity = (No%2 == 1);
            if(isOddNoCity){

            }

        }
    }
};
class hq:public city{
private:
    int HP;
    unsigned iter,typecode;     //时间迭代器及单位类型迭代器
    bool trainning;             //标记位，表示仍可继续训练新单位
    string Faction;             //司令部所属派系的名字
    vector<string> trainOrder;  //本派系的训练顺序
    map<string,int> unitCount;  //本司令部已训练单位的数目
    void testMyHP(){
        //测试用函数
        cout << " Now " << Faction << " has " << HP << " HP." << endl;
    }
public:
    hq(int M,bool isRed);       //构造函数(初始生命值,是否红方)
    unit * train();             //训练一个新单位，加入到单位槽，打印训练信息，并返回其指针
    string getFaction();        //返回本司令部的派系
    bool factionIsRed(){
        if(Faction == "red")
            return true;
        else
            return false;
    }
    int getNo();                //返回下一个训练中单位的编号(iter+1)
    int getUnitCost(int typecode);//按训练顺序和单位迭代器返回单位的训练消耗
    int getHP(){
        return HP;
    }
    void checkWhetherEnemyInHQ(){   //单位前进完成后调用此函数检查，如果敌人进入司令部则结束游戏

    }
};
// 定义基类
class weapon{           // 武器的基类
protected:
    int Type;
    string name;
    int residualCount;
public:
    weapon():name(){}
    weapon(int N,const string & Name,int res){
        Type = N;
        residualCount = res;
        name = Name;
    }
    string getName(){
        return name;
    }
    int getType(){
        return Type;
    }
    int getResCount(){
        return residualCount;
    }
    static bool destroyWeapon(weapon * t){
        if(t->getType() == 1 || t->getType() == 2)
            t->residualCount--;
        if(t->getResCount() <= 0)
            return true;
        else
            return false;
    }
    bool isUsable(){
        return residualCount>0;
    }
    virtual int atk(unit * userUnit) = 0;
    virtual int sideEffect(unit * userUnit) = 0;
};
class dummyWeapon:public weapon{
public:
    dummyWeapon():weapon(inf,"dummy",0){}
    virtual int atk(unit * userUnit){ return 0;}
    virtual int sideEffect(unit * userUnit){ return 0;}
};
dummyWeapon emptySlot;
class unit{             //所有单位的基类
protected:
    string Faction;             //单位的派系
    int elements;               //单位的血量
    int force;                  //单位的攻击力
    int No;                     //单位的序号
    string type;                //单位的类型
    int weaponCount;            //武器数目
    vector<weapon *> weaponSlot;  //武器槽
    bool isAlive;
    bool statusChanged;     // 在一轮攻击中HP和武器状态是否发生变化
public:
    unit(){}
    unit(hq* masterHQ){
        Faction = masterHQ->getFaction(); //利用所属司令部的this指针初始化单位
        No = masterHQ->getNo();
        weaponCount = 0;
        weaponSlot.assign(10,&emptySlot);
        isAlive = true;
        statusChanged = true;
    }
    int getStrength(){
        return elements;
    }
    int getUnitNo(){
        return No;
    }
    string getUnitType(){
        return type;
    }
    string getWeaponInfo(){
        if(weaponCount == 0)
            return "It does not has weapon";
        else if(weaponCount > 0){
            string output = "It has ";
            output += "a " + weaponSlot[0]->getName();
            int next = 1;
            while (next < weaponCount - 1){
                output += ",a " + weaponSlot[next]->getName();
                next++;
            }
            if(weaponCount > 1)
                output += " and a " + weaponSlot[next]->getName();
            return output;
        } else
            return "";
    }
    bool alive(){
        return isAlive;
    }
    static bool comp(weapon * w1,weapon * w2){
        if(w1->getType() != w2->getType())
            return w1->getType() < w2->getType();
        else if(w1->getType() == 2)
            return w1->getResCount() < w2->getResCount();
        else
            return w1->getType() == w2->getType();
    }
    void sortWeapons(){
        //todo
    }
    void resetStatChangedFlag(){
        statusChanged = false;
    }
    bool StatChanged(){
        return statusChanged;
    }
    vector<weapon *> giveWeapon(int availableEmptySlot){      // 被wolf抢武器
        vector<weapon*> weapons;
        if(weaponCount == 0 || availableEmptySlot == 0)
            return weapons;
        sortWeapons();
        if(weaponSlot[0] != &emptySlot){  // 如果武器槽非空
            int seizeWeaponType = weaponSlot[0]->getType();
            int seizedCount = 0;
            for (int i = 0; i < weaponCount; ++i) {             // 抢走所有同类武器
                if(weaponSlot[i]->getType() == seizeWeaponType){
                    weapons.push_back(weaponSlot[i]);
                    weaponSlot[i] = &emptySlot;
                    seizedCount++;
                }
                if(seizeWeaponType != 2 && seizedCount >= availableEmptySlot)   //抢到了wolf可以持有的最大武器数目
                    break;
            }
            if(seizeWeaponType == 2 && seizedCount >= availableEmptySlot){      //返还拿不下的arrow
                sort(weapons.begin(),weapons.end(),comp);
                reverse(weapons.begin(),weapons.end());
                int i = 0;
                while(seizedCount > availableEmptySlot){
                    for (; i < 10; ++i) {
                        if(weaponSlot[i] == &emptySlot){
                            weaponSlot[i] = weapons[weapons.size()-1];
                            weapons.pop_back();
                            seizedCount--;
                            weaponCount++;
                            break;
                        }
                    }
                }
            }
            weaponCount -= seizedCount;
            sortWeapons();
        }
        if(weapons.size() > 0)
            statusChanged = true;
        return weapons;
    }
    virtual string getSpecialStatus(){
        return getWeaponInfo();
    };
    virtual void attack(unit * targetUnit){
        //检查双方的死活
        if(!alive())
            return;
        //没武器时站立挨打
        if(weaponCount == 0){
            return;
        }
        //选择武器
        int weaponNo = 0;
        while(weaponSlot[weaponNo] == &emptySlot && weaponNo < 10){
            weaponNo++;
        }
        targetUnit->hurt(weaponSlot[weaponNo]->atk(this));    //用武器攻击
        hurt(weaponSlot[weaponNo]->sideEffect(this));         //炸弹伤害波及自身
        if(weaponSlot[weaponNo]->getType() == 1 || weaponSlot[weaponNo]->getType() == 2)
            statusChanged = true;   //武器状态改变
        if(weapon::destroyWeapon(weaponSlot[weaponNo])){        //武器减耐久
            weapon * w = weaponSlot[weaponNo];
            weaponSlot[weaponNo] = &emptySlot;
            delete w;
            weaponCount--;
        }
    };
    virtual void hurt(int damage){
        elements -= damage;
        if(elements <= 0)
            isAlive = false;
        if(damage > 0)
            statusChanged = true;
    };
    virtual void moveForward(){
        // 前进时重置状态
        resetStatChangedFlag();
    };
};
// 派生具体武器
class sword:public weapon{
public:
    sword():weapon(0,"sword",inf){}
    virtual int atk(unit * userUnit){
        int atkNum = userUnit->getStrength() * 2/10;
        return atkNum;
    };
    virtual int sideEffect(unit * userUnit){
        return 0;
    };
};
class bomb:public weapon{
public:
    bomb():weapon(1,"bomb",1){}
    int confirmedSideDamage;
    virtual int atk(unit * userUnit){
        int atkNum = userUnit->getStrength() * 4/10;
        confirmedSideDamage = atkNum * 5/10;
        return atkNum;
    };
    virtual int sideEffect(unit * userUnit){
        return confirmedSideDamage;
    };
};
class arrow:public weapon{
public:
    arrow():weapon(2,"arrow",2){}
    virtual int atk(unit * userUnit){
        int atkNum = userUnit->getStrength() * 3/10;
        return atkNum;
    };
    virtual int sideEffect(unit * userUnit){
        return 0;
    };
};
weapon * genWeaponByNo(unsigned No){
    weapon * w;
    switch(No%3){
        case 0:w = new sword;break;
        case 1:w = new bomb;break;
        case 2:w = new arrow;break;
        default:w = &emptySlot;
    }
    return w;
}
class dragon: public unit{
public:
    dragon(hq* masterHQ):unit(masterHQ){    //调用基类的构造函数
        type = "dragon";
        elements = maxStrength[type];
        weaponCount = 1;
        weaponSlot[0] = genWeaponByNo(No);
    }
    string yell(){
        //todo
    }
};
class ninja: public unit{
public:
    ninja(hq* masterHQ):unit(masterHQ){
        type = "ninja";
        elements = maxStrength[type];
        weaponCount = 2;
        weaponSlot[0] = genWeaponByNo(No);
        weaponSlot[1] = genWeaponByNo(No+1);
    }
};
class iceman: public unit{
public:
    iceman(hq* masterHQ):unit(masterHQ){
        type = "iceman";
        elements = maxStrength[type];
        weaponCount = 1;
        weaponSlot[0] = genWeaponByNo(No);
    }
    virtual void moveForward(){
        //掉血
        hurt(elements /10);
        resetStatChangedFlag();
    }
};
class lion: public unit{
private:
    int loyalty;
public:
    lion(hq* masterHQ):unit(masterHQ){
        type = "lion";
        elements = maxStrength[type];
        loyalty = masterHQ->getHP() - elements;
        weaponCount = 1;
        weaponSlot[0] = genWeaponByNo(No);
    }
    string getSpecialStatus(){
        return "It's loyalty is " + to_string(loyalty);
    }
    bool runAway(){
        return loyalty <= 0;
    }
};
class wolf: public unit{
private:
    bool seized;
public:
    wolf(hq* masterHQ):unit(masterHQ){
        type = "wolf";
        elements = maxStrength[type];
        seized = false;
    }
    void seizeWeapon(unit * targetUnit){
        //不抢武器的情况
        if(weaponCount >= 10 || targetUnit->getUnitType() == "wolf")
            return;
        vector<weapon*> weaponList;
        weaponList = targetUnit->giveWeapon(10 - weaponCount);
        if(!weaponList.empty())
            statusChanged = true;
        //todo
    }
    virtual void attack(unit * targetUnit){
        //抢武器
        if(!seized)
            seizeWeapon(targetUnit);
        //todo
    }
    virtual void moveForward(){
        // 前进时重置状态
        statusChanged = false;
        seized = false;
    }
};
// 司令部的类函数
hq::hq(int M,bool isRed):city(true,isRed){
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
    if(factionIsRed())                 //新单位归入司令部待命单位的序列
        warriorRed = newUnit;
    else
        warriorBlue = newUnit;
    printf("%03d ",iter);           //打印训练成功信息
    cout << Faction << ' ' << myType << ' ' << newUnit->getUnitNo()
         << " born with elements " << newUnit->getStrength() << ','
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
        int M,N,K,T;
        vector<int> primaryHP(5);
        cin >> M >> N >> K >> T;
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