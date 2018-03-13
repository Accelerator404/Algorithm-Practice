#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

//PAT Basic No.1015 “德才论”
//注意用scanf和printf代替cin、cout，否则就会面对超时。

struct student{
	int ID;
	int moral;
	int talent;
	int totalScore;
};


bool compare(student i,student j) {
	if (i.totalScore != j.totalScore)
		return i.totalScore > j.totalScore;
	else if (i.moral != j.moral) 
		return i.moral > j.moral;
	else
		return i.ID < j.ID;
}


int main() {
	int N, L, H;
	vector<student> rank1, rank2, rank3, rank4;
	cin >> N >> L >> H;
	int M = 0,m,t;
	for (int i = 0; i < N;i++) {
		student tmp;
		scanf("%d%d%d",&tmp.ID,&m,&t);
		tmp.moral = m;
		tmp.talent = t;
		tmp.totalScore = m+t;
		if (m < L || t < L)
			continue;
		else if (m >= H && t >= H)
			rank1.push_back(tmp);
		else if (m >= H && t < H)
			rank2.push_back(tmp);
		else if (m < H && t < H && m >= t)
			rank3.push_back(tmp);
		else
			rank4.push_back(tmp);
		M++;
	}
	sort(rank1.begin(), rank1.end(), compare);
	sort(rank2.begin(), rank2.end(), compare);
	sort(rank3.begin(), rank3.end(), compare);
	sort(rank4.begin(), rank4.end(), compare);
	cout << M << endl;
	for (int i = 0; i < rank1.size(); i++)
		printf("%d %d %d\n",rank1[i].ID,rank1[i].moral,rank1[i].talent);
	for (int i = 0; i < rank2.size(); i++)
		printf("%d %d %d\n", rank2[i].ID, rank2[i].moral, rank2[i].talent);
	for (int i = 0; i < rank3.size(); i++)
		printf("%d %d %d\n", rank3[i].ID, rank3[i].moral, rank3[i].talent);
	for (int i = 0; i < rank4.size(); i++)
		printf("%d %d %d\n", rank4[i].ID, rank4[i].moral, rank4[i].talent);
	return 0;
}
