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
// 因为相对于魔兽世界2变化太大，所以重构
// 声明全局变量
unsigned N,K;    // N为城市数，K是狮子的忠诚度下降速度
map<string,int> maxElements;
map<string,int> maxForce;
vector<string> initUnitTypeSeq = {"dragon","ninja","iceman","lion","wolf"};
int minutes;        // 时间
bool gameFinish;    // 在有司令部被占领后标识之
// 声明基类
class unit;
class city;
class weapon;
// 声明函数
void headquarterIsTaken(bool isRed);    // 输出司令部被占领信息，并标识游戏结束flag
string time2STR();          // 返回当前时间的字符串形式
// 定义武器基类
class weapon{
protected:
    int TypeCode;
    string name;
    int residualCount;  // 剩余使用次数
public:
    weapon():name(){}
    weapon(int N,const string & Name,int res){
        TypeCode = N;
        residualCount = res;
        name = Name;
    }
    string getName(){
        return name;
    }
    int getType(){
        return TypeCode;
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
    virtual int atkCount(unit * userUnit) = 0;          // 武器的攻击力
    virtual int sideEffectCount(unit * userUnit) = 0;   // 武器对使用者的伤害
};
// 派生用于标识武器槽为空的dummy
class dummyWeapon:public weapon{
public:
    dummyWeapon():weapon(inf,"dummy",0){}
    virtual int atkCount(unit * userUnit){ return 0;}
    virtual int sideEffectCount(unit * userUnit){ return 0;}
};
dummyWeapon emptySlot = dummyWeapon();
// 定义单位基类
class unit{
protected:
    bool isRedFaction;
    string typeName;
    int No;
    int elements;
    int force;
    bool statusChanged;
    bool reachEnemyHQ;
    int weaponCount;
    vector<weapon*> Inventory;
public:
    unit(){}
    unit(bool isRed,int _No,const string & _typeName,int _elem,int _force){
        isRedFaction = isRed;
        No = _No;
        typeName = _typeName;
        elements = _elem;
        force = _force;
        statusChanged = false;
        Inventory.resize(10);
        reachEnemyHQ = false;
    }
    virtual void attack(unit* targetUnit){
        // 拿第一件武器
        weapon * weaponOnHand;
        for (int i = 0; i < 10; ++i)
            if(Inventory[i] != &emptySlot){
                weaponOnHand = Inventory[i];
            }
        // 打人
        if(weaponOnHand == nullptr)
            return;
        targetUnit->hurt(weaponOnHand->atkCount(this));
        this->hurt(weaponOnHand->sideEffectCount(this));
        // 武器损失耐久,损坏时将其删除
        if(weaponOnHand->destroyWeapon(weaponOnHand)){
            delete weaponOnHand;
            weaponOnHand = &emptySlot;
            weaponCount--;
        }
    }
    virtual void hurt(int damage){
        elements -= damage;
    }
    virtual void moveForward(){
        resetStat();
    }
    virtual void reportSpecialStatus(){}    // 让狮子在出生时汇报忠诚度的函数
    // 发布移动信息的函数
    void reportMovement(int cityNo){
        cout << time2STR() << (isRedFaction?" red ":" blue ");
        cout << typeName << ' ' << No;
        if(isRedFaction && cityNo == N+1){
            cout << " reached blue headquarter ";
            reachEnemyHQ = true;
        }
        else if(!isRedFaction && cityNo == 0){
            cout << " reached red headquarter ";
            reachEnemyHQ = true;
        }
        else{
            cout << " marched to city " << cityNo;
        }
        cout << " with " << elements << " elements and force " << force << endl;
        // 抵达司令部则调用占领函数
        if(isRedFaction && cityNo == N+1){
            headquarterIsTaken(false);
        }
        else if(!isRedFaction && cityNo == 0){
            headquarterIsTaken(true);
        }
    }
    virtual bool spAct5(){}         // 用于调用狮子逃跑的多态函数
    virtual void spAct35(unit* target){}        // 用于调用狼抢夺武器的多态函数
    virtual void spActBattle(int cityNo){}    // 用于调用龙战吼的多态函数
    // 55分时汇报情况
    virtual void reportWeapon(){
        if(!isAlive())
            return;
        int swordCount = 0,bombCount = 0,arrowCount = 0;
        for (auto iter = Inventory.begin(); iter != Inventory.end(); ++iter) {
            switch((*iter)->getType()){
                case 0:swordCount++;break;
                case 1:bombCount++;break;
                case 2:arrowCount++;break;
                default:;
            }
        }
        printf("%s %s %s %d has %d sword %d bomb %d arrow and %d elements\n",
                time2STR().c_str(),isRedFaction?"red":"blue",typeName.c_str(),
                No,swordCount,bombCount,arrowCount,elements);
    }
    void sortWeapon();  // 给持有的武器排序
    void resetStat(){
        statusChanged = false;
    }
    bool hasNoChanges(){
        return !statusChanged;
    }
    bool isAlive(){
        return elements > 0;
    }
    string Faction(){
        return (isRedFaction?"red":"blue");
    }
    int getElements(){ return elements;}
    int getForce(){ return elements;}
    string getTypeName(){ return typeName;}
    int getNo(){ return No;}
    friend void lootWeapon(unit* wolf,unit* target);    // 获取败者武器及wolf抢夺武器的函数
};
// 定义城市基类
class city{
protected:
    int cityNo;         // 城市编号
    unit* redWarrior;   // 在本城市的红方战士
    unit* blueWarrior;  // 在本城市的蓝方战士
    city* prevCity;     // 用于将城市序列构造成双向链表的指针，方便移动战士
    city* nextCity;
public:
    unit* redWarriorReached;    // 刚抵达的红战士
    unit* blueWarriorReached;   // 刚抵达的蓝战士
    city(){}
    city(int n):cityNo(n){}
    bool isRedHQ(){
        return cityNo == 0;     // 判断是否司令部，便于执行指针类型的强制转换
    };
    bool isBlueHQ(){
        return cityNo == (N+1);
    }
    void lionEscape(){
        if(redWarrior)
            if(redWarrior->spAct5()){
                delete redWarrior;
                redWarrior = nullptr;
            }
        if(blueWarrior)
            if(blueWarrior->spAct5()){
                delete blueWarrior;
                blueWarrior = nullptr;
            }
    }
    // 移动信息由city0向cityN+1依次发布，移动武士的函数调用逻辑依次实现
    bool letWarriorsMove(){
        //将所有武士移入下一城市的临时指针
        if(nextCity&&redWarrior){
            nextCity->redWarriorReached = redWarrior;
            redWarrior = nullptr;
        }
        if(prevCity&&blueWarrior){
            prevCity->blueWarriorReached = blueWarrior;
            blueWarrior = nullptr;
        }
    }
    // 从city0向cityN+1依次更新移动信息
    void updateWarriorInfo(){
        if(redWarriorReached){
            redWarrior = redWarriorReached;
            redWarriorReached = nullptr;
            redWarrior->moveForward();          // 移动函数
            redWarrior->reportMovement(cityNo); // 报告移动信息函数
        }
        if(blueWarriorReached){
            blueWarrior = blueWarriorReached;
            blueWarriorReached = nullptr;
            blueWarrior->moveForward();
            blueWarrior->reportMovement(cityNo);
        }
    }
    void wolfRobWeapon(){
        if(redWarrior)
            redWarrior->spAct35(blueWarrior);
        if(blueWarrior)
            blueWarrior->spAct35(redWarrior);
    }
    void battle(){
        if(!redWarrior||!blueWarrior)
            return;
        // 将武器进行排序
        redWarrior->sortWeapon();
        blueWarrior->sortWeapon();
        // 开始战斗
        while (true){
            // 重置状态变化flag
            redWarrior->resetStat();
            blueWarrior->resetStat();
            // 根据所在城市决定攻击顺序
            if(cityNo%2 == 0){
                blueWarrior->attack(redWarrior);
                // 反击
                if(redWarrior->isAlive() && blueWarrior->isAlive())
                    redWarrior->attack(blueWarrior);
            }
            else{
                redWarrior->attack(blueWarrior);
                // 反击
                if(blueWarrior->isAlive() && redWarrior->isAlive())
                    blueWarrior->attack(redWarrior);
            }
            // 判断并报告同归于尽,删除武士
            if(!redWarrior->isAlive() && !blueWarrior->isAlive()){
                // cout << both died in city
                delete blueWarrior;
                delete redWarrior;
                blueWarrior = nullptr;
                redWarrior = nullptr;
                break;
            }
            // 判断一方战胜，报告战胜信息并调用胜利后的特殊动作,之后获取武器、删除失败者
            else if(redWarrior->isAlive() && !blueWarrior->isAlive()){
                // cout todo
                redWarrior->spActBattle(cityNo);
                lootWeapon(redWarrior,blueWarrior);
                delete blueWarrior;
                blueWarrior = nullptr;
                break;
            }
            else if(!redWarrior->isAlive() && blueWarrior->isAlive()){
                // cout todo
                blueWarrior->spActBattle(cityNo);
                lootWeapon(blueWarrior,redWarrior);
                delete redWarrior;
                redWarrior = nullptr;
                break;
            }
            // 判断平局
            else if(redWarrior->isAlive() && blueWarrior->isAlive()
                    && redWarrior->hasNoChanges() && blueWarrior->hasNoChanges()){
                // todo
                cout << time2STR() << " both ";
                cout << " were alive in city " << cityNo << endl;
                break;
            }
        }
    }
    void letReportWeapon(){
        if(redWarrior)
            redWarrior->reportWeapon();
        if(blueWarrior)
            blueWarrior->reportWeapon();
    }
    friend void link2City(city * a,city * b);
};
void link2City(city * a,city * b){
    a->nextCity = b;
    b->prevCity = a;
}
// 派生具体武器
class sword:public weapon{
public:
    sword():weapon(0,"sword",inf){}
    virtual int atkCount(unit * userUnit){
        int atkNum = userUnit->getForce() * 2/10;
        return atkNum;
    };
    virtual int sideEffectCount(unit * userUnit){
        return 0;
    };
};
class bomb:public weapon{
public:
    bomb():weapon(1,"bomb",1){}
    int confirmedSideDamage;
    virtual int atkCount(unit * userUnit){
        int atkNum = userUnit->getForce() * 4/10;
        confirmedSideDamage = atkNum * 5/10;
        return atkNum;
    };
    virtual int sideEffectCount(unit * userUnit){
        return confirmedSideDamage;
    };
};
class arrow:public weapon{
public:
    arrow():weapon(2,"arrow",2){}
    virtual int atkCount(unit * userUnit){
        int atkNum = userUnit->getForce() * 3/10;
        return atkNum;
    };
    virtual int sideEffectCount(unit * userUnit){
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
vector<weapon*> initInventory(){
    vector<weapon*> a;
    a.assign(10,&emptySlot);
    return a;
}
// 派生司令部类
class headquarter:public city{
private:
    string Faction;
    int elements;       // 司令部HP
    int trainedUnits;   // 已训练单位数，用于生成下一个单位的序号
    vector<int> trainseq;
    bool trainFlag;
public:
    headquarter(int M,bool isRed):city(isRed?0:N+1){
        elements = M;
        Faction = isRed?"red":"blue";
        trainedUnits = 0;
        trainFlag = true;
        if(isRed)
            trainseq = {2,3,4,1,0}; // 与initUnitTypeSeq配合使用
        else
            trainseq = {3,0,1,2,4};
    }
    unit* train();          // 训练新单位并返回其指针
    void reportElements(){
        cout << time2STR() << ' ' << elements << " elements in " << Faction << " headquarter" << endl;
    }
    int getNextUnitNo(){
        trainedUnits++;
        return trainedUnits;
    }
    int getElements(){ return elements;}
};
// 派生具体单位类型
class dragon: public unit{
public:
    dragon(headquarter* masterHQ):unit(masterHQ->isRedHQ(),
            masterHQ->getNextUnitNo(),"dragon",maxElements["dragon"],maxForce["dragon"]){    //调用基类的构造函数
        Inventory = initInventory();
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }
    virtual void spActBattle(int cityNo){
        cout << time2STR() << (isRedFaction?" red ":" blue ");
        cout << typeName << ' ' << No << " yelled in city " << cityNo << endl;
    }
};
class ninja: public unit{
public:
    ninja(headquarter* masterHQ):unit(masterHQ->isRedHQ(),
            masterHQ->getNextUnitNo(),"ninja",maxElements["ninja"],maxForce["ninja"]){    //调用基类的构造函数
        Inventory = initInventory();
        weaponCount = 2;
        Inventory[0] = genWeaponByNo(No);
        Inventory[1] = genWeaponByNo(No+1);
    }
};
class iceman: public unit{
public:
    iceman(headquarter* masterHQ):unit(masterHQ->isRedHQ(),
            masterHQ->getNextUnitNo(),"iceman",maxElements["iceman"],maxForce["iceman"]){    //调用基类的构造函数
        Inventory = initInventory();
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }
    virtual void moveForward(){
        //掉血
        hurt(elements /10);
        resetStat();
    }
};
class lion: public unit{
private:
    int loyalty;
public:
    lion(headquarter* masterHQ):unit(masterHQ->isRedHQ(),
            masterHQ->getNextUnitNo(),"lion",maxElements["lion"],maxForce["lion"]){    //调用基类的构造函数
        loyalty = masterHQ->getElements() - elements;
        Inventory = initInventory();
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }
    virtual void reportSpecialStatus(){
        cout << "It's loyalty is " << loyalty << endl;
    }
    virtual void moveForward(){
        loyalty -= K;
        resetStat();
    }
    virtual bool spAct5(){
        if(loyalty <= 0 && !reachEnemyHQ){
            cout << time2STR() << ' ' << (isRedFaction?"red":"blue") << " lion " << No << " ran away" << endl;
            return true;
        }
        else
            return false;
    }
};
class wolf: public unit{
public:
    wolf(headquarter* masterHQ):unit(masterHQ->isRedHQ(),
            masterHQ->getNextUnitNo(),"wolf",maxElements["wolf"],maxForce["wolf"]){    //调用基类的构造函数
        weaponCount = 0;
        Inventory = initInventory();
    }
    virtual void spAct35(unit* target){
        if(weaponCount < 10 || target->getTypeName() != "wolf")
            lootWeapon(this,target);
    }
};
unit* headquarter::train(){
    // 要注意，这个版本的题目中，只要有一次生命不足以训练单位，就从此停止训练
    if(!trainFlag)
        return nullptr;
    unit * newUnit;
    string newUnitType = initUnitTypeSeq[trainseq[trainedUnits%5]];
    // 检查是否能训练新单位
    int newUnitElem = maxElements[newUnitType];
    int newUnitForce = maxForce[newUnitType];
    if(newUnitElem > elements){
        trainFlag = false;
        return nullptr;
    }
    if(newUnitType == "dragon"){
        newUnit = new dragon(this);
    }
    else if(newUnitType == "ninja"){
        newUnit = new ninja(this);
    }
    else if(newUnitType == "iceman"){
        newUnit = new iceman(this);
    }
    else if(newUnitType == "lion"){
        newUnit = new lion(this);
    }
    else if(newUnitType == "wolf"){
        newUnit = new wolf(this);
    }
    else{
        cout << "ERROR when train new unit" << endl;
        return nullptr;
    }
    // 训练完后扣除血量（序号/已经训练的单位数在初始化新单位时已经自动增加）
    elements -= newUnitElem;
    if(isRedHQ())
        redWarrior = newUnit;
    else if(isBlueHQ())
        blueWarrior = newUnit;
    printf("%s %s %s %d born\n",time2STR().c_str(),
            newUnit->Faction().c_str(),newUnit->getTypeName().c_str(),newUnit->getNo());
    newUnit->reportSpecialStatus();
    return newUnit;
}
bool weaponComp1(weapon* a,weapon* b){
    if(a->getType() == b->getType())
        return a->getResCount() < b->getResCount();
    else
        return a->getType()<b->getType();
}
bool weaponComp2(weapon* a,weapon* b){
    if(a->getType() == b->getType())
        return a->getResCount() > b->getResCount();
    else
        return a->getType()<b->getType();
}
// 这里注意，使用武器时优先使用用过的arrow，但抢夺武器时优先抢未用过的
void lootWeapon(unit* my,unit* target){
    if(target->weaponCount == 0)
        return;
    sort(target->Inventory.begin(),target->Inventory.end(),weaponComp2);
    while(my->weaponCount < 10 && target->weaponCount > 0){
        int emptySlotLocation = inf;
        for (int i = 0; i < 10; ++i) {
            if(my->Inventory[i] == &emptySlot){
                emptySlotLocation = i;
                break;
            }
        }
        if(emptySlotLocation == inf){
            my->weaponCount = 10;
            break;
        }
        int lootIter = inf;
        for (int j = 0; j < 10; ++j) {
            if(target->Inventory[j] != &emptySlot){
                lootIter = j;
                break;
            }
        }
        if(lootIter == inf){
            target->weaponCount = 0;
            break;
        }
        // 拿一件武器
        my->Inventory[emptySlotLocation] = target->Inventory[lootIter];
        target->Inventory[lootIter] = &emptySlot;
        my->weaponCount++;
        target->weaponCount--;
    }
}
void unit::sortWeapon(){
    if(weaponCount == 0)
        return;
    sort(Inventory.begin(),Inventory.end(),weaponComp1);
}

string time2STR(){
    int hour = minutes / 60;
    int resMinute = minutes % 60;
    char timeOutput[7];
    sprintf(timeOutput,"%03d:%02d",hour,resMinute);
    return string(timeOutput);
}
void headquarterIsTaken(bool isRed){
    cout << time2STR() << ' ' << isRed?"red":"blue" ;
    cout << " headquarter was taken" << endl;
    gameFinish = true;
}


int main(){
    int caseNum,u = 0;
    cin >> caseNum;
    while(++u <= caseNum){
        cout << "Case " << u << " :" << endl;
        int M,T;
        minutes = 0;
        gameFinish = false;
        vector<int> primaryElements(5);
        vector<int> primaryForce(5);
        cin >> M >> N >> K >> T;
        // 更新单位血量与攻击力数值
        for (int i = 0; i < 5; ++i) {
            cin >> primaryElements[i];
            maxElements[initUnitTypeSeq[i]] = primaryElements[i];
        }
        for (int j = 0; j < 5; ++j) {
            cin >> primaryForce[j];
            maxForce[initUnitTypeSeq[j]] = primaryForce[j];
        }
        vector<city*> cities(N+2);
        auto red = new headquarter(M,true);
        cities[0] = red;
        auto blue = new headquarter(M,false);
        cities[N+1] = blue;
        // 建立城市链
        for(int i = 1; i <= N; ++i) {
            cities[i] = new city(i);
        }
        for(int i = 0; i < N+1;i++){
            link2City(cities[i],cities[i+1]);
        }
        while (minutes <= T){
            // 每小时00分训练
            if(minutes%60 == 0){
                red->train();
                blue->train();
            }
            // 每小时05分狮子逃跑
            else if(minutes%60 == 5)
                for (int i = 0; i <= N+1; ++i)
                    cities[i]->lionEscape();
            // 每小时10分移动单位
            else if(minutes%60 == 10){
                for (int i = 0; i <= N+1; ++i) {
                    cities[i]->letWarriorsMove();
                }
                for (int i = 0; i <= N+1 ; ++i) {
                    cities[i]->updateWarriorInfo();
                }
            }
            // 每小时35分狼抢武器
            else if(minutes%60 == 35)
                for (int i = 0; i <= N+1; ++i) {
                    cities[i]->wolfRobWeapon();
                }
            // 每小时40分发生战斗
            else if(minutes%60 == 40){
                for (int i = 0; i <= N+1; ++i) {
                    cities[i]->battle();
                }
            }
            // 每小时50分报告司令部生命元
            else if(minutes%60 == 50){
                red->reportElements();
                blue->reportElements();
            }
            // 每小时55分报告武器情况
            else if(minutes%60 == 55){
                for (int i = 0; i <= N+1; ++i) {
                    cities[i]->letReportWeapon();
                }
            }
            minutes++;
            if(gameFinish) break;
        }
    }
    return 0;
}