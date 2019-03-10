#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

/* 一般的算法显然会到达O(n2)的水平，需要保证滑动窗口内尽可能只算一次
 * 因为SUM = preSum[last] - presum[first-1],所以显然maxSum = maxPreSum-minPreSum
 * 那么可以在一个数组中储存j位置前的最小preSum
 * 亦即，当preSum[j]小于目前最小的preSum值preSum[minPos]时，它就是1~j+1序列中的最小累加和序列1~j
 * 此时maxSum[1~j+1] = preSum[j+1] - preSum[j]，
 * 否则maxSum[1~j+1] = preSum[j+1] - preSum[minPos]，保存每个1~j序列对应的minPos即可
 */

int main()
{
    int T;
    cin >> T;
    for(int i=1;i <= T;i++){
        int n,minP = 0,minPSum = 0;
        cin >> n;
        vector<int> preSum(n+1);
        vector<int> minpreSumPos(n+2);
        preSum[0] = 0;
        minpreSumPos[0] = minpreSumPos[1] = 0;
        for(int j = 1;j < n+1;j++){
            int temp;
            scanf("%d",&temp);
            preSum[j] = temp + preSum[j-1];
            if(preSum[j] < minPSum){
                minPSum = preSum[j];
                minpreSumPos[j+1] = j;
                minP = j;
            }
            else{
                minpreSumPos[j+1] = minP;
            }
        }
        int maxSum = -0x30303030,lb = 0,rb = 0;
        for(int k = 1;k < n+1;k++){
            int maxSeqSum = preSum[k] - preSum[minpreSumPos[k]];
            if(maxSeqSum > maxSum){
                lb = minpreSumPos[k] + 1;
                rb = k;
                maxSum = maxSeqSum;
            }
        }
        if(i > 1)printf("\n");
        cout << "Case " << i << ":" << endl;
        cout << maxSum << ' ' << lb << ' ' << rb << endl;
    }
    return 0;
}
