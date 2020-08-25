#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//PAT Advanced 1020 Tree Traversals

/*
 * 注意，根据两种遍历方式确定二叉树的过程，本身就是从根节点到下层一层层进行的
 * 所以不需要构造二叉树进行BFS
 */

vector<int> postOrderTraversal,inOrderTraversal,levelOrderTraversal(100000,-1);

void getRootPosition(int root,int start,int end,int index){ //root为当前根节点在后序遍历的下标
    if(start > end)
        return;
    int it = start;
    //找到中序遍历根节点下标
    while(it < end && inOrderTraversal[it] != postOrderTraversal[root]) it++;
    levelOrderTraversal[index] = postOrderTraversal[root];
    getRootPosition(root - 1 - end + it,start,it - 1, 2 * index + 1);
    getRootPosition(root - 1,it + 1,end,2 * index + 2);
}

int main(){
    int N;
    cin >> N;
    postOrderTraversal.resize(N);inOrderTraversal.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> postOrderTraversal[i];
    for (int i = 0; i < N; ++i)
        cin >> inOrderTraversal[i];
    getRootPosition(N-1,0,N-1,0);
    bool first = true;
    for (int i = 0; i <= levelOrderTraversal.size(); ++i) {
        if(!first && levelOrderTraversal[i] > 0)
            cout << ' ';
        else
            first = false;
        if(levelOrderTraversal[i] > 0 )
            cout << levelOrderTraversal[i];
        else if(levelOrderTraversal[i] == 0)
            break;
    }
    return 0;
}
