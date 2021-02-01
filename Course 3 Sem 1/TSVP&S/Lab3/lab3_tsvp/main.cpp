#include <ctime>
#include <iostream>
int c = 0, m = 0;
using namespace std;

template <class T>
T* merge(T *arr1, T* arr2, int l, int r) {
    T* temp = new T[l+r];
    int n = 0;

    while (l && r) {
        if (*arr1 < *arr2) {
            temp[n] = *arr1;
            arr1++;
            l--;
        } else {
            temp[n] = *arr2;
            arr2++;
            r--;
        }
        c++;
        m++;
        n++;
    }

    if (l == 0) {
        for (int i = 0; i < r; i++) {
            temp[n++] = *arr2++;
            m++;
        }
    }

    else {
        for (int i=0; i < l; i++) {
            temp[n++] = *arr1++;
            m++;
        }
    }
    return temp;
}

template <class T>
void mergeSort(T * mas, int len) {
    int n = 1, l, ost;
    T * mas1;
    while (n < len) {
        l = 0;
        while (l < len) {
            if (l + n >= len) break;
            ost = (l + n * 2 > len) ? (len - (l + n)) : n;
            mas1 = merge(mas + l, mas + l + n, n, ost);
            for (int i=0; i < n + ost; i++){

                mas[l + i] = mas1[i];
                cout << mas1[i] << " ";
            }
            delete [] mas1;
            l += n * 2;
            //cout << endl;
        }
        n *= 2;
        cout << "------" <<endl;
    }
}

int main() {
    srand(time(0));
    int n;
    cout << "Input array size: ";
    cin >> n;
    int *array = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << "Start Massive: ";
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    mergeSort(array, n);
    for(int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    cout << endl << c << " " << m;
}
