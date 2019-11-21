#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

/*
 * ZJU Data Structure Mooc 19 Fall
 * 03-树1 树的同构
 * 给定两棵树T1和T2。如果T1可以通过若干次左右孩子互换就变成T2，则我们称两棵树是“同构”的。例如图1给出的两棵树就是同构的，
 * 因为我们把其中一棵树的结点A、B、G的左右孩子互换后，就得到另外一棵树。而图2就不是同构的。
 * 现给定两棵树，请你判断它们是否是同构的。
 *
 * 输入格式:
 * 输入给出2棵二叉树树的信息。对于每棵树，首先在一行中给出一个非负整数N (≤10)，即该树的结点数（此时假设结点从0到N−1编号）；
 * 随后N行，第i行对应编号第i个结点，给出该结点中存储的1个英文大写字母、其左孩子结点的编号、右孩子结点的编号。
 * 如果孩子结点为空，则在相应位置上给出“-”。给出的数据间用一个空格分隔。
 * 注意：题目保证每个结点中存储的字母是不同的。
 *
 * 输出格式:
 * 如果两棵树是同构的，输出“Yes”，否则输出“No”。
 */

// 使用带深度信息的节点
// 节点数N<10

struct taggedNode{
    char data;
    int No;
    int lcNo,rcNo; // 存储的子节点编号是输入的第i个节点，与实际二叉树存储位置无关
    int depth;
};

class BT{
private:
    vector<taggedNode> data;
    int nodeCount;
public:
    BT(){
        nodeCount = 0;
    }
    static taggedNode getNode(int No){
        taggedNode tmp;
        char a;
        string l,r;
        cin >> a >> l >> r;
        tmp.data = a;
        tmp.lcNo = (l == "-"?-1:stoi(l));
        tmp.rcNo = (r == "-"?-1:stoi(r));
        tmp.No = No;
        tmp.depth = 0;
        return tmp;
    }
    bool checkEntity(){
        int count = 0;
        for(int i = 0;i < nodeCount;i++){
            if(data[i].depth == 0){
                count++;
            }
        }
        return count == 1;
    }
    void buildTree(int inputCount){
        // 读入所有节点
        nodeCount = inputCount;
        if(inputCount < 1)
            return;
        data.resize(inputCount);
        for (int i = 0; i < inputCount; ++i) {
            data[i] = getNode(i);
        }
        // 分析层级关系,子节点深度为根节点深度加1
        int maxcount = nodeCount;
        while (!checkEntity() || maxcount-- > 0){
            int opCount = 0;
            // 如果某节点的子节点的深度不满足==(该节点深度+1),则进行调整操作一次
            for (int i = 0; i < nodeCount; ++i) {
                if(data[i].lcNo != -1 && data[data[i].lcNo].depth != data[i].depth+1){
                    data[data[i].lcNo].depth = data[i].depth + 1;
                    opCount++;
                }
                if(data[i].rcNo != -1 && data[data[i].rcNo].depth != data[i].depth+1){
                    data[data[i].rcNo].depth = data[i].depth + 1;
                    opCount++;
                }
            }
            if(opCount == 0)
                break;
        }
        // 循环结束后各节点深度确定,唯一的深度为0的节点就是根节点
    }
    taggedNode* find(char d){
        for (int i = 0; i < nodeCount; ++i) {
            if(data[i].data == d){
                taggedNode* result = new taggedNode(data[i]);
                return result;
            }
        }
        return nullptr;
    }
    bool compare(BT & otherTree){
        // 需要比较：各节点层级相同，根节点-子节点关系相同
        if(nodeCount != otherTree.nodeCount)
            return false;
        for (int i = 0; i < nodeCount; ++i) {
            taggedNode* sameNode = otherTree.find(data[i].data);
            if(sameNode == nullptr)
                return false;
            if(data[i].depth != sameNode->depth)
                return false;
            // 分析两个节点的子节点是否相同
            char T1L = (data[i].lcNo == -1)?'-':data[data[i].lcNo].data;
            char T1R = (data[i].rcNo == -1)?'-':data[data[i].rcNo].data;
            char T2L = (sameNode->lcNo == -1)?'-':otherTree.data[sameNode->lcNo].data;
            char T2R = (sameNode->rcNo == -1)?'-':otherTree.data[sameNode->rcNo].data;
            if((T1L!=T2L && T1L!= T2R) || (T1R!=T2L && T1R!=T2R))
                return false;
            delete(sameNode);
        }
        return true;
    }
};

int main(){
    BT T1,T2;
    int count;
    cin >> count;
    T1.buildTree(count);
    cin >> count;
    T2.buildTree(count);
    cout << (T1.compare(T2)?"Yes":"No") << endl;
    return 0;
}