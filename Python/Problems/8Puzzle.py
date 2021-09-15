from copy import deepcopy

Direcoes = {"Cima": [-1, 0], "Baixo": [1, 0], "Esquerda": [0, -1], "Direita": [0, 1]}
Objetivo = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]


# Classe para a Criação dos Nós
class Node:
    def __init__(self, NoAtual, NoAnterior, V1, V2, dir):
        self.NoAtual = NoAtual
        self.NoAnterior = NoAnterior
        self.V1 = V1
        self.V2 = V2
        self.dir = dir

    def Soma(self):
        return self.V1 + self.V2


# Função para Mostrar os caminhos
def Saida(No):
    for i in range(len(No)):
        for j in No[i]:
            if j == 0:
                print("  ", end=' ')
            else:
                print(" ", j, end=' ')
        print("")


def RetornaPosicao(EstadoAtual, Valor):
    for i in range(len(EstadoAtual)):
        if Valor in EstadoAtual[i]:
            return (i, EstadoAtual[i].index(Valor))


# Calcula o custo euclediano
def CustoEuclediano(EstadoAtual):
    SomaCusto = 0
    for i in range(len(EstadoAtual)):
        for j in range(len(EstadoAtual[0])):
            Posicao = RetornaPosicao(Objetivo, EstadoAtual[i][j])
            SomaCusto += abs(i - Posicao[0]) + abs(j - Posicao[1])

    return SomaCusto


def NoAdjacente(node):
    ListaDosNos = []
    PosicaoVazia = RetornaPosicao(node.NoAtual, 0)

    for dir in Direcoes.keys():
        NovaPosicao = (PosicaoVazia[0] + Direcoes[dir][0], PosicaoVazia[1] + Direcoes[dir][1])
        if 0 <= NovaPosicao[0] < len(node.NoAtual) and 0 <= NovaPosicao[1] < len(node.NoAtual[0]):
            NovoEstado = deepcopy(node.NoAtual)
            NovoEstado[PosicaoVazia[0]][PosicaoVazia[1]] = node.NoAtual[NovaPosicao[0]][NovaPosicao[1]]
            NovoEstado[NovaPosicao[0]][NovaPosicao[1]] = 0
            ListaDosNos.append(Node(NovoEstado, node.NoAtual, node.V1 + 1, CustoEuclediano(NovoEstado), dir))

    return ListaDosNos


# Busca pelo melhor caminho
def RetornoMelhorCaminho(Abertos):
    TesteInicial = True

    for no in Abertos.values():
        if TesteInicial or no.Soma() < Melhor:
            TesteInicial = False
            MelhorNo = no
            Melhor = MelhorNo.Soma()
    return MelhorNo


# Constroi os caminhos
def ConstruirCaminho(Fechados):
    no = Fechados[str(Objetivo)]
    Desvios = list()

    while no.dir:
        Desvios.append({
            'dir': no.dir,
            'node': no.NoAtual
        })
        no = Fechados[str(no.NoAnterior)]

    Desvios.append({
        'dir': '',
        'node': no.NoAtual
    })

    Desvios.reverse()
    return Desvios


def main(Param):
    Abertos = {str(Param): Node(Param, Param, 0, CustoEuclediano(Param), "")}
    Fechados = {}

    # Busca
    while True:
        NoDeTeste = RetornoMelhorCaminho(Abertos)
        Fechados[str(NoDeTeste.NoAtual)] = NoDeTeste

        if NoDeTeste.NoAtual == Objetivo:
            return ConstruirCaminho(Fechados)

        adj_node = NoAdjacente(NoDeTeste)
        for node in adj_node:
            if str(node.NoAtual) in Fechados.keys() or str(node.NoAtual) in Abertos.keys() and Abertos[
                str(node.NoAtual)].Soma() < node.Soma():
                continue
            Abertos[str(node.NoAtual)] = node

        del Abertos[str(NoDeTeste.NoAtual)]


if __name__ == '__main__':
    cont = 0
    Entrada = main([[1, 2, 0], [4, 5, 3], [7, 8, 6]])

    print(f'Movimentações: ', len(Entrada) - 1)
    for i in Entrada:
        cont += 1
        print()
        if cont == len(Entrada):
            print("Resultado:")
        else:
            print(f'Passo:', cont)
        Saida(i['node'])
