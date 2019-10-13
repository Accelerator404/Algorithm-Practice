#include <iostream>
#include <string>
using namespace std;

//PAT Advanced 1058 A+B in Hogwarts

struct currency{
    int Galleon = 0,Sickle = 0,Knut = 0;
};

int main(){
    currency A,B,res;
    scanf("%d.%d.%d",&A.Galleon,&A.Sickle,&A.Knut);
    scanf("%d.%d.%d",&B.Galleon,&B.Sickle,&B.Knut);
    res.Knut = A.Knut + B.Knut;
    res.Sickle = A.Sickle + B.Sickle;
    res.Galleon = A.Galleon + B.Galleon;
    if(res.Knut >= 29){
        res.Sickle += 1;
        res.Knut -= 29;
    }
    if(res.Sickle >= 17){
        res.Galleon += 1;
        res.Sickle -= 17;
    }
    printf("%d.%d.%d",res.Galleon,res.Sickle,res.Knut);
    return 0;
}
