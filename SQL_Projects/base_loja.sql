create database loja;
use loja;
create table cliente values(
	idcliente int,
	nome varchar(30),
	PRIMARY KEY(idcliente),
	);

create table venda values(
	idvenda int,
	valor_total numeric(5,2),
	qtd_itens int,
	idcliente int,
	idproduto int,
	PRIMARY KEY(idvenda),
	FOREIGN KEY( idcliente) REFERENCES cliente(idcliente),
	FOREIGN KEY( idproduto) REFERENCES produto(idproduto),
	//CONSTRAINT FK_PersonOrder FOREIGN KEY (PersonID)
   	 //REFERENCES Persons(PersonID)
	);
	
create table produto values(
	idproduto int,
	preco_unitario numeric(5,2),
	descricao varchar(255),
	PRIMARY KEY(idproduto),
	);
