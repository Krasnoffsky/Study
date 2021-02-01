counterHelp(_X,[],N,N).

counterHelp(X,[X|T],N,Y) :-
    N1 is N+1,
    counterHelp(X,T,N1,Y).

counterHelp(X,[_H|T],N,Y) :-
    counterHelp(X,T,N,Y).

counter(X,List,N) :-
    counterHelp(X,List,0,N).

reader(F1, N):-
        read_line_to_codes(F1,Line),
        counter(32,Line, T),
        T1 is T + 1,
        write("Строка №"),
        write(N),
        write(" содержит "),
        write(T1),
        writeln(" слов "),
        N1 is N + 1,
        (at_end_of_stream, write('') ; reader(F1,N1),!).

second:-
        open('input.txt', read, F1),
        open('output.txt', write, F2),
        set_input(F1),
        set_output(F2),
        reader(F1, 1),
        close(F1),
        close(F2).
        
