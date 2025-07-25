n = int(input())
lst = list(map(int, input().split()))
dick = {}
for i in lst:
    if i not in dick:
        dick[i] = 1
    else:
        dick[i] += 1
res = 0
for i in range(len(lst)):
    for j in range(0, i+1):
        if lst[i] + lst[j] in dick:
            res += dick[lst[i] + lst[j]]
print(res)