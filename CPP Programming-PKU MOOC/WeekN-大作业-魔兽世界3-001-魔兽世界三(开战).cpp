#include <iostream>
#include <iomanip>
#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
#define inf 11451419
/**
 * PKU 程序设计与算法慕课（三） 魔兽世界3
 * 1:魔兽世界三(开战)
 * 
 * 描述
 * 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，
 * 城市从西向东依次编号为1,2,3 .... N ( N <= 20)。红魔军的司令部算作编号为0的城市，
 * 蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。
 * 
 * 两军的司令部都会制造武士。武士一共有dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
 * 双方的武士编号都是从1开始计算。红方制造出来的第n 个武士，编号就是n。同样，蓝方制造出来的第n 个武士，编号也是n。
 * 武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，
 * 如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。
 * 武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
 * sword的攻击力是使用者当前攻击力的20%(去尾取整)。
 * bomb的攻击力是使用者当前攻击力的40%(去尾取整)，但是也会导致使用者受到攻击，
 * 对使用者的攻击力是对敌人取整后的攻击力的1/2(去尾取整)。Bomb一旦使用就没了。
 * arrow的攻击力是使用者当前攻击力的30%(去尾取整)。一个arrow用两次就没了。
 * 
 * 武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。
 * 战斗的规则是：
 * 在奇数编号城市，红武士先发起攻击
 * 在偶数编号城市，蓝武士先发起攻击
 * 战斗开始前，双方先对自己的武器排好使用顺序，然后再一件一件地按顺序使用。编号小的武器，排在前面。
 * 若有多支arrow，用过的排在前面。排好序后，攻击者按此排序依次对敌人一件一件地使用武器。如果一种武器有多件，那就都要用上。
 * 每使用一件武器，被攻击者生命值要减去武器攻击力。如果任何一方生命值减为0或小于0即为死去。有一方死去，则战斗结束。
 * 双方轮流使用武器，甲用过一件，就轮到乙用。某一方把自己所有的武器都用过一轮后，就从头开始再用一轮。
 * 如果某一方没有武器了，那就挨打直到死去或敌人武器用完。武器排序只在战斗前进行，战斗中不会重新排序。
 * 如果双方武器都用完且都还活着，则战斗以平局结束。如果双方都死了，也算平局。
 * 有可能由于武士自身攻击力太低，而导致武器攻击力为0。攻击力为0的武器也要使用。
 * 如果战斗中双方的生命值和武器的状态都不再发生变化，则战斗结束，算平局。
 * 战斗的胜方获得对方手里的武器。武士手里武器总数不超过10件。缴获武器时，按照武器种类编号从小到大缴获。
 * 如果有多件arrow，优先缴获没用过的。
 * 如果战斗开始前双方都没有武器，则战斗视为平局。如果先攻击方没有武器，则由后攻击方攻击。
 * 
 * 不同的武士有不同的特点。
 * 编号为n的dragon降生时即获得编号为n%3 的武器。dragon在战斗结束后，如果还没有战死，就会欢呼。
 * 编号为n的ninjia降生时即获得编号为n%3 和(n+1)%3的武器。ninja 使用bomb不会让自己受伤。
 * 编号为n的iceman降生时即获得编号为n%3 的武器。iceman每前进一步，生命值减少10%(减少的量要去尾取整)。
 * 编号为n的lion降生时即获得编号为n%3 的武器。lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。
 * 每前进一步忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。
 * lion在己方司令部可能逃跑。
 * wolf降生时没有武器，但是在战斗开始前会抢到敌人编号最小的那种武器。
 * 如果敌人有多件这样的武器，则全部抢来。Wolf手里武器也不能超过10件。
 * 如果敌人arrow太多没法都抢来，那就先抢没用过的。如果敌人也是wolf，则不抢武器。
 * 
 * 以下是不同时间会发生的不同事件：
 * 在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。
 * 红方司令部按照iceman、lion、wolf、ninja、dragon 的顺序制造武士。
 * 蓝方司令部按照lion、dragon、ninja、iceman、wolf 的顺序制造武士。
 * 制造武士需要生命元。
 * 制造一个初始生命值为m 的武士，司令部中的生命元就要减少m 个。
 * 如果司令部中的生命元不足以制造某本该造的武士，那就从此停止制造武士。
 * 在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。
 * 在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。
 * 或从和敌军司令部相邻的城市到达敌军司令部。
 * 在每个小时的第35分：在有wolf及其敌人的城市，wolf要抢夺对方的武器。
 * 在每个小时的第40分：在有两个武士的城市，会发生战斗。
 * 在每个小时的第50分，司令部报告它拥有的生命元数量。
 * 在每个小时的第55分，每个武士报告其拥有的武器情况。
 * 武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。
 * 任何一方的司令部里若是出现了敌人，则认为该司令部已被敌人占领。
 * 任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。
 * 
 * 给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：
 * 1) 武士降生
 * 输出样例：000:00 blue dragon 1 born
 * 表示在0点0分，编号为1的蓝魔dragon武士降生
 * 如果造出的是lion，那么还要多输出一行，例:
 * 000:00 blue lion 1 born
 * Its loyalty is 24
 * 表示该lion降生时的忠诚度是24
 * 2) lion逃跑
 * 输出样例：000:05 blue lion 1 ran away
 * 表示在0点5分，编号为1的蓝魔lion武士逃走
 * 3) 武士前进到某一城市
 * 输出样例：
 * 000:10 red iceman 1 marched to city 1 with 20 elements and force 30
 * 表示在0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30
 * 对于iceman,输出的生命值应该是变化后的数值
 * 4) wolf抢敌人的武器
 * 000:35 blue wolf 2 took 3 bomb from red dragon 2 in city 4
 * 表示在0点35分，4号城市中，红魔1号武士wolf 抢走蓝魔2号武士dragon 3个bomb。为简单起见，武器不写复数形式
 * 5) 报告战斗情况
 * 战斗只有3种可能的输出结果：
 * 000:40 red iceman 1 killed blue lion 12 in city 2 remaining 20 elements
 * 表示在0点40分，1号城市中，红魔1号武士iceman 杀死蓝魔12号武士lion后，剩下生命值20
 * 000:40 both red iceman 1 and blue lion 12 died in city 2
 * 注意，把红武士写前面
 * 000:40 both red iceman 1 and blue lion 12 were alive in city 2
 * 注意，把红武士写前面
 * 6) 武士欢呼
 * 输出样例：003:40 blue dragon 2 yelled in city 4
 * 7) 武士抵达敌军司令部
 * 输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30
 * （此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值
 * 8) 司令部被占领
 * 输出样例：003:10 blue headquarter was taken
 * 9)司令部报告生命元数量
 * 000:50 100 elements in red headquarter
 * 000:50 120 elements in blue headquarter
 * 表示在0点50分，红方司令部有100个生命元，蓝方有120个
 * 10)武士报告情况
 * 000:55 blue wolf 2 has 2 sword 3 bomb 0 arrow and 7 elements
 * 为简单起见，武器都不写复数形式。elements一律写复数，哪怕只有1个
 * 交代武器情况时，次序依次是：sword,bomb, arrow。
 * 
 * 输出事件时：
 * 首先按时间顺序输出；
 * 同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。
 * 在一次战斗中有可能发生上面的 5 至 6 号事件。这些事件都算同时发生，其时间就是战斗开始时间。
 * 一次战斗中的这些事件，序号小的应该先输出。
 * 两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。
 * 对于同一城市，同一时间发生的事情，先输出红方的，后输出蓝方的。
 * 显然，8号事件发生之前的一瞬间一定发生了7号事件。输出时，这两件事算同一时间发生，但是应先输出7号事件
 * 虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。
 * 
 * 
 * 输入
 * 第一行是t,代表测试数据组数
 * 
 * 每组样例共三行。
 * 第一行，4个整数 M,N,K, T。其含义为：
 * 每个司令部一开始都有M个生命元( 1 <= M <= 100000)
 * 两个司令部之间一共有N个城市( 1 <= N <= 20 )
 * lion每前进一步，忠诚度就降低K。(0<=K<=100)
 * 要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 6000
 * 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于200
 * 第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于200
 * 
 * 输出
 * 对每组数据，先输出一行：
 * Case n:
 * 如对第一组数据就输出 Case 1:
 * 然后按恰当的顺序和格式输出到时间T为止发生的所有事件。
 * 每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
 */
