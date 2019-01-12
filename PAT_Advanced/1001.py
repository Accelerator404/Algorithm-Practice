# PAT Advanced 1001 A+B Format
# 输入在一行内，以空格分隔，使用input.split指定以“ ”分割字符串，否则会出错
num_a,num_b = input().split(" ")
result = int(num_a) + int(num_b)
str_result = str(result)
pre = ""
lens = len(str_result)
comma_result = ""
if result < 0:
    str_result = str_result[1:lens]
    pre = "-"
    lens = lens - 1
for i in range(lens, 0, -3):
    if i <= 3:
        comma_result = str_result[0:i] + comma_result
        break
    else:
        comma_result = "," + str_result[i-3:i] + comma_result
comma_result = pre + comma_result
print(comma_result)
