/**Exercicio 1**/
CREATE DATABASE EX1;
USE EX1;

CREATE TABLE Cliente(
	clienteId SERIAL PRIMARY KEY,
	cepId CHAR(2) REFERENCES Cep(cepId) ON DELETE NO ACTION ON UPDATE CASCADE,
	numero int2,
	telefone char(12),
	dataCadastro date DEFAULT current_date
);

CREATE TABLE ClienteFisico(
	clienteId INT PRIMARY KEY REFERENCES cliente(clienteId) ON DELETE NO ACTION ON UPDATE CASCADE,
	nome VARCHAR(60) NOT NULL,
	telefoneCelular VARCHAR(12),
	dataNascimento date,
	rg VARCHAR(12),
	emissorRg VARCHAR(12),
	cpf VARCHAR(12) NOT NULL UNIQUE
);

CREATE TABLE ClienteJuridico(
	clienteId INT PRIMARY KEY REFERENCES cliente(clienteId) ON DELETE NO ACTION ON UPDATE CASCADE,
	nomeFantasia VARCHAR(80) UNIQUE, 
	razaoSocial VARCHAR(80) NOT NULL UNIQUE, 
	cnpj VARCHAR(14) NOT NULL UNIQUE, 
	inscricaoEstadual VARCHAR(14) NOT NULL UNIQUE
);

CREATE TABLE Classe( 
	classeId int2,
	sigla VARCHAR(12) NOT NULL UNIQUE, nome VARCHAR(30),
	descricao TEXT,
	CONSTRAINT PK_Classe PRIMARY KEY (classeId)
);

CREATE TABLE Produto( 
	produtoId int8 PRIMARY KEY, nome VARCHAR(60) NOT NULL, 
	estoqueMinimo int2,
	unidadeMedida char(2) CHECK(unidadeMedida = 'Kg' OR unidadeMedida = 'Lt' OR unidadeMedida = 'Dz'),
	precoVenda NUMERIC(8, 2),
	embalagem VARCHAR(20),
	classeId int2,
	CONSTRAINT FK_Produto_Classe FOREIGN KEY (classeId) REFERENCES classe(classeId) ON DELETE CASCADE ON UPDATE CASCADE 
);

CREATE TABLE ProdutoLote(
	produtoId int8,
	loteId int2,
	quantidadeAdquirida NUMERIC(8, 2),
	quantidadeVendida NUMERIC(8,2),
	dataValidade DATE,
	precoCusto NUMERIC(8,2),
	CONSTRAINT PK_Produto_Lote PRIMARY KEY (produtoId, loteId),
	CONSTRAINT FK_Produto_Lote FOREIGN KEY (produtoId) REFERENCES produto(produtoId) ON DELETE CASCADE ON UPDATE CASCADE 
);

CREATE TABLE Venda(
	vendaId INTEGER PRIMARY KEY,
	valorTotal NUMERIC(14, 2),
	cepEntrega char(8) REFERENCES cep(cepId) ON UPDATE CASCADE ON DELETE SET NULL,
	numero INT2,
	dataVenda date DEFAULT current_date,
	dataEntrega date CHECK (NOT(dataEntrega < dataVenda)), status VARCHAR(30),
	vendedorId int2 DEFAULT 100 REFERENCES vendedor(vendedorId) ON DELETE SET DEFAULT ON UPDATE CASCADE,
	clienteId INT2,
	CONSTRAINT FK_Venda FOREIGN KEY (clienteId) REFERENCES cliente(clienteId) ON DELETE CASCADE ON UPDATE NO ACTION 
);

CREATE TABLE ItemVenda(
	vendaId int,
	produtoId int8,
	loteId int2,
	quantidade int NOT NULL CHECK(quantidade > 0),
	CONSTRAINT PK_ItemVenda PRIMARY KEY(vendaId, produtoId, loteId), 
	CONSTRAINT FK_IV_Venda FOREIGN KEY (vendaId) REFERENCES Venda (vendaId) ON DELETE CASCADE ON UPDATE CASCADE,
	CONSTRAINT FK_IV_ProdLote FOREIGN KEY (produtoId, loteId) REFERENCES ProdutoLote (produtoId, loteId) ON DELETE NO ACTION ON UPDATE NO ACTION
);
