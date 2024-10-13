import math

a = int(input())

for _ in range(a):
    n = int(input())
    array = list(map(int, input().split(" ")))
    while(len(array) > 1):
        minindex = 0
        maxindex = 0
        for i in range(0, len(array)):
            if(array[i] <= array[minindex]):
                minindex = i
            if(array[i] >= array[maxindex]):
                maxindex = i
        secmax = 0
        for i in range(0, len(array)):
            if(array[i] > array[secmax] and array[i] <= array[maxindex]):
                if(array[i] <= array[maxindex] and i != maxindex):
                    secmaxindex = i   
                    continue 
                secmaxindex = i
        if(secmax == minindex):
            secmax = maxindex

        print(array, secmax, minindex, maxindex)
        array[minindex] = math.floor((array[minindex] + array[secmax])/2)
        array.pop(secmax)
    print(array[0])
    