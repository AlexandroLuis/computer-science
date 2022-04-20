rainha(N, rainha) :-
    length(rainha, N),
	tabuleiro(rainha, tabuleiro, 0, N, _, _),
	rainha(tabuleiro, 0, rainha).

tabuleiro([], [], N, N, _, _).
tabuleiro([_|rainha], [Col-Vars|tabuleiro], Col0, N, [_|VR], VC) :-
	Col is Col0+1,
	functor(Vars, f, N),
	constraints(N, Vars, VR, VC),
	tabuleiro(rainha, tabuleiro, Col, N, VR, [_|VC]).

constraints(0, _, _, _) :- !.
constraints(N, Row, [R|Rs], [C|Cs]) :-
	arg(N, Row, R-C),
	M is N-1,
	constraints(M, Row, Rs, Cs).

rainha([], _, []).
rainha([C|Cs], Row0, [Col|Solution]) :-
	Row is Row0+1,
	select(Col-Vars, [C|Cs], tabuleiro),
	arg(Row, Vars, Row-Row),
	rainha(tabuleiro, Row, Solution).


/** Para Chamar a Função Use: "rainha(8, rainha)." **/
