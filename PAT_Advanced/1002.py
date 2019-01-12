# PAT Advanced 1002 A+B for Polynomials
A_raw = input()
B_raw = input()
A = [float(p) for p in A_raw.split()]
B = [float(p) for p in B_raw.split()]
K1 = int(A.pop(0))
K2 = int(B.pop(0))
result = {}
output = ""
lens = 0
for i in range(0, K1):
    result[int(A[2 * i])] = A[2 * i + 1]
for i in range(0, K2):
    if int(B[2*i]) not in result.keys():
        result[int(B[2 * i])] = B[2 * i + 1]
    else:
        result[int(B[2 * i])] = B[2 * i + 1] + result[int(B[2 * i])]
# print()传递参数end=""避免换行
for exp in sorted(result.keys(), reverse=True):
    if round(result[exp], 1) != 0:
        # 精度为小数点后1位
        output = output + " " + str(exp) + " " + str(round(result[exp], 1))
        lens = lens + 1
print(str(lens) + output)
