a = input()
b = [0, 0, 0, 0, 0, 0, 0, 0, 1]
b.extend(sum(b[i-9:i]) for i in range(9, int(a)))
print(b[int(a)-1])