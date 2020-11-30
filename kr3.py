a = input()
b = []
k = 0
for i in range(len(a)):
    if a[i] == '1':
        k += 1
    else:
        b.append(k)
        k = 0
b.append(k)
print(max(b))
