#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void reversePart(int a[], int left, int right) {
    while (left < right) {
        swap(a[left], a[right]);
        left++;
        right--;
    }
}

// Задача 1
// Три разворота занимают O(n) времени и O(1) дополнительной памяти.
void rotateRight(int a[], int n, int k) {
    if (n == 0) return;
    k %= n;
    if (k < 0) k += n;

    reversePart(a, 0, n - 1);
    reversePart(a, 0, k - 1);
    reversePart(a, k, n - 1);
}

// Задача 2
void mergeArrays(const int a[], int n, const int b[], int m, int result[]) {
    int i = 0, j = 0, pos = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            result[pos++] = a[i++];
        } else {
            result[pos++] = b[j++];
        }
    }
    while (i < n) result[pos++] = a[i++];
    while (j < m) result[pos++] = b[j++];
}

// Задача 3
// Заполняем с конца, чтобы не перезаписать ещё не обработанные числа.
void mergeInPlace(int a[], int n, const int b[], int m) {
    int i = n - 1;
    int j = m - 1;
    int pos = n + m - 1;
    while (j >= 0) {
        if (i >= 0 && a[i] > b[j]) {
            a[pos--] = a[i--];
        } else {
            a[pos--] = b[j--];
        }
    }
}

// Задача 4
// Один проход по массиву — O(n).
void sortZerosOnes(int a[], int n) {
    int nextZero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            swap(a[i], a[nextZero]);
            nextZero++;
        }
    }
}

// Задача 5
// Слева от low — нули, между low и mid — единицы, справа от high — двойки.
void sortColors(int a[], int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

// Задача 6
// Чётные числа перемещаются по очереди, поэтому их порядок сохраняется.
void evensFirst(int a[], int n) {
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            swap(a[i], a[pos]);
            pos++;
        }
    }
}

// Задача 7
// Ненулевые элементы сохраняют порядок, так как записываются последовательно. Сложность O(n).
void moveZerosToEnd(int a[], int n) {
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[pos] = a[i];
            pos++;
        }
    }
    while (pos < n) {
        a[pos] = 0;
        pos++;
    }
}

int main() {
    cout << "1. Сдвиг массива: ";
    int a1[] = {1, 2, 3, 4, 5, 6, 7};
    rotateRight(a1, 7, 3);
    printArray(a1, 7);

    cout << "2. Слияние массивов: ";
    int a2[] = {3, 8, 10, 11};
    int b2[] = {1, 7, 9};
    int result[7];
    mergeArrays(a2, 4, b2, 3, result);
    printArray(result, 7);

    cout << "3. Слияние без дополнительного массива: ";
    int a3[] = {3, 8, 10, 11, 0, 0, 0};
    int b3[] = {1, 7, 9};
    mergeInPlace(a3, 4, b3, 3);
    printArray(a3, 7);

    cout << "4. Сортировка 0 и 1: ";
    int a4[] = {1, 0, 1, 0, 0, 1, 0};
    sortZerosOnes(a4, 7);
    printArray(a4, 7);

    cout << "5. Флаг Нидерландов: ";
    int a5[] = {2, 0, 2, 1, 1, 0};
    sortColors(a5, 6);
    printArray(a5, 6);

    cout << "6. Чётные в начало: ";
    int a6[] = {3, 2, 4, 1, 11, 8, 9};
    evensFirst(a6, 7);
    printArray(a6, 7);

    cout << "7. Нули в конец: ";
    int a7[] = {0, 5, 0, 3, 0, 7, 2};
    moveZerosToEnd(a7, 7);
    printArray(a7, 7);
    return 0;
}
