a = [int(x) for x in input().split()]
b = []
N = int(input())
for i in range(N):
    a.sort()
    b.append(a[len(a) - i - 1])
for i in range(len(b)):
    print(sorted(b)[i])


