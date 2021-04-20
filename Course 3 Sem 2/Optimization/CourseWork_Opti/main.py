from SimpleFrac import SimpleFrac
import math

def print_matrix(matrix, n, m, k):

    print()
    if k == "matrix":
        for i in range(m):
            for j in range(n + 1):
                if j == n:
                    print("|%10s" % matrix[i][j], end='')
                else:
                    print("%10s" % matrix[i][j], end='')
            print()
    elif k == "simplex":
        for i in range(m + 2):
            print("\t", end='')
            for j in range(n + 1):
                if j == 0:
                    print("%10s|" % matrix[i][j], end='')
                else:
                    print("%10s" % matrix[i][j], end='')
            print()
    else:
        print("\nERROR: UNKNOWN SITUATION\n")


def check_m(simplex_list, n):

    k = 0

    for i in range(1, n + 1):
        if simplex_list[i].a > 0:
            k = 1

        elif simplex_list[i].a < 0:
            return 0

    if k == 0 and simplex_list[0].a == 0:
        return 1
    else:
        return 2


def check_z(simplex_list, n):

    k = 0

    for i in range(1, n + 1):
        if simplex_list[i].a < 0:
            return 0

    return 1


def artificial_basis(matrix, n, m, z):

    N = n
    simplex = []
    basis = []

    for i in range(n + m + 1):
        basis.append(i)
    for i in range(n + 1):
        basis[i] = 0

    print("\n", "Этап 1: Расширение матрицы")

    for i in range(m):
        k = 0
        for j in range(m):
            matrix[i].insert(N + k, SimpleFrac())
            if j == i:
                matrix[i][N + k].write(1, 1)
            k += 1

    N += m
    print_matrix(matrix, N, m, "matrix")

    print("\n", "Этап 2: Построение Симплекс-таблицы")

    for i in range(m):
        simplex.append([])
        for j in range(N + 1):
            if j == 0:
                simplex[i].append(matrix[i][N])
            else:
                simplex[i].append(matrix[i][j - 1])

    simplex.append([])
    for j in range(n + 1):
        if j == 0:
            simplex[m].append(z[n])
        else:
            temp = z[j - 1]
            temp.a *= -1
            simplex[m].append(temp)

    for j in range(n + 1, N + 1):
        simplex[m].append(SimpleFrac())

    simplex.append([])
    for j in range(n + 1):
        if j == 0:
            temp = SimpleFrac()
            for i in range(m):
                temp = temp + matrix[i][N]
            temp.a *= -1
            simplex[m + 1].append(temp)
        else:
            temp = SimpleFrac()
            for i in range(m):
                temp = temp + matrix[i][j - 1]
            temp.a *= -1
            simplex[m + 1].append(temp)

    for j in range(n + 1, N + 1):
        simplex[m + 1].append(SimpleFrac())

    print_matrix(simplex, N, m, "simplex")

    print("\n", "Этап 3: Решение методом искуственного базиса")

    print_matrix(simplex, N, m, "simplex")
    # print("\n\t", "BASIS = ", basis)
    while True:

        stop_kof = check_m(simplex[m + 1], n)           # проверка строки M

        if stop_kof == 0:       # если есть отрицательный элемент в строке M
            maxi = SimpleFrac()
            maxi_i = -1
            for j in range(1, N + 1):               # поиск столбца с максимальным по модулю значением в M
                if int(simplex[m + 1][j].a) < 0 and simplex[m + 1][j] < maxi:
                    maxi = simplex[m + 1][j]
                    maxi_i = j

            mini = SimpleFrac()
            mini_i = -1
            k = -1
            for i in range(m):              # поиск опорного элемента, чьё симплексное отношение будет взято как минимальное
                if simplex[i][maxi_i].a > 0 and simplex[i][0].a > 0:
                    mini = simplex[i][0] / simplex[i][maxi_i]
                    k = i
                    break

            if k == -1:
                print("Начинайте паниковать")
                return 1

            for i in range(k, m):           # поиск строки с минимальным сиплексным отношением
                if simplex[i][maxi_i].a > 0 and simplex[i][0].a > 0 and simplex[i][0] / simplex[i][maxi_i] <= mini:
                    mini = simplex[i][0] / simplex[i][maxi_i]
                    mini_i = i

            print("\n\t", "Минимальное СО = (", mini_i, ",", maxi_i, ") = ", simplex[mini_i][0], " / ", simplex[mini_i][maxi_i])

            mini = simplex[mini_i][maxi_i]
            for i in range(N + 1):          # делим строку с минимальным сиплексным отношением на опорный элемент
                simplex[mini_i][i] = simplex[mini_i][i] / mini

            for i in range(m + 2):          # шаг Гаусса
                for j in range(N + 1):
                    if i != mini_i and j != maxi_i:
                        temp_1 = simplex[i][j] * simplex[mini_i][maxi_i]
                        temp_2 = simplex[i][maxi_i] * simplex[mini_i][j]
                        simplex[i][j] = temp_1 - temp_2

            for i in range(m + 2):          # обнуляем столбец с опорным элементом
                if i != mini_i:
                    simplex[i][maxi_i].a = 0
                    simplex[i][maxi_i].b = 1

            if basis[n + 1 + mini_i] >= 0:      # удаление столбца с искусственной переменной и обновление базиса
                # print("\n\t", "DEL = ", basis[n + 1 + mini_i])
                temp_k = basis[n + 1 + mini_i]
                for i in range(m + 2):
                    simplex[i].pop(temp_k)
                N -= 1
                basis[n + 1 + mini_i] = -1
                for i in range(n + 1 + mini_i, n + m + 1):
                    basis[i] -= 1
            basis[mini_i] = maxi_i
            print("BASIS = ", basis)

            print_matrix(simplex, N, m, "simplex")

        elif stop_kof == 1:         # если строка M обнулилась
            break

        elif stop_kof == 2:                 # если матрица не разрешима
            print("\n", "Матрица не разрешима")
            return 1

    print("\n", "Этап 4: Решение симплекс-методом")

    simplex.pop(m + 1)
    print_matrix(simplex, N, m - 1, "simplex")
    while True:
        kof = check_z(simplex[m], N)        # проверяем строку z

        if kof == 0:        # если в строке есть отрицательный элемент
            maxi = SimpleFrac()
            maxi_i = -1
            for j in range(1, N + 1):  # поиск столбца с максимальным по модулю значением в Z
                if int(simplex[m][j].a) < 0 and simplex[m][j] < maxi:
                    maxi = simplex[m][j]
                    maxi_i = j
            mini = SimpleFrac()
            mini_i = -1
            k = -1
            for i in range(m):  # поиск опорного элемента, чьё симплексное отношение будет взято как минимальное
                if simplex[i][maxi_i].a > 0 and simplex[i][0].a > 0:
                    mini = simplex[i][0] / simplex[i][maxi_i]
                    k = i
                    break

            if k == -1:
                print("Начинайте паниковать")
                print("Но сперва проверьте правильно ли записана строка z")
                return 1
            # print("Cur mini = ", mini)
            for i in range(k, m):  # поиск строки с минимальным сиплексным отношением
                if simplex[i][maxi_i].a > 0 and simplex[i][0].a > 0 and simplex[i][0] / simplex[i][maxi_i] <= mini:
                    mini = simplex[i][0] / simplex[i][maxi_i]
                    mini_i = i

            print("\n\t", "Минимальное СО = (", mini_i, ",", maxi_i, ") = ", simplex[mini_i][0], " / ",
                  simplex[mini_i][maxi_i])

            mini = simplex[mini_i][maxi_i]
            for i in range(N + 1):  # делим строку с минимальным сиплексным отношением на опорный элемент
                simplex[mini_i][i] = simplex[mini_i][i] / mini

            for i in range(m + 1):  # шаг Гаусса
                for j in range(N + 1):
                    if i != mini_i and j != maxi_i:
                        temp_1 = simplex[i][j] * simplex[mini_i][maxi_i]
                        temp_2 = simplex[i][maxi_i] * simplex[mini_i][j]
                        simplex[i][j] = temp_1 - temp_2

            for i in range(m + 1):  # обнуляем столбец с опорным элементом
                if i != mini_i:
                    simplex[i][maxi_i].a = 0
                    simplex[i][maxi_i].b = 1

            basis[mini_i] = maxi_i              # записываем новый элемент в базис
            print("\n", "BASIS = ", basis)

            print_matrix(simplex, N, m - 1, "simplex")

        if kof == 1:
            print("Z -> max = Z(", end='')

            for i in range(n):
                k = -1
                for j in range(n):
                    if i + 1 == basis[j] and j <= m:
                        print(simplex[j][0], end='');
                        k = 0
                        break;
                if k != 0:
                    print(0, end='')
                if i != n - 1:
                    print(", ", end='')
            print(") = ", simplex[m][0])
            return 0

    return 1


if __name__ == '__main__':

    matrix = []
    z = []

    print("Количество переменных: ")
    n = int(input())
    print("Количество ограничений: ")
    m = int(input())

    for i in range(m):
        matrix.append([])
        for j in range(n + 1):
            matrix[i].append(SimpleFrac())

    print("Заполните матрицу: ")
    for i in range(m):
        print(i + 1, " столбец")
        for j in range(n + 1):
            matrix[i][j].write(int(input()), 1)

    print('Введите Z: ')
    for i in range(n + 1):
        if i == n:
            print("C = ", end='')
        z.append(SimpleFrac())
        z[i].write(int(input()), 1)

    print("\n", "Ваша матрица:")
    print_matrix(matrix, n, m, "matrix")

    artificial_basis(matrix, n, m, z)