/**
 * 说明
 * 因为题设相对于魔兽世界2变化太大，所以进行了重构
 * 注意点：
 * 1.战斗时，每个单位会按顺序循环切换使用手上的武器，
 *   这里有个情况，就是如果单位手上有多把武器，其中部分能给对方造成伤害而部分不能，
 *   就有可能在未使用到能炸死对方的炸弹时就被提前判断这次战斗为平局，
 *   结果战斗双方的武器数目和生命值就都算错了，
 *   解决方法就是分别存储三种武器的数目，直到双方将bomb和arrow用完再进行平局判断，
 *   但我在这使用的是简单的超时机制，直接等待maxWait=攻击10次再判断。
 * 2.注意wolf抢夺武器的实现
 *
 */
// 声明全局变量
unsigned N, K;    // N为城市数，K是狮子的忠诚度下降速度
map<string, int> maxElements;
map<string, int> maxForce;
vector<string> initUnitTypeSeq = {"dragon", "ninja", "iceman", "lion", "wolf"};
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
class weapon {
protected:
    int TypeCode;
    string name;
    int residualCount;  // 剩余使用次数
public:
    weapon() {}

    weapon(int N, const string &Name, int res) {
        TypeCode = N;
        residualCount = res;
        name = Name;
    }

    string getName() {
        return name;
    }

