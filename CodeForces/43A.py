n = int(input())
teams = {'container' : 0}
for _ in range(n):
    x = input()
    if x in list(teams.keys()):
        teams[x] += 1
    else:
        teams[x] = 1

if(len(list(teams.keys())) == 2):
    print(list(teams.keys())[1])
elif(teams[list(teams.keys())[1]] > teams[list(teams.keys())[2]]):
    print(list(teams.keys())[1])
else:
    print(list(teams.keys())[2])