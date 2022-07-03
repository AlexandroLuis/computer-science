import threading
import time
import random
from multiprocessing import Process, Queue, cpu_count

#Barbeiro
def barber(queue):
    while True:
        queue.get()
        print("Barbeiro Esta Cortando Cabelo")
        time.sleep(random.randint(10, 25))

#Cliente
def customer(queue):
	while True:
	    print("Cliente Esta em Espera")
	    queue.put('Trabalhando')
	    time.sleep(random.randint(1, 3)) 

#Classe de gerenciamento
class Manager:
    def __init__(self):
        self.queue = Queue()
        self.NUMBER_OF_PROCESSES = cpu_count() # Função para obter o numero de cpu do computador
    
    #Função para a inicialização
    def start(self):
        self.workers = [Process(target=barber, args=(self.queue,)) for i in range(self.NUMBER_OF_PROCESSES)]
        for w in self.workers:
            w.start()

        customer(self.queue)

Manager().start()
