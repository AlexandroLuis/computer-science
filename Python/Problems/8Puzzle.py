from copy import deepcopy
from random import sample
import math
import os

Direcoes = {"Cima": [-1, 0], "Baixo": [1, 0], "Esquerda": [0, -1], "Direita": [0, 1]}
Objetivo = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

'''
   - Classe para a Criação dos Nós
    - Faz a inicialização dos nós criando os filhos,
      nas funções NoAdjacente & main 
'''
class Node:
    def __init__(self, NoAtual, NoAnterior, V1, DistE, ListCam):
        self.NoAtual = NoAtual
        self.NoAnterior = NoAnterior
        self.V1 = V1
        self.DistE = DistE
        self.ListCam = ListCam

    def Soma(self):
        return self.V1 + self.DistE


'''
    Função para Mostrar os caminhos.
    percorre a matriz imprimindo o estado final de cada
    contrução de caminho com o melhor caminho
'''
def Saida(No):
    for i in range(len(No)):
        for j in No[i]:
            if j == 0:
                print("  ", end=' ')
            else:
                print("", j, end=' ')
        print("")


'''
    Faz o retorno de cada estado atual
'''
def RetornaPosicao(EstadoAtual, Valor):
    for i in range(len(EstadoAtual)):
        if Valor in EstadoAtual[i]:
            return (i, EstadoAtual[i].index(Valor))


'''
    Calcula a distancia euclediana
'''
def Heuristica(EstadoAtual):
    SomaCusto = 0
    j = 3

    # Euclediana
    if j == 1:
        for i in range(len(EstadoAtual)):
            for j in range(len(EstadoAtual[0])):
                Posicao = RetornaPosicao(Objetivo, EstadoAtual[i][j])
                SomaCusto += abs(i - Posicao[0]) + abs(j - Posicao[1])

    # Manhattam 
    elif j == 2:
        for i in range(len(EstadoAtual)):
            for j in range(len(EstadoAtual[0])):
                Posicao = RetornaPosicao(Objetivo, EstadoAtual[i][j])
                SomaCusto += abs((j - Posicao[0]) % 3 - i % 3) + abs((j - Posicao[1]) // 3 - i // 3)

    # Misplaced 
    elif j == 3:
        SomaCusto = -1
        for i in range(len(EstadoAtual)):
            for j in range(len(EstadoAtual)):
                if EstadoAtual[i][j] != Objetivo[i][j]:
                    SomaCusto += 1

        for i in range(len(EstadoAtual)):
            for j in range(len(EstadoAtual[0])):
                SomaCusto += math.fabs((EstadoAtual[i][j] - Objetivo[i][j]))

    return SomaCusto


def NoAdjacente(no):
    ListaDosNos = []
    PosicaoVazia = RetornaPosicao(no.NoAtual, 0)

    for ListCam in Direcoes.keys():
        NovaPosicao = (PosicaoVazia[0] + Direcoes[ListCam][0], PosicaoVazia[1] + Direcoes[ListCam][1])
        if 0 <= NovaPosicao[0] < len(no.NoAtual) and 0 <= NovaPosicao[1] < len(no.NoAtual[0]):
            NovoEstado = deepcopy(no.NoAtual)
            NovoEstado[PosicaoVazia[0]][PosicaoVazia[1]] = no.NoAtual[NovaPosicao[0]][NovaPosicao[1]]
            NovoEstado[NovaPosicao[0]][NovaPosicao[1]] = 0
            ListaDosNos.append(Node(NovoEstado, no.NoAtual, no.V1 + 1, Heuristica(NovoEstado), ListCam))

    return ListaDosNos


'''
    Busca pelo melhor caminho
'''
def RetornoMelhorCaminho(Abertos):
    TesteInicial = True

    for no in Abertos.values():
        if TesteInicial or no.Soma() < Melhor:
            TesteInicial = False
            MelhorNo = no
            Melhor = MelhorNo.Soma()
    return MelhorNo


'''
    Constroi os caminhos
'''
def ConstruirCaminho(Fechados):
    no = Fechados[str(Objetivo)]
    Caminhos = list()

    while no.ListCam:
        Caminhos.append({'ListCam': no.ListCam, 'no': no.NoAtual})
        no = Fechados[str(no.NoAnterior)]

    Caminhos.append({'ListCam': '', 'no': no.NoAtual})

    Caminhos.reverse()
    #print(Caminhos)
    return Caminhos


def somacount(vet):
    count = 0
    for i in range(0, 9):
        for j in range(i + 1, 9):
            if vet[j] != -1 and vet[i] != -1 and vet[i] > vet[j]:
                count += 1
    return count


def BuscaSolucao(Entrada):
    count = somacount([j for sub in Entrada for j in sub])
    return bool(count % 2 == 0)


def Start(Entrada):
    if BuscaSolucao(Entrada):
        return False
    Abertos = {str(Entrada): Node(Entrada, Entrada, 0, Heuristica(Entrada), "")}
    Fechados = {}
    j = 1

    '''
        Realiza as buscas

    '''
    if j == 1:
        # A*
        while True:
            NoDeTeste = RetornoMelhorCaminho(Abertos)
            Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

            if NoDeTeste.NoAtual == Objetivo:
               print("A*")
               return ConstruirCaminho(Fechados)

            NosAdjacentes = NoAdjacente(NoDeTeste)
            for no in NosAdjacentes:
                if str(no.NoAtual) in Fechados.keys() or str(no.NoAtual) in Abertos.keys() and \
                        Abertos[str(no.NoAtual)].Soma() < no.Soma():
                    continue
                else:
                    Abertos[str(no.NoAtual)] = no
            del Abertos[str(NoDeTeste.NoAtual)]


    elif j == 2:
        # Dfs
        while True:
            NoDeTeste = RetornoMelhorCaminho(Abertos)
            Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

            if NoDeTeste.NoAtual == Objetivo:
                print("Dfs")
                return ConstruirCaminho(Fechados)

            NosAdjacentes = NoAdjacente(NoDeTeste)
            for no in NosAdjacentes:
                if str(no.NoAtual) not in Fechados.keys():
                    Abertos[str(no.NoAtual)] = no
            del Abertos[str(NoDeTeste.NoAtual)]


    elif j == 3:
        # Greedy, melhor caso 1°
        while True:
            NoDeTeste = RetornoMelhorCaminho(Abertos)
            Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

            if NoDeTeste.NoAtual == Objetivo:
                print("Gulosa")
                return ConstruirCaminho(Fechados)

            NosAdjacentes = NoAdjacente(NoDeTeste)
            for no in NosAdjacentes:
                if str(no.NoAtual) in Abertos.keys():
                    continue
                Abertos[str(no.NoAtual)] = no
            del Abertos[str(NoDeTeste.NoAtual)]


if __name__ == '__main__':
    cont = 0
    x = 1

    # Entrada Possível
    if x == 1:
        Entrada = Start([[4, 1, 2], [0, 5, 3], [7, 8, 6]])

    # Entrada Impossível
    elif x == 2:
        Entrada = Start([[8, 1, 2], [0, 4, 3], [7, 6, 5]])

    # Entrada Aleatória
    elif x == 3:
        V = sample(range(0, 9), 9)
        Entrada = Start([[V[0], V[1], V[2]], [V[3], V[4], V[5]], [V[6], V[7], V[8]]])

    try:
        print(f'Movimentações:', len(Entrada) - 1)
        for i in Entrada:
            cont += 1
            print()
            if cont == len(Entrada):
                print("Resultado:")
            else:
                print(f'Passo:', cont)
            Saida(i['no'])
    except:
        print("Não Existe Solução!")
