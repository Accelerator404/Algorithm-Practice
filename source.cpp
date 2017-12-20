#include <iostream>
using namespace std;
//约瑟夫问题
//有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ）
//从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。
//就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。
//猴子最大300只，环形排列
int nextMonkey[300];
int previousMonkey[300];

int main() {
    int n,m;
    while (true){
        cin >>n>>m;
        if (n==0&&m==0)
            break;
        for (int i=0;i< n - 1;i++){
            nextMonkey[i] = i+1;
            previousMonkey[i +1] = i;
        }
        nextMonkey[n-1] = 0;
        previousMonkey[0] = n-1; //将猴子序号环形排列
        //开始报数循环
        int currentMonkey = 0;
        while(true){
            for (int count = 0;count < m-1;count++)
                currentMonkey = nextMonkey[currentMonkey];//报m-1次next后便是报第m次号的要退出的猴子

            int pre = previousMonkey[currentMonkey];
            int next = nextMonkey[currentMonkey];
            nextMonkey[pre] = next;//将退出猴子的前一只猴子的下一位改成退出猴子的下一位
            previousMonkey[next] = pre;//将退出猴子的后一只猴子的前一位改成退出猴子的前一位
            //以上便剔出了currentMonkey位的猴子
            if (pre == next){//仅有一只猴子了
                cout << pre + 1 <<endl;//输出时序号需要加一
                break;
            }
            currentMonkey = next; //内部存储的猴王序号
        }
    }
    return 0;
}