#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//PAT Advanced 1016 Phone Bills

int feeRate[24];

struct callRecord{
    string name;
    int month,day,hour,minute;
    bool isOnline;
};

struct callInfo{
    string name;
    int month;
    string beginTime,endTime;
    int timelaspe;
    float fee;
};

callRecord getRecord(){
    callRecord data;
    string token;
    cin >> data.name;
    scanf("%d:%d:%d:%d",&data.month,&data.day,&data.hour,&data.minute);
    cin >> token;
    if(token == "on-line")
        data.isOnline = true;
    else
        data.isOnline = false;
    return data;
}

callInfo calculateBill(const callRecord & beginRecord,const callRecord & endRecord){
    callInfo data;
    char timeStr[10];
    data.name = beginRecord.name;
    data.month = beginRecord.month;
    data.fee = 0.0;data.timelaspe = 0;
    sprintf(timeStr,"%02d:%02d:%02d",beginRecord.day,beginRecord.hour,beginRecord.minute);
    data.beginTime = timeStr;
    sprintf(timeStr,"%02d:%02d:%02d",endRecord.day,endRecord.hour,endRecord.minute);
    data.endTime = timeStr;
    int pHour = beginRecord.hour,pDay = beginRecord.day;
    //思路是把通话开始到结束的时间段按hour分段，每一段分别计算话费与时间，累加进话费及通话时间总和
    if(pDay == endRecord.day && pHour == endRecord.hour){
        data.timelaspe = endRecord.minute - beginRecord.minute;
        data.fee += data.timelaspe * feeRate[pHour];
    } else{
        data.timelaspe = 60 - beginRecord.minute;
        data.fee += data.timelaspe * feeRate[pHour];
        while(pHour != endRecord.hour || pDay != endRecord.day){
            if(pHour == 23){
                pDay++;
                pHour = 0;
            } else
                pHour++;
            if(pHour == endRecord.hour && pDay == endRecord.day){
                data.timelaspe += endRecord.minute;
                data.fee += endRecord.minute * feeRate[endRecord.hour];
            } else{
                data.timelaspe += 60;
                data.fee += 60 * feeRate[pHour];
            }
        }
    }
    data.fee /= 100.0;
    return data;
}

bool compare(callRecord A,callRecord B){
    if(A.name != B.name)
        return A.name < B.name;
    else if(A.month != B.month)
        return A.month < B.month;
    else if(A.day != B.day)
        return A.day < B.day;
    else if(A.hour != B.hour)
        return A.hour < B.hour;
    else
        return A.minute < B.minute;
}

int main() {
    int N;
    vector<callRecord> callRawData;
    vector<callInfo> singleCallBillData;
    for (int i = 0; i < 24; ++i) {
        cin >> feeRate[i];
    }
    cin >> N;
    callRawData.resize(N);
    for (int i = 0; i < N; ++i) {
        callRawData[i] = getRecord();
    }
    sort(callRawData.begin(),callRawData.end(),compare);
    for (int i = 0; i < N; ++i) {
        if(!callRawData[i].isOnline || i == N-1)
            continue;
        int j = i+1;
            if(callRawData[j].name == callRawData[i].name && callRawData[i].month == callRawData[j].month &&
                !callRawData[j].isOnline){
                singleCallBillData.push_back(calculateBill(callRawData[i],callRawData[j]));
            }
    }
    string namePtr;
    int monthPtr = -1;
    float billSum = 0;
    bool first = false;
    for (auto iter = singleCallBillData.begin(); iter != singleCallBillData.end(); ++iter) {
        if(namePtr != iter->name || monthPtr != iter->month){
            if(!first)
                first = true;
            else
                printf("Total amount: $%.2f\n",billSum);
            namePtr = iter->name;
            monthPtr = iter->month;
            billSum = iter->fee;
            printf("%s %02d\n",namePtr.c_str(),monthPtr);
            printf("%s %s %d $%.2f\n",iter->beginTime.c_str(),iter->endTime.c_str(),iter->timelaspe,iter->fee);
        }
        else{
            printf("%s %s %d $%.2f\n",iter->beginTime.c_str(),iter->endTime.c_str(),iter->timelaspe,iter->fee);
            billSum += iter->fee;
        }
    }
    printf("Total amount: $%.2f\n",billSum);
    return 0;
}
