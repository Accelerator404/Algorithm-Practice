//需要进一步修改

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long N1 = nums1.size(),N2 = nums2.size();
        //排除空集
        if(N1 == 0 && N2%2 == 0)
            return (nums2[N2/2-1] + nums2[N2/2])/2.0;
        else if(N1 == 0 && N2%2 == 1)
            return nums1[(N2 - 1)/2];
        else if(N2 == 0 && N1%2 == 0)
            return (nums2[N1/2-1] + nums2[N1/2])/2.0;
        else if(N2 == 0 && N1%2 == 1)
            return nums1[(N1 - 1)/2];
        //需要讨论中位数在整体N1+N2两个数中的情况，此处i+j不对
        unsigned long i = (N1+1)/2,j = (N2+1)/2;
        while(true){
            if(i+j != (N1+N2)/2){
                if(i+j < (N1+N2)/2 && nums1[i+1] <= nums2[j+1])
                    i++;
                else if (i+j < (N1+N2)/2 && nums1[i+1] > nums2[j+1])
                    j++;
                else if (i+j > (N1+N2)/2 && nums1[i] <= nums2[j])
                    j--;
                else if (i+j > (N1+N2)/2 && nums1[i] > nums2[j])
                    i--;
                }
            else{
                //出现两侧数目相等且四个数相等情况，中位数确定
                if(nums1[i] == nums2[j] && nums1[i+1] == nums2[j+1])
                    return (nums1[i]+nums2[j])/2.0;
                //出现完美划分 中位数确定
                else if(max(nums1[i],nums2[j]) <= min(nums1[i+1],nums2[j+1]))
                    return (max(nums1[i],nums2[j]) + min(nums1[i+1],nums2[j+1]))/2.0;
                //交换两侧最大最小值
                if(nums1[i] < nums2[j])
                    j--;
                else
                    i--;
                if(nums1[i+1] < nums2[j+1])
                    i++;
                else
                    j++;
            }
        }
    }
};
