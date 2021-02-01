occurencesHelp(_X,[],N,N).

occurencesHelp(X,[X|T],N,Y) :-
    N1 is N+1,
    occurencesHelp(X,T,N1,Y).

occurencesHelp(X,[_H|T],N,Y) :-
    occurencesHelp(X,T,N,Y).

occurences(X,List,N) :-
    occurencesHelp(X,List,0,N),
    append([X],[N], NewList),
    write(NewList),
    write(" ").

first([]).
first(List):-
    _List1 = [H|List],
    occurences(H, List, _N),
	delete(List, H, List2),
    first(List2).
