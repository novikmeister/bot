a = [str(s) for s in input().split()]
b = [(a[i],a.count(a[i])) for i in range(len(a))]
b = sorted(sorted(list(dict.fromkeys(b)), key = lambda e: e[0]), key = lambda e: e[1], reverse = True)
for i in range(len(b)):
    print(b[i][1], b[i][0])