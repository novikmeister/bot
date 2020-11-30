k = 0
try:
    a = open(input(), 'r')
except:
    a = "error.document.228322"
b = input()
if a == "error.document.228322":
    k = 0
else:
    c = (a.read().lower().split())
    k += c.count(b.lower())

print(k)

