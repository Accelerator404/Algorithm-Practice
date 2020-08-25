#include <iostream>
using namespace std;

//PAT Advanced 1108 Finding Average

bool isLegal(string num){
    char q[50];
    double k;
    bool l = true;
    sscanf(num.c_str(),"%lf",&k);
    sprintf(q,"%.02lf",k);
    for (int i = 0; i < num.length(); ++i) {
        if(num[i] != q[i])
            l = false;
    }
    if(!l || k > 1000.0 || k < -1000.0)
        return false;
    else
        return true;
}

int main(){
    int N,legalCount = 0;
    double sum = 0.0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string num;
        cin >> num;
        if(!isLegal(num))
            printf("ERROR: %s is not a legal number\n",num.c_str());
        else{
            double k;
            k = strtof(num.c_str(),nullptr);
            sum += k;
            legalCount++;
        }
    }
    if (legalCount == 1)
        printf("The average of %d number is %.02lf\n",legalCount,sum);
    else if (legalCount > 1)
        printf("The average of %d numbers is %.02lf\n",legalCount,sum/legalCount);
    else
        printf("The average of %d numbers is Undefined\n",legalCount);
    return 0;
}
