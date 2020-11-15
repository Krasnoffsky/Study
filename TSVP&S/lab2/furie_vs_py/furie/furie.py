
import numpy as np
import cmath

def FurieDiscrete(f, a):
    temp = 0.0
    c = 0
    print('\nПрямое преобразование')
    for k in range(n):
        for i in range(n):
            temp += cmath.exp(-2 * cmath.pi * 1j * (k * i / n)) * f[i]
            c += 5
        a[k] = (1 / n) * temp
        temp = 0
        print(round(a[k].real, 4) + round(a[k].imag, 4) * 1j)
    print(c)
    FurieDiscreteReverse(a, f)


def FurieDiscreteReverse(a, f):
    temp = 0.0
    c = 0
    #print (a)
    f = [0.0] * n
    print('\nОбратное преобразование')
    for k in range(n):
        for i in range(n):
            temp += cmath.exp(2 * cmath.pi * 1j * (k * i / n)) * a[i]
            c += 5
        f[k] =  temp
        temp = 0
        print(round(f[k].real, 4)+  round(f[k].imag, 4) * 1j)
    print(c)


n = 5

a = [0.0] * n
f = [0.0] * n
f = [1, 0, 1, 0, 1]
print('Изначальный массив')
for i in range(n):
    print(f[i])

FurieDiscrete(f, a)
