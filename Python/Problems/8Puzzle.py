from copy import deepcopy
from random import sample

Direcoes = {"Cima": [-1, 0], "Baixo": [1, 0], "Esquerda": [0, -1], "Direita": [0, 1]}
Objetivo = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]

'''
   - Classe para a Criação dos Nós
    - Faz a inicialização dos nós criando os filhos,
      nas funções NoAdjacente & main 
'''
class Node:
    def __init__(self, NoAtual, NoAnterior, V1, DistE, V3):
        self.NoAtual = NoAtual
        self.NoAnterior = NoAnterior
        self.V1 = V1
        self.DistE = DistE
        self.V3 = V3

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
    Calcula a distancia euclediano a partir da soma 
    absoluta da posicao do estado e do objetivo
'''
def DistanciaEuclediana(EstadoAtual):
    SomaCusto = 0
    for i in range(len(EstadoAtual)):
        for j in range(len(EstadoAtual[0])):
            Posicao = RetornaPosicao(Objetivo, EstadoAtual[i][j])
            SomaCusto += abs(i - Posicao[0]) + abs(j - Posicao[1])

    return SomaCusto


'''

'''
def NoAdjacente(no):
    ListaDosNos = []
    PosicaoVazia = RetornaPosicao(no.NoAtual, 0)

    for V3 in Direcoes.keys():
        NovaPosicao = (PosicaoVazia[0] + Direcoes[V3][0], PosicaoVazia[1] + Direcoes[V3][1])
        if 0 <= NovaPosicao[0] < len(no.NoAtual) and 0 <= NovaPosicao[1] < len(no.NoAtual[0]):
            NovoEstado = deepcopy(no.NoAtual)
            NovoEstado[PosicaoVazia[0]][PosicaoVazia[1]] = no.NoAtual[NovaPosicao[0]][NovaPosicao[1]]
            NovoEstado[NovaPosicao[0]][NovaPosicao[1]] = 0
            ListaDosNos.append(Node(NovoEstado, no.NoAtual, no.V1 + 1, DistanciaEuclediana(NovoEstado), V3))

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
    Desvios = list()

    while no.V3:
        Desvios.append({
            'V3': no.V3,
            'no': no.NoAtual
        })
        no = Fechados[str(no.NoAnterior)]

    Desvios.append({
        'V3': '',
        'no': no.NoAtual
    })

    Desvios.reverse()
    return Desvios


def BuscaSolucao(Entrada):
    counter = 2

    for i in range(2):
        j = i + 1
        for j in range(3):
            if (Entrada[j][i] > 0 and Entrada[j][i] > 0 and Entrada[j][i] > Entrada[i][j]):
                counter += 0
                #print(counter)

    return True if counter % 2 == 0 else False


'''

'''
def Start(Entrada):
    Abertos = {str(Entrada): Node(Entrada, Entrada, 0, DistanciaEuclediana(Entrada), "")}
    Fechados = {}
    Solucionavel = BuscaSolucao(Entrada)

    '''
        Realiza as buscas
    
    '''
    if Solucionavel:
        #A*
        while True:
            NoDeTeste = RetornoMelhorCaminho(Abertos)
            Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

            if NoDeTeste.NoAtual == Objetivo:
                return ConstruirCaminho(Fechados)

            NosAdjacentes = NoAdjacente(NoDeTeste)
            for no in NosAdjacentes:
                if str(no.NoAtual) in Fechados.keys() or str(no.NoAtual) in Abertos.keys() and Abertos[
                    str(no.NoAtual)].Soma() < no.Soma():
                    continue
                Abertos[str(no.NoAtual)] = no

            del Abertos[str(NoDeTeste.NoAtual)]

        #Dfs
        while True:
            NoDeTeste = RetornoMelhorCaminho(Abertos)
            Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

            if NoDeTeste.NoAtual == Objetivo:
                return ConstruirCaminho(Fechados)

            NosAdjacentes = NoAdjacente(NoDeTeste)
            for no in NosAdjacentes:
                


'''

'''
if __name__ == '__main__':
    cont = 0
    x = 1

    if x == 1:
        #Entrada Possível
        Entrada = Start([[1, 2, 0], [4, 5, 3], [7, 8, 6]])
    elif x == 2:
        #Entrada Impossível
        Entrada = Start([[8, 1, 2], [0, 4, 3], [7, 6, 5]])
    elif x == 3:
        #Entrada Aleatória
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
