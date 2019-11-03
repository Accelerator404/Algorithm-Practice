# ZJU Data Structure Mooc 19 Fall
# 01-复杂度2 Maximum Subsequence Sum
# Input Specification:
#    Each input file contains one test case. Each case occupies two lines.
#   The first line contains a positive integer K (≤10000).
#   The second line contains K numbers, separated by a space.
# Output Specification:
#   For each test case, output in one line the largest sum,
#   together with the first and the last numbers of the maximum subsequence.
#   The numbers must be separated by one space,
#   but there must be no extra space at the end of a line.
#   In case that the maximum subsequence is not unique,
#   output the one with the smallest indices i and j (as shown by the sample case).
#   If all the K numbers are negative, then its maximum sum is defined to be 0,
#   and you are supposed to output the first and the last numbers of the whole sequence.

K = eval(input())
seq = list(map(int, input().strip().split()))
for num in seq:
    num = int(num)
subLeft = 0
subRight = 0
tmpLeft = 0
tmpRight = 0
maxSubSeqSum = 0
tmpSubSum = 0
for i in range(0,len(seq)):
    tmpSubSum = tmpSubSum + seq[i]
    if tmpSubSum >= 0:
        tmpRight = i
        if tmpSubSum > maxSubSeqSum or (maxSubSeqSum == 0 and tmpSubSum == 0):
            maxSubSeqSum = tmpSubSum
            subRight = tmpRight
            subLeft = tmpLeft
    else:
        tmpLeft = i+1
        tmpSubSum = 0
# 当数组全负数时，subRight停在0
if subRight == 0 and seq[0] < 0:
    subLeft = 0
    subRight = len(seq) - 1
print(maxSubSeqSum,seq[subLeft],seq[subRight])

