#include <iostream>

using namespace std;

class SimpleFrac
{
    public:
        SimpleFrac();
        ~SimpleFrac();

        int a, b;

        void FracPlus(SimpleFrac t1, SimpleFrac t2);
        void FracMinus(SimpleFrac t1, SimpleFrac t2);
        void FracMulti(SimpleFrac t1, SimpleFrac t2);
        void FracDiv(SimpleFrac t1, SimpleFrac t2);

};

SimpleFrac::SimpleFrac()
{
    a = 0;
    b = 1;
}

SimpleFrac::~SimpleFrac()
{

}

void SimpleFrac::FracPlus(SimpleFrac t1, SimpleFrac t2)
{
    if (t1.b != t2.b){
        a = t1.a * t2.b + t2.a * t1.b;
        b = t1.b * t2.b;
    }
    else {
        a = t1.a + t2.a;
        b = t1.b;
    }
    
}

void SimpleFrac::FracMinus(SimpleFrac t1, SimpleFrac t2)
{
    if (t1.b != t2.b){
        a = t1.a * t2.b - t2.a * t1.b;
        b = t1.b * t2.b;
    }
    else {
        a = t1.a - t2.a;
        b = t1.b;
    }
}

void SimpleFrac::FracMulti(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.a;
    b = t1.b * t2.b;
}

void SimpleFrac::FracDiv(SimpleFrac t1, SimpleFrac t2)
{
    a = t1.a * t2.b;
    b = t1.b * t2.a;
}

int main()
{
    SimpleFrac **matrix;
    int M, N;

    cout << "Количетсво переменных: ";
    cin >> M;
    cout << "Количество уравнений: ";
    cin >> N;

    matrix = new SimpleFrac* [N];

    for (int i = 0; i < N; i++){
        matrix[i] = new SimpleFrac [M];
    }

    cout << "Заполните матрицу" << endl;

    for (int i = 0; i < N; i++){
        cout << i + 1 << " строка:" << endl; 
        for (int j = 0; j < M; j++){
            cin >> matrix[i][j].a;
        }
    }

    cout << endl << "Ваша матрица:" << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (matrix[i][j].b == 1)
                if (matrix[i][j].a == 0)
                    printf("%4.c", "0"); 
                else
                    printf("%4.d", matrix[i][j].a);
            else if (matrix[i][j].a == 0)
                printf("%4.c", "0");
            else
                printf("%2.d/%2.d", matrix[i][j].a, matrix[i][j].b);
        }
        cout << endl;
    }

    return 0;
}