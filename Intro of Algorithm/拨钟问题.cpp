#include <iostream>
using namespace std;

/**
 * 拨钟问题
 * 描述
 * 有9个时钟，排成一个3*3的矩阵。
 *      |-------|    |-------|    |-------|
        |       |    |       |    |   |   |
        |---O   |    |---O   |    |   O   |
        |       |    |       |    |       |
        |-------|    |-------|    |-------|
            A            B            C
        |-------|    |-------|    |-------|
        |       |    |       |    |       |
        |   O   |    |   O   |    |   O   |
        |   |   |    |   |   |    |   |   |
        |-------|    |-------|    |-------|
            D            E            F
        |-------|    |-------|    |-------|
        |       |    |       |    |       |
        |   O   |    |   O---|    |   O   |
        |   |   |    |       |    |   |   |
        |-------|    |-------|    |-------|
            G            H            I
                       (图 1)
 * 现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。共允许有9种不同的移动。
 * 如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
    移动    影响的时钟
    1        ABDE
    2        ABC
    3        BCEF
    4        ADG
    5        BDEFH
    6        CFI
    7        DEGH
    8        GHI
    9        EFHI
       (图 2)
 *
 *
 * 输入
 * 从标准输入设备读入9个整数，表示各时钟指针的起始位置。0=12点、1=3点、2=6点、3=9点。
 *
 * 输出
 * 输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号大小，输出结果。
 *
 */

//1.操作的顺序不影响结果
//2.任一操作重复4次后便回到操作前状态，故9种操作每个至多执行3次，有0~3四种情况
//故可以考虑以下解法了
//1.暴力枚举，9层循环
//2.9元1次方程组
//因为屋子里实在太冷了，为了快点写完躲回床上，我选择暴力法。

int clocks[9];
int tempSteps[9],steps[9];
int minStepsCount = -1;
void doMovement(int No,int count){
    int countI = count;
    while (--countI >= 0){
        switch(No){
            case 1:clocks[0]++;clocks[1]++;clocks[3]++;clocks[4]++;break;
            case 2:clocks[0]++;clocks[1]++;clocks[2]++;break;
            case 3:clocks[1]++;clocks[2]++;clocks[4]++;clocks[5]++;break;
            case 4:clocks[0]++;clocks[3]++;clocks[6]++;break;
            case 5:clocks[1]++;clocks[3]++;clocks[4]++;clocks[5]++;clocks[7]++;break;
            case 6:clocks[2]++;clocks[5]++;clocks[8]++;break;
            case 7:clocks[3]++;clocks[4]++;clocks[6]++;clocks[7]++;break;
            case 8:clocks[6]++;clocks[7]++;clocks[8]++;break;
            case 9:clocks[4]++;clocks[5]++;clocks[7]++;clocks[8]++;break;
            default:;
        }
    }
    for (int i = 0; i < 9; ++i) {
        clocks[i] %= 4;
    }
    tempSteps[No - 1] = count;
}

bool check(){
    for (int i = 0; i < 9; ++i) {
        if(clocks[i] != 0)
            return false;
    }
    return true;
}

void cal(){
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += tempSteps[i];
    }
    if(sum > 0 && minStepsCount < 0 || sum > 0 && minStepsCount > sum){
        for (int i = 0; i < 9; ++i)
            steps[i] = tempSteps[i];
        minStepsCount = sum;
    }
}

void output(){
    for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < steps[i]; ++j)
                cout << i + 1 << ' ';
    }
}

int main() {
    int clockInput[9];
    for (int i = 0; i < 9; ++i) {
        cin >> clockInput[i];
    }
    for (int j = 0; j < 4; ++j) {
        for (int i = 0; i < 4; ++i) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 4; ++m) {
                        for (int n = 0; n < 4; ++n) {
                            for (int i1 = 0; i1 < 4; ++i1) {
                                for (int j1 = 0; j1 < 4; ++j1) {
                                    for (int k1 = 0; k1 < 4; ++k1) {
                                        for (int l1 = 0; l1 < 9; ++l1) {
                                            clocks[l1] = clockInput[l1];
                                        }
                                        doMovement(1,j);
                                        doMovement(2,i);
                                        doMovement(3,k);
                                        doMovement(4,l);
                                        doMovement(5,m);
                                        doMovement(6,n);
                                        doMovement(7,i1);
                                        doMovement(8,j1);
                                        doMovement(9,k1);
                                        if(check())
                                            cal();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    output();
    return 0;
}
