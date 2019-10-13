#include <iostream>
#include <vector>
#include <string>
using namespace std;

//PAT Advanced 1042 Shuffling Machine

void initial(vector<int> & deck){
    deck.resize(55);
    for (int i = 0; i < 55; ++i) {
        deck[i] = i;
    }
}

void printCard(int Num){
    if(Num == 0)
        return;
    else if(Num >=1 && Num <= 13){
        cout << 'S' << Num;
    } else if(Num >= 14 && Num<=26){
        cout << 'H' << Num - 13;
    } else if(Num >= 27 && Num <=39){
        cout << 'C' << Num - 26;
    } else if(Num >= 40 && Num <= 52){
        cout << 'D' << Num - 39;
    } else if(Num == 53)
        cout << "J1";
    else if(Num == 54)
        cout << "J2";
}

int main(){
    int K;
    vector<int> cards,tempDeck(55),shuffleSeq(55);
    initial(cards);
    cin >> K;
    for (int i = 1; i < 55; ++i) {
        cin >> shuffleSeq[i];
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 1; j < 55; ++j) {
            tempDeck[shuffleSeq[j]] = cards[j];
        }
        cards.swap(tempDeck);
        tempDeck.clear();
    }
    for (int i = 1; i < 55; ++i) {
        if(i > 1)
            cout << ' ';
        printCard(cards[i]);
    }
    return 0;
}
