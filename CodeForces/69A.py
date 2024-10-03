a = int(input())
b = []
for _ in range(a):
    b.append(list(map(int, input().split(" "))))

temp = True
for i in range(3):
    sum = 0
    for j in range(a):
        sum += b[j][i]
    if(sum != 0):
        print(sum)
        print("NO")
        exit()

print("YES") 