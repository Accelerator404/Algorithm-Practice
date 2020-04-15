#include <iostream>

using namespace std;

/*
 * 洛谷 P1540 机器翻译
 */

int main() {
    bool wordInMem[1010] = {false};
    int addSeqLinkList[1010] = {-1};
    int oldestWord = -1;
    int newestWord = -1;
    int wordInMemCount = 0;
    int swapCount = 0;
    int M, N;
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        int word;
        scanf("%d", &word);
        if (wordInMem[word])
            continue;
        // 处理最早单词剔除，维护加入内存顺序链表
        if (wordInMemCount >= M) {
            int t = oldestWord;
            oldestWord = addSeqLinkList[oldestWord];
            addSeqLinkList[t] = -1;
            wordInMem[t] = false;
        } else {
            wordInMemCount++;
        }
        swapCount++;
        wordInMem[word] = true;
        // 维护加入内存顺序链表
        if (newestWord >= 0) {
            // 添加最新单词（链表头删尾插）
            addSeqLinkList[newestWord] = word;
        } else {
            // 第一次查外存时，最早词指针指向该单词
            oldestWord = word;
        }
        newestWord = word;
    }
    cout << swapCount;
    return 0;
}