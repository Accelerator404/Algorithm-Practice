#include <iostream>
#include <iomanip>
using namespace std;

/**
分配病房

描述
某个科室的病房分为重症和普通，只有当病人的疾病严重程度超过了入住重症病房的最低严重值，才可以安排入住重症病房。
现在要求设计一个程序，给病人安排好病房。疾病的严重程度用0到10来表示，0表示小毛病，10表示非常严重。

输入
第一行输入病人的个数m(m < 50)，以及安排住入重症病房的最低严重值a
紧接着m行，每行表示病人编号（三个位，用0补齐）及其疾病的严重程度（浮点数，1位小数）。
每个病人的疾病严重程度都不一样。

输出
要求按照病人的严重程度输出住在重症病房里的病人的编号
注意：如果当前所有病人的严重程度并不满足住在重症病房里，则输出“None.”（不包括引号）

*/


int main() {
    //为通过oj编译，直接设定数组范围为上限50人
    int m,patient[50] = {0};
    float emergency[50] = {0.0},a;
    cin >> m >> a;
    for (int i = 0;i < m;i++){
        cin >> patient[i] >> emergency[i];
    }
    //传统的冒泡排序
    for(int i = 0;i < m - 1;i++){
        for(int j = i + 1;j < m;j++){
            if(emergency[i] < emergency[j]){
                float temp = emergency[j];
                emergency[j] = emergency[i];
                emergency[i] = temp;
                int temp2 = patient[j];
                patient[j] = patient[i];
                patient[i] = temp2;
            }
        }
    }
    if(emergency[0] < a){
        cout << "None." << endl;
    }
    //格式输出
    else{
        cout.setf(ios::fixed);
        for(int i = 0;emergency[i] >= a;i++){
            cout << setw(3) << setfill('0') << patient[i] << " " << setprecision(1) << emergency[i] << endl;
        }
    }
    return 0;
}
