# PAT Advanced 1048 Find Coins
# 第4个测试点超时，不知道有没有AC的可能性
raw_N, raw_M = input().split()
raw_vector = input()
N = int(raw_N)
M = int(raw_M)
coins = list(map(int, raw_vector.strip().split()))
coins .sort()
prev = -1
flag_found = 0
for i in range(0, len(coins)):
    if prev == coins[i]:
        i = i + 1
    else:
        # 二分查找 i+1~len(coin)
        left = i + 1
        right = len(coins) - 1
        # 以“//”运算符得到int/int = int形式，否则商为float
        mid = (left + right) // 2
        while left <= right:
            if coins[mid] + coins[i] == M:
                flag_found = 1
                break
            if coins[mid] < M - coins[i]:
                left = mid + 1
            else:
                right = mid - 1
            mid = (left + right)//2
        if flag_found == 1:
            print("%d %d" % (coins[i], coins[mid]))
            break
        prev = coins[i]
if flag_found == 0:
    print("No Solution")
