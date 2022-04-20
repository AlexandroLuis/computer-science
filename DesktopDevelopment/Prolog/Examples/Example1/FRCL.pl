oposto(e,w).
oposto(w,e).

mover(
	[F1,W,G,C],
	[F2,W,G,C]) 
	:-  oposto(F1,F2),
		certo([F2,W,G,C]).
		
mover(
	[S1,S1,G,C],
	[S2,S2,G,C]) 
	:-  oposto(S1,S2),
		certo([S2,S2,G,C]). 
		
mover(
	[S1,W,S1,C],
	[S2,W,S2,C]) 
	:-  oposto(S1,S2),
		certo([S2,W,S2,C]). 
		
mover(
	[S1,W,G,S1],
	[S2,W,G,S2]) 
	:-  oposto(S1,S2),
		certo([S2,W,G,S2]). 

certo(
	[F,W,G,C]) 
	:- \+(uncerto([F,W,G,C])). 

uncerto(
	[S1,S2,S2,_]) 
	:- oposto(S1,S2). 
	
uncerto(
	[S1,_,S2,S2]) 
	:- oposto(S1,S2).

solucao([[w,w,w,w]]). 
solucao(
	[estado1, estado2 | Tail]) 
	:- mover(
		estado1, 
		estado2), 
			solucao(
				[estado2|Tail]
			). 

puzzle(
	[inicio|EstadoLista]) 
	:- 
	inicio = [e,e,e,e], 
	length(EstadoLista,L), 
	L<8, solucao(
		[inicio|EstadoLista]), 
		printsolucao(
			[inicio|EstadoLista]),!. 

printsolucao([X|Y]) 
	:-  write('inicio. '), 
		writeLocation(X),
		!,
		PrintMovimentos([X|Y]), 
		write('Solved.\n').
		
writeLocation(X) 
	:-  getList(X, e, E), 
		getList(X, w, W), 
		write('East: '), 
		writeList(E), 
		write('West: '), 
		writeList(W), 
		write('\n').

getList([],_,[]).

getList(
	[H],
	H,
	[cabbage|L]) 
		:-  length([H],N), 
		N=1, 
		getList(Tail,H,L).
		
getList(
	[H|Tail],
	H,
	[goat|L]) 
		:-  length([H|Tail],N), 
			N=2, 
			getList(Tail,H,L).
		
getList(
	[H|Tail],
	H,
	[wolf|L]) 
		:-  length([H|Tail],N), 
			N=3, 
			getList(Tail,H,L).
getList(
	[H|Tail],
	H,
	[farmer|L]) 
		:-  length([H|Tail],N), 
			N=4, 
			getList(Tail,H,L).
getList(
	[H|Tail],
	Z,
	L) 
		:-  \+ (H=Z), 
			getList(Tail, Z, L).

writeList([]). 
writeList([X]) 
	:-  write(X), 
		write(' ').
		
writeList([H|L]) 
	:-  write(H), 
		write(', '), 
		writeList(L).

% Mostrar Os Movimentos
PrintMovimentos([]).
PrintMovimentos([_]).

PrintMovimentos([X, Y|Z]) 
	:-  X = [A, B, C, D], 
		Y = [E, B, C, D], 
		oposto(A, E), 
		write('Fazendeiro vai sozinho. '), 
		writeLocation(Y), 
		PrintMovimentos([Y|Z]).

PrintMovimentos([X, Y|Z]) 
	:-  X = [A, A, C, D], 
		Y = [E, E, C, D], 
		oposto(A, E), 
		write('Fazendeiro leva o lobo. '), 
		writeLocation(Y), 
		PrintMovimentos([Y|Z]).

PrintMovimentos([X, Y|Z]) 
	:-  X = [A, B, A, D], 
		Y = [E, B, E, D], 
		oposto(A, E), 
		write('Fazendeiro leva a cabra. '), 
		writeLocation(Y), 
		PrintMovimentos([Y|Z]).

PrintMovimentos([X, Y|Z]) 
	:-  X = [A, B, C, A], 
		Y = [E, B, C, E], 
		oposto(A, E), 
		write('Fazendeiro leva o repolho. '), 
		writeLocation(Y), 
		PrintMovimentos([Y|Z]).
