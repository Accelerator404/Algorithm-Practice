#include<cstdio>
#include<vector> 
#include<algorithm>
using namespace std;
//PATest Basic Level : No.

struct node {
	int add, data, next;
};

int main() {
	vector<node> orig(100000);    //用来存储输入的数据 (因为输入的时候要直接用orig[n]，所以要先开足够大的副本)  
	vector<node> list;        //用来存储排列好的数据(未反转)  
	vector<node> ans;     //用来存储翻转后的顺序   

	int first, n, k;
	scanf("%d%d%d", &first, &n, &k);
	node temp;

	//数据输入的顺序   
	for (int i = 0; i<n; i++) {
		scanf("%d%d%d", &temp.add, &temp.data, &temp.next);
		orig[temp.add] = temp;
	}
	//更新数据的顺序   
	while (first != -1) {
		list.push_back(orig[first]);
		first = orig[first].next;
	}
	//数据的个数(n和n2可能会不同)   
	int n2 = list.size();
	//更新反转后的顺序   
	for (int i = 0; i <= n2-k; i += k) {
		reverse(list.begin() + i, list.begin() + i + k);
	}
	for (int i = 0; i < n2; i++) {
		node tmp = list[i];
		if (i != n2 - 1)
			tmp.next = list[i + 1].add;
		else
			tmp.next = -1;
		ans.push_back(tmp);
	}

	for (int i = 0; i<n2 - 1; i++) {
		ans[i].next = ans[i + 1].add; //更新反转后的数据的next数据   
		printf("%05d %d %05d\n", ans[i].add, ans[i].data, ans[i].next);
	}
	printf("%05d %d -1\n", ans[n2 - 1].add, ans[n2 - 1].data);
	return 0;
}
