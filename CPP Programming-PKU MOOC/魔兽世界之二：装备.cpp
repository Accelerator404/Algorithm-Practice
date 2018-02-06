#include <iostream>
#include <iomanip>
using namespace std;

/**
 * 魔兽世界之二：装备
 *
 * 描述
 * 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
 * 红司令部，City 1，City 2，……，City n，蓝司令部
 * 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
 * 有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
 * 双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
 * 不同的武士有不同的特点。
 * dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。
 * dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
 * ninja可以拥有两件武器。编号为n的ninja降生时即获得编号为 n%3 和 (n+1)%3的武器。
 * iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
 * lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
 * wolf没特点。
 * 请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
 * 武士在刚降生的时候有一个生命值。
 * 在每个整点，双方的司令部中各有一个武士降生。
 * 红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
 * 蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。
 * 制造武士需要生命元。
 * 制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
 * 如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
 * 给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
 * 一共有两种事件，其对应的输出样例如下：

1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。
 (为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninja，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninja降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士
输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

*/


//设置为对象内static总是报错，故设置为全局变量
const char warriorClassName[5][7] = {"dragon","ninja","iceman","lion","wolf"},sideCode[2][5] = {"red","blue"};

//因为完全改写太麻烦了，基于“魔兽世界之一”的代码加上装备输出部分
class warrior{
    int No,HP;
  //  bool trainSuccess;
public:
    warrior(int  No_,int  HP_,int  baseHP_):No(No_),HP(HP_){
    //    if(baseHP_ >= HP_)
    //        trainSuccess = true;
    //    else
     //       trainSuccess = false;
    };
   // int getNo(){
    //    return this->No;
    //}
    //int getHP(){
    //    return this->HP;
   // }
   // bool getTrainStat(){
    //    return trainSuccess;
  //  }
    string getEquipName(int & equipCode){
        string equipName[3] = {"sword","bomb","arrow"};
        return equipName[equipCode];
    }
    void outputCharacteristic(){};
};

class dragon:public warrior{
    int equipment;
    float morale;
public:
    dragon(int  No_,int  HP_,int  baseHP_):warrior(No_,HP_,baseHP_){
      //  if(getTrainStat()){
            equipment = No_ % 3;
            morale = (baseHP_ - HP_) / (float)HP_;
       // }
      //  else{
      //      equipment = 0;
       //     morale = 0;
      //  }
    };
    void outputCharacteristic(){
        cout << setiosflags(ios::fixed);
        cout << "It has a " << getEquipName(equipment) << ",and it's morale is " <<  setprecision(2) << morale << endl;
    };
};

class ninja:public warrior{
    int equipment[2];
public:
    ninja(int  No_,int  HP_,int  baseHP_):warrior(No_,HP_,baseHP_){
        equipment[0] = No_ % 3;
        equipment[1] = (No_ + 1) % 3;
    }
    void outputCharacteristic(){
        cout << "It has a " << getEquipName(equipment[0]) << " and a " << getEquipName(equipment[1]) << endl;
    };
};

class iceman:public warrior{
    int equipment;
public:
    iceman(int  No_,int  HP_,int  baseHP_):warrior(No_,HP_,baseHP_){
        equipment = No_ % 3;
    }
    void outputCharacteristic(){
        cout << "It has a " << getEquipName(equipment) << endl;
    };
};

class lion:public warrior{
    int loyalty;
public:
    lion(int  No_,int  HP_,int  baseHP_):warrior(No_,HP_,baseHP_){
        loyalty = baseHP_ - HP_;
    }
    void outputCharacteristic(){
        cout << "It's loyalty is " << loyalty << endl;
    };
};

class wolf:public warrior{
public:
    wolf(int & No_,int & HP_,int & baseHP_):warrior(No_,HP_,baseHP_){};
};

