toks = input().split()
n, k = [int(x) for x in toks[:2]]
a = float(toks[-1])

for i in range(1,n):
    print(*([i+1]*k))
