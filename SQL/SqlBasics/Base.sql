CREATE TABLE Fatura(
	IdP integer,
	parcela integer,
	DTVencimento date not null,
	DTPagamento date,
	Valor numeric(14,2) check (valor > 0),
	constraint FK_IdPFatura foreign key (IdP) references Passagem(IdP) on delete no action on update cascade,
	primary key(IdP, parcela)
);	
alter table Passagem add column cnpj varchar(20) not null; 
alter table Fatura alter column DTVencimento drop default; 
drop table Empresa; 
insert into Aeroporto VALUES('', 'HAHA', 'op', 'nome', 'AC'); 
update Aviao set modelo = 'Fokker 100', numPoltronas = 202 where aviaoId = 8976; 
delete from Fatura where IdP = 356 and parcela = 2; 
select e.nome from Empresa e where e.nome ~*'[^aeiou]$' ;
select a.nome from Aeroporto a where a.nome ~* '^[a-j]'; 
select p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Aeroporto a on a.aeroportoId=pa.aeroportoPartida where a.cidade = 'Curitiba' intersect select p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Aeroporto a on a.aeroportoId=pa.aeroportoPartida where a.cidade = 'São Paulo'; 
select p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Aviao a on a.aviaoId=pa.aviaoId except select p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Aviao a on a.aviaoId=pa.aviaoId where a.modelo = 'Vickers VC-10'; 
select e.nome, a.aviaoId, a.numPoltronas from Aviao a join Empresa e on e.empresaId=a.empresaId where a.numPoltronas = 80 union select e.nome, a.aviaoId, a.numPoltronas from Aviao a join Empresa e on e.empresaId=a.empresaId where a.numPoltronas = 120;
select p.passageiroId, p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Fatura f on pa.IdP=f.IdP except select p.passageiroId, p.nome from Passageiro p join Passagem pa on p.passageiroId=pa.passageiroId join Fatura f on pa.IdP=f.IdP where (f.DTVencimento < current_date and f.DTPagamento = NULL); 