    int getType() {
        return TypeCode;
    }

    int getResCount() {
        return residualCount;
    }

    void loseRes() {
        residualCount--;
    }

    bool isUsable() {
        return residualCount > 0;
    }

    virtual int atkCount(unit *userUnit) = 0;          // 武器的攻击力
    virtual int sideEffectCount(unit *userUnit) = 0;   // 武器对使用者的伤害
};

// 派生用于标识武器槽为空的dummy
class dummyWeapon : public weapon {
public:
    dummyWeapon() : weapon(inf, "dummy", 0) {}

    virtual int atkCount(unit *userUnit) { return 0; }

    virtual int sideEffectCount(unit *userUnit) { return 0; }
};

dummyWeapon emptySlot = dummyWeapon();

// 定义单位基类
class unit {
protected:
    bool isRedFaction;
    string typeName;    // 单位类型名
    int No;         // 单位序号
    int elements;   // 单位生命值
    int force;      // 单位攻击力
    bool statusChanged; // 在攻击/被攻击流程后血量与武器状态是否发生变化的标识
    bool reachEnemyHQ;  // 抵达敌军司令部标识
    int weaponCount;    // 持有武器数
    vector<weapon *> Inventory; //武器栏
    int weaponIter;     //战斗时用于按顺序轮流使用武器
public:
    unit() {}

    unit(bool isRed, int _No, const string &_typeName, int _elem, int _force) {
        isRedFaction = isRed;
        No = _No;
        typeName = _typeName;
        elements = _elem;
        force = _force;
        statusChanged = false;
        Inventory.resize(10);   // 最大武器数目为10
        reachEnemyHQ = false;
        Inventory.assign(10, &emptySlot);
    }

    virtual void attack(unit *targetUnit) {
        // 拿第一件武器
        weapon *weaponOnHand = nullptr;
        // 没武器就挨打
        int miniCount = 10;
        if (weaponCount <= 0)
            return;
        while (Inventory[weaponIter] == &emptySlot) {
            weaponIter++;
            miniCount--;
            if (weaponIter >= 10)
                weaponIter = 0;
            if (miniCount < 0)
                return;
        }
        weaponOnHand = Inventory[weaponIter];
        if (weaponOnHand == nullptr)
            return;
        // 打人
        targetUnit->hurt(weaponOnHand->atkCount(this));
        this->hurt(weaponOnHand->sideEffectCount(this));
        // 武器损失耐久,损坏时将其删除，将武器库该位置替换为dummy
        if (weaponOnHand->getType() == 1 || weaponOnHand->getType() == 2) {
            weaponOnHand->loseRes();
            statusChanged = true;
        }
        if (!weaponOnHand->isUsable()) {
            delete Inventory[weaponIter];
            weaponCount--;
            Inventory[weaponIter] = &emptySlot;
            statusChanged = true;
        }
        weaponIter++;
        if (weaponIter >= 10)
            weaponIter = 0;
    }

    virtual void hurt(int damage) {
        elements -= damage;
        if (damage > 0)
            statusChanged = true;
    }

    virtual void moveForward() {
        resetStat();
    }

    virtual void reportSpecialStatus() {}    // 让狮子在出生时汇报忠诚度的函数
    // 发布移动信息的函数
    void reportMovement(int cityNo) {
        cout << time2STR() << (isRedFaction ? " red " : " blue ");
        cout << typeName << ' ' << No;
        if (isRedFaction && cityNo == N + 1) {
            cout << " reached blue headquarter ";
            reachEnemyHQ = true;
        } else if (!isRedFaction && cityNo == 0) {
            cout << " reached red headquarter ";
            reachEnemyHQ = true;
        } else {
            cout << " marched to city " << cityNo << ' ';
        }
        cout << "with " << elements << " elements and force " << force << endl;
        // 抵达司令部则调用占领函数
        if (isRedFaction && cityNo == N + 1) {
            headquarterIsTaken(false);
        } else if (!isRedFaction && cityNo == 0) {
            headquarterIsTaken(true);
        }
    }

