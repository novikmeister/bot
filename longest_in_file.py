f = open(input(), 'r')
print(max(f.read().split(), key = lambda e: len(e)))
f.close()