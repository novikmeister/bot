a = input()
k = 1
f = 1
try:
    b = a.split('.')
    c = b[1]
    d = b[0]
    k = len(c)
    f = len(d)
    if int(b[0]) < 0:
        b[1] = int(b[1]) + 1
    elif int(b[1]) == 0:
        b[1] = '9' * k
        b[0] = int(b[0]) - 1
    else:
        b[1] = int(b[1]) - 1

    b[0] = str(b[0]) +'.' + str(b[1])
    b[0] = float(b[0])
except:
    b[0] = int(b[0]) - 1
print(b[0])

