# ZJU Data Structure Mooc 19 Fall
# 01-复杂度1 最大子列和问题
# 输入格式:
#   输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
# 输出格式:
#   在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。

def findMaxCrossingSubarray(A):
    low = 0
    high = len(A) - 1
    leftSum = -1000000
    sum = 0
    mid = int((low+high)/2)
    maxLeft = mid
    for i in range(mid,low-1,-1):
        sum = sum + A[i]
        if sum > leftSum:
            leftSum = sum
            maxLeft = i
    rightSum = -1000000
    sum = 0
    maxRight = mid+1
    for j in range(mid+1,high+1,1):
        sum = sum + A[j]
        if sum > rightSum:
            rightSum = sum
            maxRight = j
    return (maxLeft,maxRight,leftSum+rightSum)


def findMaximumSubarray(A):
    low = 0
    high = len(A) - 1
    if low == high:
        return (low,high,A[low])
    else:
        mid = int((low+high)/2)
        leftSub = findMaximumSubarray(A[low:mid+1])
        rightSub = findMaximumSubarray(A[mid+1:high+1])
        rightSub = (rightSub[0] + mid + 1,rightSub[1] + mid + 1,rightSub[2])
        crossSub = findMaxCrossingSubarray(A)
        if leftSub[2] >= rightSub[2] and leftSub[2] >= crossSub[2]:
            return leftSub
        elif rightSub[2] >= leftSub[2] and rightSub[2] >= crossSub[2]:
            return rightSub
        else:
            return crossSub


K = eval(input())
seq = list(map(int,input().strip().split()))
for num in seq:
    num = int(num)
print(findMaximumSubarray(seq)[2])
