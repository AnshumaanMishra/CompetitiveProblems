t = int(input())
i = 0
usernames = dict()
while(i < t):
    name = input()
    if(name in usernames.keys()):
        print(name + str(usernames[name]))
        usernames[name] += 1
    else:
        usernames[name] = 1
        print("OK")
    i += 1