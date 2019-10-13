#include <iostream>
#include <iomanip>
using namespace std;

//发票统计
//有一个小型的报账系统，它有如下功能：
//（1）统计每个人所报发票的总钱数
//（2）统计每类发票的总钱数
//将此系统简化为如下：假设发票类别共有A、B、C三种;一共有三个人，ID分别为1、2、3。
//输入：系统输入包含三行，每行第一个数为人员ID（整型，1或2或3），第二个数为发票总张数(张数不超过100)，
//之后是多个发票类别（字符型，A或B或C）和相应发票金额（单进度浮点型,不超过1000.0）。。
//输出：输出包含六行，前三行为每人（按ID由小到大输出）所报发票总钱数（保留两位小数），
//后三行为每类发票的总钱数（保留两位小数）。


//按人统计
float personalSum(int a,float amount[3][100]){  //按人统计
    float sum = 0.0;
    for (int i = 0; i < 100; i++){
        sum += amount[a][i];
    }
    return sum;
}
//按发票类型统计
float typeSum(char a, float amount[3][100],char type[3][100]){  //按发票类型统计
    float sum = 0.0;
    for (int i = 0;i < 3; i++){
        for (int j = 0 ;j < 100; j++){
            if(type[i][j] == a){
                sum += amount[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int no,num;
    float ticketAmount[3][100] = {0};
    char ticketType[3][100] = {'\0'};
    for (int i = 0; i < 3;i++){
        cin >> no >> num;
        no--;
        for (int j = 0;j < num ; j++){
            cin >> ticketType[no][j] >> ticketAmount[no][j];
        }
    }


    cout << "1 " << fixed << setprecision(2) << personalSum(0,ticketAmount) << endl;
    cout << "2 " << fixed << setprecision(2) << personalSum(1,ticketAmount) << endl;
    cout << "3 " << fixed << setprecision(2) << personalSum(2,ticketAmount) << endl;
    cout << "A " << fixed << setprecision(2) << typeSum('A',ticketAmount,ticketType) << endl;
    cout << "B " << fixed << setprecision(2) << typeSum('B',ticketAmount,ticketType) << endl;
    cout << "C " << fixed << setprecision(2) << typeSum('C',ticketAmount,ticketType) << endl;
    return 0;
}