    virtual bool spAct5() { return false; }    // 用于调用狮子逃跑的多态函数,默认返回false
    virtual void spAct35(unit *target, int cityNo = 0) {}      // 用于调用狼抢夺武器的多态函数
    virtual void spActBattle(int cityNo) {}    // 用于调用龙战吼的多态函数
    // 55分时汇报情况
    virtual void reportWeapon() {
        if (!isAlive())
            return;
        int swordCount = 0, bombCount = 0, arrowCount = 0;
        for (auto iter = Inventory.begin(); iter != Inventory.end(); ++iter) {
            switch ((*iter)->getType()) {
                case 0:
                    swordCount++;
                    break;
                case 1:
                    bombCount++;
                    break;
                case 2:
                    arrowCount++;
                    break;
                default:;
            }
        }
        printf("%s %s %s %d has %d sword %d bomb %d arrow and %d elements\n",
               time2STR().c_str(), isRedFaction ? "red" : "blue", typeName.c_str(),
               No, swordCount, bombCount, arrowCount, elements);
    }

    void sortWeapon();  // 给持有的武器排序
    void resetStat() {
        statusChanged = false;
    }

    bool hasNoChanges() {
        return !statusChanged;
    }

    bool isAlive() {
        return elements > 0;
    }

    string Faction() {
        return (isRedFaction ? "red" : "blue");
    }

    int getElements() { return elements; }

    int getForce() { return force; }

    string getTypeName() { return typeName; }

    int getNo() { return No; }

    friend void lootWeapon(unit *my, unit *target);    // 获取败者武器的函数
    friend void wolfRobWeapon(unit *wolf, unit *target, int cityNo);   //wolf抢夺武器的函数
};

// 定义城市基类
class city {
protected:
    int cityNo;         // 城市编号
    unit *redWarrior;   // 在本城市的红方战士
    unit *blueWarrior;  // 在本城市的蓝方战士
    city *prevCity;     // 用于将城市序列构造成双向链表的指针，方便移动战士
    city *nextCity;
public:
    unit *redWarriorReached;    // 刚抵达的红战士
    unit *blueWarriorReached;   // 刚抵达的蓝战士
    city() {}

    city(int n) : cityNo(n) {
        redWarrior = redWarriorReached = blueWarrior = blueWarriorReached = nullptr;
        prevCity = nextCity = nullptr;
    }

    bool isRedHQ() {
        return cityNo == 0;     // 判断是否司令部，便于执行指针类型的强制转换
    };

    bool isBlueHQ() {
        return cityNo == (N + 1);
    }

    void lionEscape() {
        if (redWarrior) {
            if (redWarrior->spAct5()) {
                delete redWarrior;
                redWarrior = nullptr;
            }
        }
        if (blueWarrior) {
            if (blueWarrior->spAct5()) {
                delete blueWarrior;
                blueWarrior = nullptr;
            }
        }
    }

    // 移动信息由city0向cityN+1依次发布，移动武士的函数调用逻辑依次实现
    bool letWarriorsMove() {
        //将所有武士移入下一城市的临时指针
        if (nextCity && redWarrior) {
            nextCity->redWarriorReached = redWarrior;
            redWarrior = nullptr;
        }
        if (prevCity && blueWarrior) {
            prevCity->blueWarriorReached = blueWarrior;
            blueWarrior = nullptr;
        }
    }

    // 从city0向cityN+1依次更新移动信息
    void updateWarriorInfo() {
        if (redWarriorReached) {
            redWarrior = redWarriorReached;
            redWarriorReached = nullptr;
            redWarrior->moveForward();          // 移动函数
            redWarrior->reportMovement(cityNo); // 报告移动信息函数
        }
        if (blueWarriorReached) {
            blueWarrior = blueWarriorReached;
            blueWarriorReached = nullptr;
            blueWarrior->moveForward();
            blueWarrior->reportMovement(cityNo);
        }
    }

    void wolfRobWeapon() {
        if (redWarrior)
            redWarrior->spAct35(blueWarrior, cityNo);
        if (blueWarrior)
            blueWarrior->spAct35(redWarrior, cityNo);
    }

