from random import randint as ri
from random import sample

n, m, low, up = [int(x) for x in input().split()]

print(n,m,low,up)

for i in range(m):
    u, v = sample(range(n),2)
    print(u,v,ri(1,1000),ri(1,up))
