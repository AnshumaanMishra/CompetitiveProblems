s = input()
s = s.lower()

def checkConsonant(x):
    if(x != 'a' and x != 'e' and x != 'i' and x != 'o' and x != 'u' and x != 'y'):
        return True
    return False

r = ''

for i in s:
    if(checkConsonant(i)):
        r += '.' + i

print(r)