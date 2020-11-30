#!/usr/bin/env python3
a = input()
b = [0, 1]
b.extend(sum(b[i-2:i]) for i in range(2, int(a)))
print(b[int(a)-1])