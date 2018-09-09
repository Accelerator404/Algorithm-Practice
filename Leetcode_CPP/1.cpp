class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> toFindList;
        vector<int> result(2);
        for(int i = 0;i < nums.size();i++){
            int numToFind = target - nums[i];
            if(toFindList.find(numToFind) != toFindList.end()){
                result[0] = toFindList[numToFind];
                result[1] = i;
                return result;
            }
            toFindList[nums[i]] = i;
        }
        return result;
    }
};
