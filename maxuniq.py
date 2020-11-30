a = [int(x) for x in input().split()]
print(max([x for x in a if a.count(x) == 1]))