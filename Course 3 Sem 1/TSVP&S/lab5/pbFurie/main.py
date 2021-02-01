import cmath
import math

def DFT(f, n):
    a = [0.0] * n
    c = 0
    print('\nПрямое преобразование')
    for k in range(n):
        for i in range(n):
            a[k] += cmath.exp(-2 * cmath.pi * 1j * (k * i / n)) * f[i]
            c += 5
        a[k] *= (1 / n)
        print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[a[k].real < 0], abs(a[k].real), '+-'[a[k].imag < 0], abs(a[k].imag)))

    print("C = ", c)
    return a



def DFT_O(a, n):
    c = 0
    f = [0.0] * n
    print('\nОбратное преобразование')
    for k in range(n):
        for i in range(n):
            f[k] += cmath.exp(2 * cmath.pi * 1j * (k * i / n)) * a[i]
            c += 5

    print("C = ", c)
    return f

def PBFT(f, n):
    a = [0] * n
    a2 = [0] * n
    cs = 0
    for k1 in range(p1):
        for j2 in range(p2):
            for j1 in range(p1):
                a[k1 + p1 * j2] += f[j2 + p2 * j1] * cmath.exp(-2 * cmath.pi * 1j * (k1 * j1 / p1))
                cs += 1
            a[k1 + p1 * j2] *= 1 / p1 

    print('Прямое преобразование')
    for k1 in range(p1):
        for k2 in range(p2):
            for j2 in range(p2):
                a2[k1 + p1 * k2] += a[k1 + p1 * j2] * cmath.exp(-2 * cmath.pi * 1j * (j2 / (p1 * p2)) * (k1 + p1 * k2))
                cs += 1
            a2[k1 + p1 * k2] *= 1 / p2 

            print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[a2[k1 + p1 * k2].real < 0], abs(a2[k1 + p1 * k2].real), '+-'[a2[k1 + p1 * k2].imag < 0], abs(a2[k1 + p1 * k2].imag)))
    print('C = ', cs)
    return a2

def PBFT_O(a2, n):
    cs = 0
    f1 = [0] * n
    a1 = [0] * n
    for k1 in range(p1):
        for j2 in range(p2):
            for j1 in range(p1):
                f1[k1 + p1 * j2] += a2[j2 + p2 * j1] * cmath.exp(2 * cmath.pi * 1j * (k1 * j1 / p1))
                cs += 1

    print('Обратное преобразование')
    for k1 in range(p1):
        for k2 in range(p2):
            for j2 in range(p2):
                a1[k1 + p1 * k2] += f1[k1 + p1 * j2] * cmath.exp(2 * cmath.pi * 1j * (j2 / (p1 * p2)) * (k1 + p1 * k2))
                cs += 1
    print ('C = ', cs)
    return a1



size = 5
p2 = int(math.sqrt(size))
while True:
    if size % p2 == 0 :
        break
    else :
        p2 += 1
p1 = size // p2
print('p1 = ', p1)
print('p2 = ', p2)
#a2 = [0.0] * size


f = [0.0] * size
f = [1, 0, 1, 0, 1]
#f = [6, 7, 0, 0, 0]

print('ДПФ')
A_DFT = [0] * size
A_DFT = DFT(f, size)
A_DFT = DFT_O(A_DFT, size)
for i in range(size):
    print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[A_DFT[i].real < 0], abs(A_DFT[i].real), '+-'[A_DFT[i].imag < 0], abs(A_DFT[i].imag)))

print('ПБПФ')

A_PB = [0] * size
A_PB = PBFT(f, size)
A_PB = PBFT_O(A_PB, size)
for i in range(size):
    print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[A_PB[i].real < 0], abs(A_PB[i].real), '+-'[A_PB[i].imag < 0], abs(A_PB[i].imag)))
