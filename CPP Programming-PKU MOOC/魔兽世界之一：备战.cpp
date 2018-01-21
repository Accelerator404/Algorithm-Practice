#include <iostream>
#include <iomanip>
using namespace std;

/**
 * 魔兽世界之一：备战
 *
 * 描述：
 *
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

//设置为对象内static总是报错，故设置为全局变量
const char warriorClassName[5][7] = {"dragon","ninja","iceman","lion","wolf"},sideCode[2][5] = {"red","blue"};

class faction{
private:
    //设置为static则链接错误，故设置为普通变量
    int unitClassHP[5];
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
        baseHP -= unitClassHP[classQuery[pointer]];
        unitNum[classQuery[pointer]]++;
        cout << setw(3) << setfill('0') << time << ' ' << sideCode[factionSide] << ' '
             << warriorClassName[classQuery[pointer]] << ' ' << time + 1 << " born with strength "
             << unitClassHP[classQuery[pointer]] << ',' << unitNum[classQuery[pointer]] << ' '
             << warriorClassName[classQuery[pointer]] << " in " << sideCode[factionSide] << " headquarter"
             << endl;
    }
public:
    faction(bool side,int M):baseHP(M){
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
