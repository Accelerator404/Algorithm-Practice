#include <iostream>
#include <vector>
#include <set>
using namespace std;

//PAT Advanced Level 1143 Lowest Common Ancestor

/*
 * 考虑平衡二叉树中情形：
 * 1.u,v均在共同祖先左枝或右枝，则可以从此侧再下一层，继续判断；
 * 2.u,v互为祖先，退出；
 * 3.u,v分别在共同祖先左侧与右侧，此时没有更深层的共同祖先，退出；
 * 所以实际上只有2，3两种情况；
 * 先序遍历+二叉树，意味着只要某root a满足a<u&&a>v||a>v&&a<u，就肯定是最低共同祖先，因为此时u,v在两侧不能再往下
 * 遍历时肯定先节点再左子树右子树，排除了不符合以上判别式的反例
 */


int main() {
    int M,N;
    cin >> M >> N;
    set<int> nodeSet;
    vector<int> pre;
    for (int i = 0; i < N; ++i) {
        int u;
        scanf("%d",&u);
        pre.push_back(u);
        nodeSet.insert(u);
    }
    for (int i = 0; i < M; ++i) {
        int u,v,a;
        scanf("%d%d",&u,&v);
        for (int j = 0; j < N; ++j) {
            a=pre[j];
            if((a>=u&&a<=v)||(a>=v&&a<=u)){
                break;
            }
        }
        if(nodeSet.count(u) && !nodeSet.count(v)){
            printf("ERROR: %d is not found.\n",v);
            continue;
        }
        else if(!nodeSet.count(u) && nodeSet.count(v)) {
            printf("ERROR: %d is not found.\n", u);
            continue;
        }
        else if(!nodeSet.count(u) && !nodeSet.count(v)){
            printf("ERROR: %d and %d are not found.\n",u,v);
            continue;
        }
        if(a == u){
            printf("%d is an ancestor of %d.\n",a,v);
        }
        else if(a == v){
            printf("%d is an ancestor of %d.\n",a,u);
        }
        else{
            printf("LCA of %d and %d is %d.\n",u,v,a);
        }
    }
    return 0;
}