    void battle() {
        if (!redWarrior || !blueWarrior)
            return;
        // 将武器进行排序
        redWarrior->sortWeapon();
        blueWarrior->sortWeapon();
        // 设置一个最大等待计数器，用来应对平局的情形
        int maxWaitingCount = 10;
        // 开始战斗
        while (true) {
            // 重置状态变化flag
            redWarrior->resetStat();
            blueWarrior->resetStat();
            // 根据所在城市决定攻击顺序
            if (cityNo % 2 == 0) {
                blueWarrior->attack(redWarrior);
                // 反击
                if (redWarrior->isAlive() && blueWarrior->isAlive())
                    redWarrior->attack(blueWarrior);
            } else {
                redWarrior->attack(blueWarrior);
                // 反击
                if (blueWarrior->isAlive() && redWarrior->isAlive())
                    blueWarrior->attack(redWarrior);
            }
            // 判断并报告同归于尽,删除武士
            if (!redWarrior->isAlive() && !blueWarrior->isAlive()) {
                cout << time2STR() << " both red " << redWarrior->getTypeName() << ' ' << redWarrior->getNo();
                cout << " and blue " << blueWarrior->getTypeName() << ' ' << blueWarrior->getNo();
                cout << " died in city " << cityNo << endl;
                delete blueWarrior;
                delete redWarrior;
                blueWarrior = nullptr;
                redWarrior = nullptr;
                break;
            }
                // 判断一方战胜，报告战胜信息并调用胜利后的特殊动作,之后获取武器、删除失败者
            else if (redWarrior->isAlive() && !blueWarrior->isAlive()) {
                cout << time2STR() << " red " << redWarrior->getTypeName() << ' ' << redWarrior->getNo();
                cout << " killed blue " << blueWarrior->getTypeName() << ' ' << blueWarrior->getNo();
                cout << " in city " << cityNo << " remaining " << redWarrior->getElements() << " elements" << endl;
                redWarrior->spActBattle(cityNo);
                lootWeapon(redWarrior, blueWarrior);
                delete blueWarrior;
                blueWarrior = nullptr;
                break;
            } else if (!redWarrior->isAlive() && blueWarrior->isAlive()) {
                cout << time2STR() << " blue " << blueWarrior->getTypeName() << ' ' << blueWarrior->getNo();
                cout << " killed red " << redWarrior->getTypeName() << ' ' << redWarrior->getNo();
                cout << " in city " << cityNo << " remaining " << blueWarrior->getElements() << " elements" << endl;
                blueWarrior->spActBattle(cityNo);
                lootWeapon(blueWarrior, redWarrior);
                delete redWarrior;
                redWarrior = nullptr;
                break;
            }
                // 判断平局
            else if (redWarrior->isAlive() && blueWarrior->isAlive()
                     && redWarrior->hasNoChanges() && blueWarrior->hasNoChanges() && maxWaitingCount > 0) {
                maxWaitingCount--;
            } else if (redWarrior->isAlive() && blueWarrior->isAlive()
                       && redWarrior->hasNoChanges() && blueWarrior->hasNoChanges() && maxWaitingCount <= 0) {
                cout << time2STR() << " both red " << redWarrior->getTypeName() << ' ' << redWarrior->getNo();
                cout << " and blue " << blueWarrior->getTypeName() << ' ' << blueWarrior->getNo();
                cout << " were alive in city " << cityNo << endl;
                redWarrior->spActBattle(cityNo);
                blueWarrior->spActBattle(cityNo);
                break;
            }
        }
    }

    void letReportWeapon() {
        if (redWarrior)
            redWarrior->reportWeapon();
        if (blueWarrior)
            blueWarrior->reportWeapon();
    }

    friend void link2City(city *a, city *b);
};

void link2City(city *a, city *b) {
    a->nextCity = b;
    b->prevCity = a;
}

// 派生具体武器
class sword : public weapon {
public:
    sword() : weapon(0, "sword", inf) {}

    virtual int atkCount(unit *userUnit) {
        int atkNum = userUnit->getForce() * 2 / 10;
        return atkNum;
    };

    virtual int sideEffectCount(unit *userUnit) {
        return 0;
    };
};

class bomb : public weapon {
public:
    bomb() : weapon(1, "bomb", 1) {}

    int confirmedSideDamage;

    virtual int atkCount(unit *userUnit) {
        int atkNum = userUnit->getForce() * 4 / 10;
        confirmedSideDamage = atkNum * 5 / 10;
        return atkNum;
    };

    virtual int sideEffectCount(unit *userUnit) {
        return confirmedSideDamage;
    };
};

class arrow : public weapon {
public:
    arrow() : weapon(2, "arrow", 2) {}