class faction{
private:
    //设置为static则链接错误，故设置为普通变量
    int unitClassHP[5],generalNo;
    //factionSide以true~联盟，false~部落来区分
    bool unitTrainningStat;
    int classQuery[5],unitNum[5];
    int baseHP,pointer,factionSide;
    //向建造顺序下一位移动指针
    void pointerSwitch(){
        if(pointer == 4)
            pointer = 0;
        else
            pointer++;
    }
    //检查该兵种是否标记为不可训练状态
    bool statCheck(){
        if(classQuery[pointer] == -1)
            return false;
        else
            return true;
    }
    //检查能否训练士兵
    bool warriorCheck(){
        if(unitClassHP[classQuery[pointer]] <= baseHP)
            return true;
        else{
            classQuery[pointer] = -1;
            return false;
        }
    }
    //开始循环指针，若某一兵种可训练则停在此位置。否则返回“所有兵种都无法训练”
    bool cycling(){
        int count = 0;
        while (!statCheck() || !warriorCheck()){
            count++;
            if(count > 5)
                return false;
            else
                pointerSwitch();
        }
        return true;
    }
    //训练状态输出
    void outputTrainning(int time){
        unitNum[classQuery[pointer]]++;
        cout << setw(3) << setfill('0') << time << ' ' << sideCode[factionSide] << ' '
             << warriorClassName[classQuery[pointer]] << ' ' << generalNo << " born with strength "
             << unitClassHP[classQuery[pointer]] << ',' << unitNum[classQuery[pointer]] << ' '
             << warriorClassName[classQuery[pointer]] << " in " << sideCode[factionSide] << " headquarter" << endl;

        if(classQuery[pointer] == 0){
            dragon tmp(generalNo,unitClassHP[classQuery[pointer]],baseHP);
            tmp.outputCharacteristic();}
        else if(classQuery[pointer] == 1){
            ninja tmp(generalNo,unitClassHP[classQuery[pointer]],baseHP);
            tmp.outputCharacteristic();}
        else if(classQuery[pointer] == 2){
            iceman tmp(generalNo,unitClassHP[classQuery[pointer]],baseHP);
            tmp.outputCharacteristic();}
        else if(classQuery[pointer] == 3){
            lion tmp(generalNo,unitClassHP[classQuery[pointer]],baseHP);
            tmp.outputCharacteristic();}
        else if(classQuery[pointer] == 4){
            wolf tmp(generalNo,unitClassHP[classQuery[pointer]],baseHP);
            tmp.outputCharacteristic();}
        baseHP -= unitClassHP[classQuery[pointer]];
    }
public:
    faction(bool side,int M):baseHP(M),generalNo(0){
        if(side)
            classQuery[0] = 3, classQuery[1] = 0, classQuery[2] = 1,
            classQuery[3] = 2, classQuery[4] = 4,factionSide = 1;
        else
            classQuery[0] = 2, classQuery[1] = 3, classQuery[2] = 4,
            classQuery[3] = 1, classQuery[4] = 0, factionSide = 0;
        unitTrainningStat = true,pointer = 0;
        for (int i = 0; i < 5; ++i) {
            unitNum[i] = 0;
        }
    }
    void setHPList(int dragonHP,int ninjaHP,int icemanHP,int lionHP,int wolfHP){
        unitClassHP[0] = dragonHP; unitClassHP[1] = ninjaHP; unitClassHP[2] = icemanHP;
        unitClassHP[3] = lionHP; unitClassHP[4] = wolfHP;
    }
    bool unitTrainning(int time){
        if(!unitTrainningStat)
            return false;
        else {
            if (!statCheck() || !warriorCheck())
                if (!cycling()){
                    unitTrainningStat = false;
                    cout << setw(3) << setfill('0') << time << ' ' << sideCode[factionSide]
                         << " headquarter stops making warriors" << endl;
                    return false;
                }
            generalNo++;
            outputTrainning(time);
            pointerSwitch();
            return true;
        }
    }
};

int main(){
    int n,i = 1;
    cin >> n;
    while(i <= n){
        int M,HP1,HP2,HP3,HP4,HP5;
        cin >> M;
        cin >> HP1 >> HP2 >> HP3 >> HP4 >> HP5;
        faction red(false,M),blue(true,M);
        red.setHPList(HP1,HP2,HP3,HP4,HP5);
        blue.setHPList(HP1,HP2,HP3,HP4,HP5);
        int time = 0;
        cout << "Case:" << i << endl;
        while(true){
            bool tokenR = red.unitTrainning(time);
            bool tokenB = blue.unitTrainning(time);
            if(!tokenR && !tokenB)
                break;
            time++;
        }
        i++;
    }
    return 0;
};
