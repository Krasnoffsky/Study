#include <iostream>
#include <cmath>

using namespace std;

int lab4(int num1, int num2)
{
    int i = 10, j = 1, k = 10, res = 0;
    long int result = 0;
    int temp_num2, swap, temp_num1;
    int temp_res = 0;
    int buf;
    int U = 0, S = 0;
    int counter = 0;

    if (num2 > num1){
        swap = num1;
        num1 = num2;
        num2 = swap;
    }

    temp_num1 = num1;
    counter = num1;

    do {
        temp_num2 = num2 % 10;
        buf = 0;
        do {
            temp_res = ((temp_num1 % 10) * temp_num2) % 10;
            if (temp_num1 % 10 == 0 || temp_num2 == 0){
                U += 0;
            } else {
                U++;
            }

            res += (temp_res + buf) * j;
            buf = (int)((temp_num1 % 10) * temp_num2 / 10);
            temp_res = 0;
            i *= 10;
            j *= 10;
            temp_num1 = (int)(temp_num1 / 10);
        } while (temp_num1 != 0);

        cout << "Res = " << res + buf * j << endl;
        temp_num1 = num1;
        num2 = (int)(num2 / 10);
        result += (res + buf * j) * k / 10;
        if (res + buf * j != 0)
            S++;
        res = 0;
        k *= 10;
        i = 10;
        j = 1;
        counter = (int)(counter / 10);

    } while (counter != 0);
    S -= 1;


    cout << "S = " << S << endl;
    cout << "U = " << U << endl;
    return result;
}

int main(void)
{
    int num1, num2, result;

    cout << "Input Num 1: ";
    cin >> num1;
    cout << "Input Num 2: ";
    cin >> num2;

    result = lab4(num1, num2);

    cout << "Result = " << result << endl;

    return 0;
}
