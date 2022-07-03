from random import randint
import sys

def Swap(a, b):
    if len(a) > 0:
        b.append(a.pop())

#Cria as pilhas
A = ['A','C']
B = ['B']
C = []
ObjStack = ['C','B','A']

stack = [A, B, C]
true = True
StateTest = stack
Storage = stack.copy()

while true:
    print(f'{A}\t{B}\t{C}\nP1\tP2\tP3\n\n')
    
    if B == ObjStack:
        true = False
        print(f'Sucesso')
    else: 
        pop = randint(0, 2)
        push = randint(0, 2)
        while push == pop:
            push = randint(0, 2)
    Swap(StateTest[pop], StateTest[push])
    
    if StateTest not in Storage:
        if pop == 0:
            if push == 1:
                Swap(A, B)
            else:
                 Swap(A, C)

        if pop == 1:
            if push == 0:
                Swap(B, A)
            else:
                Swap(B, C)

        if pop == 2:
            if push == 0:
                Swap(C, A)
            else:
                Swap(C, B)
    else:
        Swap(StateTest[pop], StateTest[push])
