create database PROVA;
use PROVA;
create table PROVA1(cod int, nome var_char(30));
load data local infile 'Área de Trabalho/dados.csv' into table PROVA1 fields terminated by ',' lines terminated by '\n'(cod,nome);
select * from PROVA1;
insert into PROVA1(cod, nome) values (5001, 'Debora');
delete from PROVA1 where id =11;
update PROVA1 set cod= '5001', nome='Marcos A Bronosky' WHERE id = 10;
