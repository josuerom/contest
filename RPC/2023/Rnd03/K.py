"""
   author:  josuerom
   created: 25/03/23 17:40:04
"""
n = int(raw_input())
ans = 0
vol = {}

for i in range(n):
   x, y = map(int, raw_input().split(" "))
   if x in vol:
      vol[x].append(y)
   else:
      vol[x] = [y]

keys = sorted(vol.keys())

if len(keys) == 0:
   ans = 0
else:
   ans = keys[-1] - keys[0]

up_val = 0
down_val = 0
up = max(vol[keys[0]])
down = min(vol[keys[0]])

for xval in keys:
   low = min(vol[xval])
   high = max(vol[xval])
   ans += high - low
   downhigh = abs(down - high)
   downlow = abs(down - low)
   uphigh = abs(up - high)
   uplow = abs(up - low)
   up_val2 = min(up_val + uplow, down_val + downlow)
   down_val2 = min(up_val + uphigh, down_val + downhigh)
   up_val = up_val2
   down_val = down_val2
   up = high
   down = low

print(ans + min(up_val, down_val))