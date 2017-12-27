#include <iostream>
using namespace std;

//四大湖
//我国有4大淡水湖。
//A说：洞庭湖最大，洪泽湖最小，鄱阳湖第三。
//B说：洪泽湖最大，洞庭湖最小，鄱阳湖第二，太湖第三。
//C说：洪泽湖最小，洞庭湖第三。
//D说：鄱阳湖最大，太湖最小，洪泽湖第二，洞庭湖第三。
//已知这4个湖的大小均不相等，4个人每人仅答对一个，
//请编程按照鄱阳湖、洞庭湖、太湖、洪泽湖的顺序给出他们的大小排名。
//输入：无。
//输出：输出为4行，第1行为鄱阳湖的大小名次，从大到小名次分别表示为1、2、3、4；
//第2、3、4行分别为洞庭湖、太湖、洪泽湖的大小名次。

bool judge(int a, int b, int c, int d, int e, int f, int g, int h){ //a-d为尝试序列，e-h为当前人的答案
    int i = 0;
    if (a == e) i++;
    if (b == f) i++;
    if (c == g) i++;
    if (d == h) i++;

    if(i == 1)
        return true;
    else
        return false;
}

int main() {
    int lake[4] = {0};//依此为鄱阳湖、洞庭湖、太湖、洪泽湖
    for (int i = 1; i < 5;i++){
        for (int j = 1; j < 5;j++){
            if(j == i) continue;
            for (int k = 1; k < 5;k++){
                if(k == i) continue;
                else if(k == j) continue;
                for (int l = 1; l < 5;l++){
                    if(l == i) continue;
                    else if(l == j) continue;
                    else if(l == k) continue;
                    if(judge(i,j,k,l,3,1,0,4) && judge(i,j,k,l,2,4,3,1)
                       && judge(i,j,k,l,0,3,0,4) && judge(i,j,k,l,1,3,4,2)){
                        lake[0] = i;
                        lake[1] = j;
                        lake[2] = k;
                        lake[3] = l;
                        goto exit;
                    }
                }
            }
        }
    }
exit:
    for (int i = 0; i < 4;i++){
        cout << lake[i] << endl;
    }
    return 0;
}
