#a=[]
#a = input().split()
#print(a)
n = int(input())
res = []
for i in range(n):
    res.append(list(map(int,input().split())))
#print(res)
res = sorted(res, key = lambda e: e[0])
#print(res)
#print(res[counter][0])
s = int(input())
counter = int(0)
#print(res[counter][0])
while s > 0 and counter < len(res):
#print("counter: " + str(counter))
#print("price: " + str(res[counter][0]))
#print()
    if res[counter][0] > s:
#print("end0")
        break
    else:
        s = s - res[counter][0]
        counter = counter + int(1)
#print("counter cool")
#print(counter)

sum = int(0)
for x in range(counter):
    sum += res[x][1]
print(str(counter) + ' ' + str(sum))