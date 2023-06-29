"""
   author:  josuerom
   created: 25/03/23 17:59:76
"""
from math import sqrt

q = int(raw_input())
m = {1: 1}
row = [1]

for i in range(1, 2000):
   cur = [1]
   for j in range(1, i):
      num = row[j] + row[j - 1]
      cur.append(min(num, 10**11))
      if num != 10**11 and num not in m:
         m[num] = i + 1
   cur.append(1)
   row = cur

for i in range(q):
   n = int(raw_input())
   if n not in m:
      x = sqrt(1 + 8 * n)
      if x - int(x) == 0:
         row = (1 + x) / 2
         print int(row + 1)
      else:
         print n + 1
   else:
      print m[n]
