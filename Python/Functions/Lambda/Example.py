a = 3
n = 7

def myfunc(n):
  return lambda a : a * n

mytripler = myfunc(a)

print(mytripler(n))
