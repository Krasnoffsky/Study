class SimpleFrac:
    a = 0
    b = 1

    def __init__(self):
        self.a = 0
        self.b = 1

    def write(self, x: int, y: int):
        self.a = x
        self.b = y

    def __str__(self):
        if self.b != 1:
            return '{}/{}'.format(int(self.a), int(self.b))
        else:
            return '{}'.format(int(self.a))

    def sf_reduce(self):
        temp_a = abs(self.a)
        temp_b = abs(self.b)

        if self.a == 0:
            return self

        while temp_a != temp_b:
            if temp_a > temp_b:
                tmp = temp_a
                temp_a = temp_b
                temp_b = tmp
            temp_b = temp_b - temp_a

        self.a /= temp_a
        self.b /= temp_a

        return self

    def __add__(self, other):
        result = SimpleFrac()
        result.a = self.a * other.b + other.a * self.b
        result.b = self.b * other.b

        if result.b < 0:
            result.a *= -1
            result.b *= -1

        if result.a == 0:
            result.b = 1

        result.sf_reduce()

        return result

    def __sub__(self, other):
        result = SimpleFrac()
        result.a = self.a * other.b - other.a * self.b
        result.b = self.b * other.b
        if result.b < 0:
            result.a *= -1
            result.b *= -1

        if result.a == 0:
            result.b = 1

        result.sf_reduce()

        return result

    def __mul__(self, other):
        result = SimpleFrac()
        temp1 = SimpleFrac()
        temp2 = SimpleFrac()

        temp1.a = self.a
        temp1.b = other.b
        temp2.a = other.a
        temp2.b = self.b
        temp1.sf_reduce()
        temp2.sf_reduce()
        result.a = temp1.a * temp2.a
        result.b = temp1.b * temp2.b

        if result.b < 0:
            result.a *= -1
            result.b *= -1

        if result.a == 0:
            result.b = 1

        result.sf_reduce()

        return result

    def __truediv__(self, other):
        result = SimpleFrac()
        temp1 = SimpleFrac()
        temp2 = SimpleFrac()

        temp1.a = self.a
        temp1.b = other.a
        temp2.a = other.b
        temp2.b = self.b
        temp1.sf_reduce()
        temp2.sf_reduce()
        result.a = temp1.a * temp2.a
        result.b = temp1.b * temp2.b

        if result.b < 0:
            result.a *= -1
            result.b *= -1

        if result.a == 0:
            result.b = 1

        result.sf_reduce()

        return result

    def __gt__(self, other):
        result = self - other
        if result.a > 0:
            return True
        else:
            return False

    def __ge__(self, other):
        result = self - other
        if result.a > 0:
            return True
        else:
            return False

    def __lt__(self, other):
        result = self - other
        if result.a < 0:
            return True
        else:
            return False

    def __le__(self, other):
        result = self - other
        if result.a <= 0:
            return True
        else:
            return False

    def __abs__(self):
        if self.a < 0:
            self.a *= -1
        return self
