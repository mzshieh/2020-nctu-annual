toks = input().split()
n, k = [int(x) for x in toks[:2]]
a = float(toks[-1])

for i in range(1,n):
    print(*range(i+1,min(i+k+1,n+1)))
