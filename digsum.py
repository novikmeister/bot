num = input()
l = len(num)
summ = 0
for i in range(l):
    summ = summ + int(num[i])
    i += 1
num = str(summ)
l = len(num)
summ = 0
for i in range(l):
    summ = summ + int(num[i])
print(summ)
