a = [str(s) for s in input().split()]
b = []
for i in range(len(a)):
    try:
        f = open(a[i], 'r')
        b.extend(f.read().split())
        f.close()
    except:
        pass
b = sorted(set(dict.fromkeys(b)))
c = b[0]
for i in range(1, len(b)):
    c = c + str(" "+b[i])
print(c)