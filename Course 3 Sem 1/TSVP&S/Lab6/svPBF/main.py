import cmath
import math
import numpy as np
import random

def sv(a, b, size, n, m):
    c_p = 0
    c_u = 0
    s = 0
    C = [0] * size
    for k in range(size):
        print ("C[", k, "] = ", end= ' ')
        s = 0
        for i in range(n):
            for j in range(m):
                if (i + j == k):
                    if (s != 0): print(" + ", end= ' ')
                    C[k] += a[i] * b[j]
                    c_u += 1
                    c_p += 1
                    s += 1
                    print("(", a[i], "*", b[j], ")", end= ' ')
        c_p -= 1
        print("")

    print("Сложения = ", int(c_p))
    print("Умножения = ", int(c_u))
    return C

def DFT(a, size):
    global ch
    ch = 0
    c = [0] * size
    for k in range(size):
        for j in range(size):
            c[k] += a[j] * cmath.exp(-2 * cmath.pi * 1j * (k * j / (size)))
            ch += 5
        c[k] *= 1 / (size)
#    print("DP = ", int(ch))
    return c


def DFT_1(c, size):
    global ch
    ch = 0
    a = [0] * size
    for k in range(size):
        for j in range(size):
            a[k] += c[j] * cmath.exp(2 * cmath.pi * 1j * (k * j / (size)))
            ch += 5
#    print("DO = ", ch)
    return a


def PBFT(f, p1, p2, size):
    global ch
    ch = 0
    a = [0] * size
    a2 = [0] * size

    for k1 in range(p1):
        for j2 in range(p2):
            for j1 in range(p1):
                a[k1 + p1 * j2] += f[j2 + p2 * j1] * cmath.exp(-2 * cmath.pi * 1j * (k1 * j1 / p1))
                ch += 1
            a[k1 + p1 * j2] *= 1 / p1

    for k1 in range(p1):
        for k2 in range(p2):
            for j2 in range(p2):
                a2[k1 + p1 * k2] += a[k1 + p1 * j2] * cmath.exp(-2 * cmath.pi * 1j * (j2 / (p1 * p2)) * (k1 + p1 * k2))
                ch += 1
            a2[k1 + p1 * k2] *= 1 / p2
#    print("PP = ", ch)
    return a2


def PBFT_O(a2, p1, p2, size):
    global ch
    ch = 0
    f1 = [0] * p1 * p2
    a1 = [0] * p1 * p2

    # print('Массив А1')
    for k1 in range(p1):
        for j2 in range(p2):
            for j1 in range(p1):
                f1[k1 + p1 * j2] += a2[j2 + p2 * j1] * cmath.exp(2 * cmath.pi * 1j * (k1 * j1 / p1))
                ch += 1

    # print('Массив А2')
    for k1 in range(p1):
        for k2 in range(p2):
            for j2 in range(p2):
                a1[k1 + p1 * k2] += f1[k1 + p1 * j2] * cmath.exp(2 * cmath.pi * 1j * (j2 / (p1 * p2)) * (k1 + p1 * k2))
                ch += 1
#    print("PO = ", ch)
    return a1


n = 512
m = 512

size1 = m + n - 1
C1 = [0] * size1

a = [0] * n
b = [0] * m

for i in range(n):
    a[i] = random.randint(0, 100)

for i in range(m):
    b[i] = random.randint(0, 100)
#a = [1, 2, 3]
#b = [9, 8, 7, 6, 5]
'''
print(a)
print(b)
print("Обычная свертка: ")
C1 = sv(a, b, size1, n, m)

for i in range(size1):
    print(C1[i])
'''
if n >= m:
    size = 2 * n
else:
    size = 2 * m
for i in range(n, size):
    a.append(0)

for i in range(m, size):
    b.append(0)
result = 0
print("Свертка с помощью ДПФ: ")
C_DFT = [0] * (size)
a_df = [0] * (size)
b_df = [0] * (size)
a_df = DFT(a, size)
result += ch
b_df = DFT(b, size)
result += ch
co = 0

# C_DFT = DFT(a, b, size)
for k in range(size):
    C_DFT[k] = a_df[k] * b_df[k]
    C_DFT[k] *= size
    result += 1
print("count = ", co)
C_DFT = DFT_1(C_DFT, size)
result += ch
print ("Операции = ", result)

result = 0
'''
for i in range(size1):
    print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[C_DFT[i].real < 0], abs(C_DFT[i].real), '+-'[C_DFT[i].imag < 0], abs(C_DFT[i].imag)))
'''
#print(size)



p1 = int(math.sqrt(size))
while True:
    if size % p1 == 0:
        break
    else:
        p1 += 1
p2 = size // p1

print("Свертка с помощью ПБПФ:")
print(" p1 = ", p1, "p2 = ", p2)
count = 0
a_pb = [0.0] * size
b_pb = [0.0] * size
C = [0.0] * size
a_pb = PBFT(a, p1, p2, size)
result += ch
b_pb = PBFT(b, p1, p2, size)
result += ch
for k in range(size):
    C[k] = a_pb[k] * b_pb[k]
    C[k] *= size
    result += 1
#print("count = ", count)
C = PBFT_O(C, p1, p2, size)
result += ch
print("Операции = ", result)


'''
for i in range(size1):
    print('({0} {1:.2f} {2} {3:.2f}i)'.format('  '[C[i].real < 0], abs(C[i].real), '+-'[C[i].imag < 0], abs(C[i].imag)))
'''
