#include <iostream>
#include <vector>
using namespace std;

//PAT Advanced Level 1043 Is It a Binary Search Tree

/* 递归：因为BST满足左子树<root<右子树，所以遍历前序遍历序列，比root大的就是它的右子树
 * 由此可以确定每个根节点的左右子树，从而将前序遍历转换为后序遍历，
 * 如果转换出的后序序列没有输入序列大，说明不是BST，按照镜像BST再生成一次后序遍历序列
 * 这时候还没有输入序列大，就说明输入序列不是BST/Mirror的先序遍历
 */

 void getPostTra(int root,int seqTail,const vector<int> & pre,vector<int> & post,const bool & isMirror){
    if(root > seqTail)
        return;
    int i = root+1,j = seqTail;
    if(!isMirror){
        while(i <= seqTail && pre[root] > pre[i])
            i++;
        while(j > root && pre[root] <= pre[j])
            j--;
    }
    else{
        while(i <= seqTail && pre[root] <= pre[i])
            i++;
        while(j > root && pre[root] > pre[j])
            j--;
    }
    //此时i是右子树左界，j是左子树右界，二者应当相邻，否则说明这个是叶节点
    if(i-j != 1)
        return;
    getPostTra(root+1,j,pre,post,isMirror);
    getPostTra(i,seqTail,pre,post,isMirror);
    post.push_back(pre[root]);
 }

int main() {
    int N;
    bool isMirror = false;
    cin >> N;
    vector<int> preTra(N),postTra;
    for(int i = 0;i < N;i++){
        scanf("%d",&preTra[i]);
    }
    getPostTra(0,N-1,preTra,postTra,isMirror);
    if(postTra.size() != preTra.size()){
        isMirror = true;
        postTra.clear();
        getPostTra(0,N-1,preTra,postTra,isMirror);
    }
    if(postTra.size() == preTra.size()){
        cout << "YES" << endl;
        for(int i = 0;i < N;i++){
            if(i > 0)
                cout << ' ';
            printf("%d",postTra[i]);
        }
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
