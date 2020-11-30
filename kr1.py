a = input().split()
sum = 0
for i in range(len(a)):
    try:
        sum = sum + int(a[i])
    except:
        pass
print(sum)