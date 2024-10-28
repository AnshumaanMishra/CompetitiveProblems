from itertools import permutations 

a = list(range(1, 10))
b = [2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17]#ṇ, 6, 7, 8, 9, 10]
# b = a.copy()
k = 0
for i in range(len(a)):
    if((i + 1) % 2 == 0):
        k = k | a[i]
    else:
        k = k & a[i]
print(k)


max = k
p = permutations(b)
for j in p:
    k = 0
    for i in range(len(j)):
        if((i + 1) % 2 == 0):
            k = k | j[i]
        else:
            k = k & j[i]
    if(k == max):
        print(*j)
        print(k)
        # input()

# j = []

