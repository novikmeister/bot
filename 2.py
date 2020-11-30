N = int(input())
#a = []
#while N > 0:
    #array = input().split()
  #  for i in range(len(array)):
   #     array[i] = int(array[i])
 #   a.append(array)
  #  N-=1
#print(a)
#for i in range(len(a)):
   # print()
#    for j in range(len(a[i])):
 #       print(a[i][j], end=(' '))

a = []
while N > 0:
    array = input().split()
    for i in range(len(array)):
        array[i] = int(array[i])
    a.append(array)
    N-=1
s = int(input())
for i in range(len(a)):
    a1 = a.split(" ")
    if s > 0:
        max+=1
        i+=1
    else:
        i+=1

print(max)