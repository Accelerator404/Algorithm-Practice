#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//PAT Advanced Level 1033 To Fill or Not to Fill

struct gasStation{
    double price,dist;
};

const int INF = 99999999;

bool compare(gasStation A,gasStation B){
    return A.dist < B.dist;
}

int main() {
    double Cmax,D,Davg;
    int N;
    cin >> Cmax >> D >> Davg >> N;
    const int maxSingleD = Davg * Cmax;
    vector<gasStation> gsList;
    for(int i = 0; i < N ;i++){
        double a, b;
        scanf("%lf%lf",&a,&b);
        gsList.push_back({a,b});
    }
    gsList.push_back({0,D});
    sort(gsList.begin(),gsList.end(),compare);
    //leftDis是在某加油站时候的剩余油量可行驶距离
    double thisPrice = 0.0,totalCost = 0.0,nowDis = 0.0,maxDis = 0.0,leftDis = 0.0;
    if(gsList[0].dist != 0){
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    else{
        thisPrice = gsList[1].price;
    }
    while(nowDis < D){
        maxDis = nowDis + maxSingleD; //当前行程极限，用以匹配可到达的加油站
        double minPriceDis = 0.0,minPrice = INF;
        bool existCheaper = false;
        for(int i = 1; i <= N && gsList[i].dist <= maxDis;i++){
            if(gsList[i].dist <= nowDis)
                continue;
            //贪心算法：找到最近的比当前加油站便宜的加油站，就加上刚好够过去的油去那儿
            if(gsList[i].price < thisPrice){
                totalCost += (gsList[i].dist - nowDis - leftDis)*thisPrice / Davg;
                leftDis = 0.0;
                thisPrice = gsList[i].price;
                nowDis = gsList[i].dist;//正好到目标加油站，进行下一轮
                existCheaper = true;
                break;
            }
            //不比当前加油站便宜，就寻找可抵达范围内最便宜的加油站
            if(gsList[i].price < minPrice){
                minPrice = gsList[i].price;
                minPriceDis = gsList[i].dist;
            }
        }
        //有可抵达的加油站，加满再过去
        if(!existCheaper && minPrice != INF){
            totalCost += thisPrice * (Cmax - leftDis/Davg);
            leftDis = maxSingleD - (minPriceDis - nowDis);
            thisPrice = minPrice;
            nowDis = minPriceDis;
        }
        else if(!existCheaper && minPrice == INF){
            nowDis += maxSingleD;
            printf("The maximum travel distance = %.02f\n",nowDis);
            return 0;
        }
    }
    printf("%.02f\n",totalCost);
    return 0;
}
