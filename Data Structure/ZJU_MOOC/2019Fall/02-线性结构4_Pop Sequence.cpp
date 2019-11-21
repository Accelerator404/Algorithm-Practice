#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
 * ZJU Data Structure Mooc 19 Fall
 * 02-线性结构4 Pop Sequence
 * Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop randomly.
 * You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.
 * For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
 *
 * 输入格式:
 * Each input file contains one test case. For each case, the first line contains 3 numbers (all no more than 1000):
 * M (the maximum capacity of the stack),
 * N (the length of push sequence),
 * and K (the number of pop sequences to be checked).
 * Then K lines follow, each contains a pop sequence of N numbers.
 * All the numbers in a line are separated by a space.
 *
 * 输出格式:
 * For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
 */

int main(){
    int M,N,K;
    cin >> M >> N >> K;
    for (int p = 0; p < K; ++p) {
        vector<int> inputSeq(N+1);
        stack<int> emuStack;
        for (int i = 1; i <= N; ++i)
            scanf("%d",&inputSeq[i]);
        int curr = 1;
        for (int i = 1; i <= N; ++i) {
            emuStack.push(i);
            // 如果栈满了，但是栈顶数仍然与序列的下一个数不一样，则该输出序列无法满足
            if(emuStack.size() > M)
                break;
            // 只要栈顶=弹出序列当前数，就一直弹出直到不满足条件，再进入下一个入栈循环
            while (!emuStack.empty() && emuStack.top() == inputSeq[curr]){
                emuStack.pop();
                curr++;
            }
        }
        if(curr == N+1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}