#include <iostream>
#include <iomanip>

using namespace std;
//年龄与疾病
//某医院想统计一下某项疾病的获得与否与年龄是否有关，需要对以前的诊断记录进行整理。
//输入：共2行，第一行为过往病人的数目n（0 < n <= 100)，第二行为每个病人患病时的年龄。
//输出：每个年龄段（分四段：18以下，19-35，36-60，大于60的输出是“60-: ”而不是“61-: ”）的患病人数占总患病人数的比例
// 以百分比的形式输出，精确到小数点后两位（double）。
int main() {
    //输入
    int n;
    double token1 = 0,token2 = 0,token3 = 0,token4 = 0;//似乎不能用int型相除得到double型
    cin >> n;
    int age[n];
    for (int i = 0;i <n ; i++){
        cin >> age[i];
        if (age[i] <= 18)
            token1++;
        else if (age[i] > 18 && age[i] <= 35)
            token2++;
        else if (age[i] > 35 && age[i] <= 60)
            token3++;
        else if (age[i] > 60)
            token4++;
    }
    //计算比率
    token1 = token1 / n * 100.00;
    token2 = token2 / n * 100.00;
    token3 = token3 / n * 100.00;
    token4 = token4 / n * 100.00;
    //输出
    cout << "1-18: " << fixed << setprecision(2) << token1 << '%' << endl;
    cout << "19-35: " << fixed << setprecision(2) << token2 << '%' << endl;
    cout << "36-60: " << fixed << setprecision(2) << token3 << '%' << endl;
    cout << "60-: " << fixed << setprecision(2) << token4 << '%' << endl;
    return 0;
}
