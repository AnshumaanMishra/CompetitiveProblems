t = int(input())
for _ in range(t):
    a, b = input().split(" ")
    a = int(a)
    b = int(b)
    leaves = 0;
    for i in range(1, a + 1):
        leaves += i**i
        if(i >= b):
            leaves -= (i-b)**(i-b)
    if(leaves % 2):
        print("NO")
    else:
        print("YES")