    virtual int atkCount(unit *userUnit) {
        int atkNum = userUnit->getForce() * 3 / 10;
        return atkNum;
    };

    virtual int sideEffectCount(unit *userUnit) {
        return 0;
    };
};

weapon *genWeaponByNo(unsigned No) {
    weapon *w;
    switch (No % 3) {
        case 0:
            w = new sword;
            break;
        case 1:
            w = new bomb;
            break;
        case 2:
            w = new arrow;
            break;
        default:
            w = &emptySlot;
    }
    return w;
}

// 派生司令部类
class headquarter : public city {
private:
    string Faction;
    int elements;       // 司令部HP
    int trainedUnits;   // 已训练单位数，用于生成下一个单位的序号
    vector<int> trainseq;
    bool trainFlag;
public:
    headquarter(int M, bool isRed) : city(isRed ? 0 : N + 1) {
        elements = M;
        Faction = isRed ? "red" : "blue";
        trainedUnits = 0;
        trainFlag = true;
        if (isRed)
            trainseq = {2, 3, 4, 1, 0}; // 与initUnitTypeSeq配合使用
        else
            trainseq = {3, 0, 1, 2, 4};
    }

    unit *train();          // 训练新单位并返回其指针
    void reportElements() {
        cout << time2STR() << ' ' << elements << " elements in " << Faction << " headquarter" << endl;
    }

    int getNextUnitNo() {
        trainedUnits++;
        return trainedUnits;
    }

    int getElements() { return elements; }
};

// 派生具体单位类型
class dragon : public unit {
public:
    dragon(headquarter *masterHQ) : unit(masterHQ->isRedHQ(),
                                         masterHQ->getNextUnitNo(), "dragon", maxElements["dragon"],
                                         maxForce["dragon"]) {    //调用基类的构造函数
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }

    virtual void spActBattle(int cityNo) {
        cout << time2STR() << (isRedFaction ? " red " : " blue ");
        cout << typeName << ' ' << No << " yelled in city " << cityNo << endl;
    }
};

class ninja : public unit {
public:
    ninja(headquarter *masterHQ) : unit(masterHQ->isRedHQ(),
                                        masterHQ->getNextUnitNo(), "ninja", maxElements["ninja"],
                                        maxForce["ninja"]) {    //调用基类的构造函数
        weaponCount = 2;
        Inventory[0] = genWeaponByNo(No);
        Inventory[1] = genWeaponByNo(No + 1);
    }

    // 忍者免疫炸弹副作用
    virtual void attack(unit *targetUnit) {
        // 拿第一件武器
        weapon *weaponOnHand = nullptr;
        // 没武器就挨打
        int miniCount = 10;
        if (weaponCount <= 0)
            return;
        while (Inventory[weaponIter] == &emptySlot) {
            weaponIter++;
            miniCount--;
            if (weaponIter >= 10)
                weaponIter = 0;
            if (miniCount < 0)
                return;
        }
        weaponOnHand = Inventory[weaponIter];
        if (weaponOnHand == nullptr)
            return;
        // 打人
        targetUnit->hurt(weaponOnHand->atkCount(this));
        // 武器损失耐久,损坏时将其删除，将武器库该位置替换为dummy
        if (weaponOnHand->getType() == 1 || weaponOnHand->getType() == 2) {
            weaponOnHand->loseRes();
            statusChanged = true;
        }
        if (!weaponOnHand->isUsable()) {
            delete Inventory[weaponIter];
            weaponCount--;
            Inventory[weaponIter] = &emptySlot;
            statusChanged = true;
        }
        weaponIter++;
        if (weaponIter >= 10)
            weaponIter = 0;
    }

};

class iceman : public unit {
public:
    iceman(headquarter *masterHQ) : unit(masterHQ->isRedHQ(),
                                         masterHQ->getNextUnitNo(), "iceman", maxElements["iceman"],
                                         maxForce["iceman"]) {    //调用基类的构造函数
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }

    virtual void moveForward() {
        //掉血
        hurt(elements / 10);
        resetStat();
    }
};

class lion : public unit {
private:
    int loyalty;
public:
    lion(headquarter *masterHQ) : unit(masterHQ->isRedHQ(),
                                       masterHQ->getNextUnitNo(), "lion", maxElements["lion"],
                                       maxForce["lion"]) {    //调用基类的构造函数
        loyalty = masterHQ->getElements() - elements;
        weaponCount = 1;
        Inventory[0] = genWeaponByNo(No);
    }

    virtual void reportSpecialStatus() {
        cout << "Its loyalty is " << loyalty << endl;
    }

