#include <iostream>
#include <vector>
using namespace std;

void buildBST(vector<int> & PostOrder,vector<int> & MidOrder){
    if(PostOrder.size() == 0 || MidOrder.size() == 0 || PostOrder.size() != MidOrder.size()){
        return;
    }
    int root = PostOrder[PostOrder.size()-1];
    int div = -99;
    for (int i = 0; i < MidOrder.size(); ++i) {
        if(MidOrder[i] == root){
            div = i;
            break;
        }
    }
    cout << ' ' << root;
    vector<int> lPost,lMid,rPost,rMid;
    int Llen = div;
    int Rlen = MidOrder.size() - (div+1);
    for (int i = 0; i < Llen; ++i) {
        lPost.push_back(PostOrder[i]);
        lMid.push_back(MidOrder[i]);
    }
    for (int i = div+1; i < MidOrder.size(); ++i) {
        rMid.push_back(MidOrder[i]);
    }
    for (int i = Llen; i < PostOrder.size()-1; ++i) {
        rPost.push_back(PostOrder[i]);
    }
    buildBST(lPost,lMid);
    buildBST(rPost,rMid);
}

int main(){
    int n;
    vector<int> PostOrder,MidOrder;
    cin >> n;
    PostOrder.resize(n);
    MidOrder.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> PostOrder[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> MidOrder[i];
    }
    cout << "Preorder:";
    buildBST(PostOrder,MidOrder);
    return 0;
}