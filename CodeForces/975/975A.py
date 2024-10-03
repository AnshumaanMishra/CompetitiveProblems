from bisect import bisect_left
 
def BinarySearch(a, x):
    i = bisect_left(a, x)
    if i != len(a) and (a[i] >= x and a[i+1] <= x):
        return i
    else:
        return -1

t = int(input())

for _ in range(t):
    a = input().split(" ")
    n, q = int(a[0]), int(a[1])
    pts = list(map(int, input().split(" ")))
    queries = list(map(int, input().split(" ")))
    key = pts[0]
    width = pts[-1] - pts[0]
    map1 = [0 for _ in range(width)]
    for i in range(0, width){
        index = BinarySearch(pts, i + key)
        left = index + 1
        right = n - index
        map1[i] = left * right
    }

    for i in queries:
        count = 0
        for j in map1:
            count += (j == i) 
        print(count, end = " ")
