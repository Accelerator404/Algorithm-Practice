#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//PAT Advanced 1022 Digital Library

/*
 * 思路：单纯的线性存储+遍历搜索显然效率低下，将可以归并到某一特征的项索引，搜索时直接导出索引即可。
 * 活用map容器。
 */

struct book{
    unsigned int ID,year;
    string title,author,publisher;
    vector<string> keywords;
};
vector<book> database;
map<string,vector<int>> authorCata,keyWordCata,publisherCata;
map<int,vector<int>> yearCata;

book getInfo(){
    book data;
    string keyword;
    cin >> data.ID;
    getchar();
    getline(cin,data.title);
    getline(cin,data.author);
    getline(cin,keyword);
    getline(cin,data.publisher);
    cin >> data.year;
    authorCata[data.author].push_back(data.ID);
    while (true){
        unsigned long div = keyword.find_first_of(' ');
        if(div != string::npos){
            string word = keyword.substr(0,div);
            data.keywords.push_back(word);
            keyword = keyword.substr(div+1,keyword.length());
            keyWordCata[word].push_back(data.ID);
        } else{
            data.keywords.push_back(keyword);
            keyWordCata[keyword].push_back(data.ID);
            break;
        }
    }
    publisherCata[data.publisher].push_back(data.ID);
    yearCata[data.year].push_back(data.ID);
    return data;
}

//对数据库索引内的ID进行排序
void sortCatalog(){
    for (auto iter = authorCata.begin();  iter != authorCata.end() ; iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
    for (auto iter = yearCata.begin();  iter != yearCata.end() ; iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
    for (auto iter = keyWordCata.begin();  iter != keyWordCata.end() ; iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
    for (auto iter = publisherCata.begin();  iter != publisherCata.end() ; iter++) {
        sort(iter->second.begin(),iter->second.end());
    }
};

void search(){
    vector<int> resultQueue;
    int searchType;
    string input;
    getline(cin,input);
    searchType = input[0] - '0';
    input = input.substr(3,input.length());
    if(searchType == 1){
        for (int i = 0; i < database.size(); ++i) {
            if(database[i].title == input)
                resultQueue.push_back(database[i].ID);
        }
    } else if(searchType == 2){
        resultQueue = authorCata[input];
    } else if(searchType == 3){
        resultQueue = keyWordCata[input];
    } else if(searchType == 4){
        resultQueue = publisherCata[input];
    } else if(searchType == 5){
        int yr = strtol(input.c_str(), nullptr,10);
        resultQueue = yearCata[yr];
    }
    cout << searchType << ": " << input << endl;
    if(resultQueue.empty()){
        cout << "Not Found" << endl;
        return;
    }
    else{
        //如果发生排序错误，在此处对resultQueue进行排序
        for (int j = 0; j < resultQueue.size(); ++j) {
            printf("%07d\n",resultQueue[j]);
        }
    }
}

int main(){
    int N,M;
    cin >> N;
    database.resize(N);
    for (int i = 0; i < N; ++i) {
        database.push_back(getInfo());
    }
    sortCatalog();
    cin >> M;
    getchar();
    for (int j = 0; j < M; ++j) {
        search();
    }
    return 0;
}
