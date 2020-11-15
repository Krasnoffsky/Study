(MAPCAR (LAMBDA(x)
(COND
((NUMBERP x)'*)
(t x)
)) '(A B 6 C 7 8 D ))
