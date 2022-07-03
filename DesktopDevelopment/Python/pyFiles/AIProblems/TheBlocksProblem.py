import copy

class node:
    def __init__(self, state):
        self.state = state
        self.children = []

    def action(self):
        for i in range(3):            
            for j in range(3):
                if i != j:
                    if self.state[i]:
                        temp = copy.deepcopy(self.state)
                        m = temp[i].pop()
                        temp[j].append(m)
                                               
                        if temp not in self.children:
                            self.children.append(node(temp))                                         

    def search(self, goal, queue):

        if self.state == goal:
            counter = 0
            
            print("Estado Final - Sucesso")
            print(self.state,"\n\nEstado Inicial:")
            print(f'{i_state}')
            print("\nCaminho:")
            
            for i in walkaround:
                if (i == i_state or counter > 0):
                    print('\n'.join(map(str, i)), "\n")  
                    counter += 1
        
            return True

        for child in self.children:
            if child.state not in queue:
                walkaround.append(child.state)
                child.action()
                temp = copy.deepcopy(child.state)
                queue.append(temp)
                result = child.search(goal, queue)

                if result:
                    return result

                return self.search(goal, queue)

        return False

i_state = [['A'], ['B', 'C'], []]
root = node(i_state)
root.action()
goal = [[], ['C', 'B', 'A'], []]
queue = []
walkaround = []
root.search(goal, queue)