    virtual void moveForward() {
        loyalty -= K;
        resetStat();
    }

    virtual bool spAct5() {
        if (reachEnemyHQ)
            return false;
        if (loyalty <= 0) {
            cout << time2STR() << ' ' << (isRedFaction ? "red" : "blue") << " lion " << No << " ran away" << endl;
            return true;
        } else
            return false;
    }
};

class wolf : public unit {
public:
    wolf(headquarter *masterHQ) : unit(masterHQ->isRedHQ(),
                                       masterHQ->getNextUnitNo(), "wolf", maxElements["wolf"],
                                       maxForce["wolf"]) {    //调用基类的构造函数
        weaponCount = 0;
    }

    virtual void spAct35(unit *target, int cityNo = 0) {
        if (target == nullptr)
            return;
        if (weaponCount < 10 && target->getTypeName() != "wolf") {
            wolfRobWeapon(this, target, cityNo);
        } else
            return;
    }
};

unit *headquarter::train() {
    // 要注意，这个版本的题目中，只要有一次生命不足以训练单位，就从此停止训练
    if (!trainFlag)
        return nullptr;
    unit *newUnit;
    string newUnitType = initUnitTypeSeq[trainseq[trainedUnits % 5]];
    // 检查是否能训练新单位
    int newUnitElem = maxElements[newUnitType];
    int newUnitForce = maxForce[newUnitType];
    if (newUnitElem > elements) {
        trainFlag = false;
        return nullptr;
    }
    if (newUnitType == "dragon") {
        newUnit = new dragon(this);
    } else if (newUnitType == "ninja") {
        newUnit = new ninja(this);
    } else if (newUnitType == "iceman") {
        newUnit = new iceman(this);
    } else if (newUnitType == "lion") {
        newUnit = new lion(this);
    } else if (newUnitType == "wolf") {
        newUnit = new wolf(this);
    } else {
        cout << "ERROR when train new unit" << endl;
        return nullptr;
    }
    // 训练完后扣除血量（序号/已经训练的单位数在初始化新单位时已经自动增加）
    elements -= newUnitElem;
    if (isRedHQ())
        redWarrior = newUnit;
    else if (isBlueHQ())
        blueWarrior = newUnit;
    printf("%s %s %s %d born\n", time2STR().c_str(),
           newUnit->Faction().c_str(), newUnit->getTypeName().c_str(), newUnit->getNo());
    newUnit->reportSpecialStatus();
    return newUnit;
}

bool weaponComp1(weapon *a, weapon *b) {
    if (a->getType() == b->getType())
        return a->getResCount() < b->getResCount();
    else
        return a->getType() < b->getType();
}

bool weaponComp2(weapon *a, weapon *b) {
    if (a->getType() == b->getType())
        return a->getResCount() > b->getResCount();
    else
        return a->getType() < b->getType();
}

