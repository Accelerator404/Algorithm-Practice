#include <iostream>
using namespace std;

//细菌实验分组
//有一种细菌分为A、B两个亚种，它们的外在特征几乎完全相同，仅仅在繁殖能力上有显著差别，
//A亚种繁殖能力非常强，B亚种的繁殖能力很弱。
//在一次为时一个 小时的细菌繁殖实验中，实验员由于疏忽把细菌培养皿搞乱了，
//请你编写一个程序，根据实验结果，把两个亚种的培养皿重新分成两组。
//输入：输入有多行，第一行为整数n（n≤100），表示有n个培养皿。
//其余n行，每行有三个整数，分别代表培养皿编号，试验前细菌数量，试验后细菌数量。
//输出：输出有多行：
//第一行输出A亚种培养皿的数量，其后每行输出A亚种培养皿的编号，按繁殖率升序排列。
//然后一行输出B亚种培养皿的数量，其后每行输出B亚种培养皿的编号，也按繁殖率升序排列。

double ratio(int a,int b){
    double c;
    c = (double)a / (double)b;
    return c;
}
//冒泡排序（包括序号重排）
void bubble(int k,int no[100], double num[100]){
    for (int i = 0; i < k; i++) {
        for (int j = k - 1; j > i; j--) {
            if (num[j] > num[j - 1]) {
                double temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
                int temp2 = no[j - 1];
                no[j - 1] = no[j];
                no[j] = temp2;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int no[n],data[2][n];
    double reRate[n];
    for (int i = 0; i < n;i++){
        cin >> no[i] >> data[0][i] >> data [1][i];
        reRate[i] = ratio(data[1][i],data[0][i]);
    }

    bubble(n,no,reRate);
    double maxDiff = 0; //最大差值
    int markDiff = 0;  //最大差值的下标
    for(int i = 0;i < n - 1;i++){
        if(reRate[i] - reRate[i + 1] > maxDiff){
            maxDiff = reRate[i] - reRate[i + 1];
            markDiff = i;
        }
    }

    cout << (markDiff + 1) << endl;
    for (int i = markDiff; i >= 0;i--){
        cout << no[i] << endl;
    }

    cout << (n - 1 - markDiff) << endl;
    for (int i = n - 1; i > markDiff;i--){
        cout << no[i] << endl;
    }
    return 0;
}
