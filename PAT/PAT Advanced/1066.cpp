#include <iostream>
#include <vector>
using namespace std;

/*
 * PAT (Advanced Level) 1066 Root of AVL Tree
 *
 * An AVL tree is a self-balancing binary search tree. In an AVL tree,
 * the heights of the two child subtrees of any node differ by at most one;
 * if at any time they differ by more than one, rebalancing is done to restore this property.
 * Figures 1-4 illustrate the rotation rules.Now given a sequence of insertions,
 * you are supposed to tell the root of the resulting AVL tree.
 *
 * 输入格式:
 * Each input file contains one test case.
 * For each case, the first line contains a positive integer N (≤20) which is the total number of keys to be inserted.
 * Then N distinct integer keys are given in the next line. All the numbers in a line are separated by a space.
 *
 * 输出格式:
 * For each test case, print the root of the resulting AVL tree in one line.
 */
// 实现一棵AVL树，插入序列再输出根节点即可

#define BalFac(x) (stature((x)->lc) - stature((x)->rc))

struct node{
    node *lc,*rc;
    int data;
};

unsigned stature(node* root){   // 获取该二叉树的高度
    if(root == nullptr)
        return 0;
    return max(stature(root->lc),stature(root->rc)) + 1;
}

node *LRotate(node *root){
    node *nr = root->rc;
    root->rc = nr->lc;
    nr->lc = root;
    return nr;
}

node *RRotate(node *root){
    node *nr = root->lc;
    root->lc = nr->rc;
    nr->rc = root;
    return nr;
}

node *LRRotate(node *root){
    root->lc = LRotate(root->lc);
    return RRotate(root);
}

node *RLRotate(node *root){
    root->rc = RRotate(root->rc);
    return LRotate(root);
}

node *insert(node *root,int val){
    if(root == nullptr){
        root = new node();
        root->data = val;
        root->lc = nullptr;
        root->rc = nullptr;
    }
    else if(val < root->data){
        root->lc = insert(root->lc,val);
        if(BalFac(root) == 2)
            root = (val < root->lc->data)?RRotate(root):LRRotate(root);
    }
    else{
        root->rc = insert(root->rc,val);
        if(BalFac(root) == -2)
            root = (val > root->rc->data)?LRotate(root):RLRotate(root);
    }
    return root;
}

int main(){
    int N;
    cin >> N;
    node *AVL = nullptr;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        AVL = insert(AVL,t);
    }
    cout << AVL->data << endl;
    return 0;
}