// 这里注意，使用武器时优先使用用过的arrow，但抢夺武器时优先抢未用过的
void lootWeapon(unit *my, unit *target) {
    if (!target || target->weaponCount == 0)
        return;
    sort(target->Inventory.begin(), target->Inventory.end(), weaponComp2);
    while (my->weaponCount < 10 && target->weaponCount > 0) {
        int emptySlotLocation = inf;
        for (int i = 0; i < 10; ++i) {
            if (my->Inventory[i] == &emptySlot) {
                emptySlotLocation = i;
                break;
            }
        }
        if (emptySlotLocation == inf) {
            my->weaponCount = 10;
            break;
        }
        int lootIter = inf;
        for (int j = 0; j < 10; ++j) {
            if (target->Inventory[j] != &emptySlot) {
                lootIter = j;
                break;
            }
        }
        if (lootIter == inf) {
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

void wolfRobWeapon(unit *wolf, unit *target, int cityNo) {
    int weaponID = inf;
    vector<weapon *> temp;
    int count = 0, tempSize = 0;
    for (int i = 0; i < 10; ++i) {
        if (target->Inventory[i]->getType() < weaponID)
            weaponID = target->Inventory[i]->getType();
    }
    if (weaponID == inf)
        return;
    for (int j = 0; j < 10; ++j) {
        if (target->Inventory[j]->getType() == weaponID) {
            temp.push_back(target->Inventory[j]);
            target->Inventory[j] = &emptySlot;
            target->weaponCount--;
            tempSize++;
        }
    }
    sort(temp.begin(), temp.end(), weaponComp2);
    // 抢武器
    while (wolf->weaponCount < 10 && tempSize > 0) {
        for (int i = 0; i < temp.size(); ++i) {
            if (temp[i]) {
                for (int j = 0; j < 10; ++j) {
                    if (wolf->Inventory[j] == &emptySlot) {
                        wolf->Inventory[j] = temp[i];
                        temp[i] = nullptr;
                        wolf->weaponCount++;
                        count++;
                        tempSize--;
                        break;
                    }
                }
                if (wolf->weaponCount >= 10)
                    break;
            }
        }
    }
    // 抢剩下的武器返回原武器槽
    for (int k = 0; k < temp.size(); ++k) {
        if (temp[k]) {
            for (int i = 0; i < 10; ++i) {
                if (target->Inventory[i] == &emptySlot) {
                    target->Inventory[i] = temp[k];
                    temp[k] = nullptr;
                    target->weaponCount++;
                    break;
                }
            }
        }
    }
    if (count == 0)
        return;
    cout << time2STR() << ' ' << wolf->Faction() << " wolf " << wolf->No << " took ";
    cout << count << ((weaponID == 0) ? " sword " : ((weaponID == 1) ? " bomb " : " arrow "));
    cout << "from " << target->Faction() << ' ' << target->typeName << ' ' << target->No;
    cout << " in city " << cityNo << endl;
}

void unit::sortWeapon() {
    if (weaponCount == 0)
        return;
    sort(Inventory.begin(), Inventory.end(), weaponComp1);
    weaponIter = 0; // 重置武器使用迭代器
}

string time2STR() {
    int hour = minutes / 60;
    int resMinute = minutes % 60;
    char timeOutput[7];
    sprintf(timeOutput, "%03d:%02d", hour, resMinute);
    return string(timeOutput);
}

void headquarterIsTaken(bool isRed) {
    cout << time2STR() << ' ' << (isRed ? "red" : "blue");
    cout << " headquarter was taken" << endl;
    gameFinish = true;
}


int main() {
    int caseNum, u = 0;
    cin >> caseNum;
    while (++u <= caseNum) {
        cout << "Case " << u << ":" << endl;
        int M, T;
        minutes = 0;
        gameFinish = false;
        maxElements.clear();
        maxForce.clear();
        vector<int> primaryElements(5);
        vector<int> primaryForce(5);
        cin >> M >> N >> K >> T; // M个生命元，N个城市，lion每步减低K忠诚，输出信息到时间T
        // 更新单位血量与攻击力数值
        for (int i = 0; i < 5; ++i) {
            cin >> primaryElements[i];
            maxElements[initUnitTypeSeq[i]] = primaryElements[i];
        }
        for (int j = 0; j < 5; ++j) {
            cin >> primaryForce[j];
            maxForce[initUnitTypeSeq[j]] = primaryForce[j];
        }
        vector<city *> cities(N + 2);
        auto red = new headquarter(M, true);
        cities[0] = red;
        auto blue = new headquarter(M, false);
        cities[N + 1] = blue;
        // 建立城市链
        for (int i = 1; i <= N; ++i) {
            cities[i] = new city(i);
        }
        for (int i = 0; i < N + 1; i++) {
            link2City(cities[i], cities[i + 1]);
        }
        while (minutes <= T) {
            // 每小时00分训练
            if (minutes % 60 == 0) {
                red->train();
                blue->train();
            }
                // 每小时05分狮子逃跑
            else if (minutes % 60 == 5)
                for (int i = 0; i <= N + 1; ++i)
                    cities[i]->lionEscape();
                // 每小时10分移动单位
            else if (minutes % 60 == 10) {
                for (int i = 0; i <= N + 1; ++i) {
                    cities[i]->letWarriorsMove();
                }
                for (int i = 0; i <= N + 1; ++i) {
                    cities[i]->updateWarriorInfo();
                }
            }
                // 每小时35分狼抢武器
            else if (minutes % 60 == 35)
                for (int i = 0; i <= N + 1; ++i) {
                    cities[i]->wolfRobWeapon();
                }
                // 每小时40分发生战斗
            else if (minutes % 60 == 40) {
                for (int i = 0; i <= N + 1; ++i) {
                    cities[i]->battle();
                }
            }
                // 每小时50分报告司令部生命元
            else if (minutes % 60 == 50) {
                red->reportElements();
                blue->reportElements();
            }
                // 每小时55分报告武器情况
            else if (minutes % 60 == 55) {
                for (int i = 0; i <= N + 1; ++i) {
                    cities[i]->letReportWeapon();
                }
            }
            minutes++;
            if (gameFinish) break;
        }
    }
    return 0;
}