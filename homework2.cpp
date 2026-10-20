#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* createList(const int a[], int n) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        Node* node = new Node{a[i], nullptr};
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << '\n';
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

// Задача 1
// Меняем направление ссылок, переходя к следующему узлу. O(n).
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Задача 2
// fast идёт вдвое быстрее slow, поэтому slow останавливается в середине.
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Задача 3
// dummy помогает удалить голову; остальные узлы исключаем через prev->next.
Node* removeValue(Node* head, int val) {
    Node dummy{0, head};
    Node* prev = &dummy;
    Node* current = head;

    while (current != nullptr) {
        if (current->value == val) {
            prev->next = current->next;
            delete current;
            current = prev->next;
        } else {
            prev = current;
            current = current->next;
        }
    }
    return dummy.next;
}

// Задача 4
// Символы a должны встретиться в b в том же порядке.
bool isSubsequence(const string& a, const string& b) {
    int i = 0;
    int n = a.size();
    int m = b.size();
    for (int j = 0; j < m && i < n; j++) {
        if (a[i] == b[j]) {
            i++;
        }
    }
    return i == n;
}

// Задача 5
// Сдвигаем левый или правый указатель; каждый делает не более n шагов: O(n).
bool hasPair(const int a[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left < right) {
        long long sum = 0LL + a[left] + a[right];
        if (sum == target) {
            return true;
        }
        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

// Задача 6
// Сравниваем символы с краёв к центру за O(n).
bool isPalindrome(const string& s) {
    int left = 0;
    int right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Задача 7
// read ищет уникальные элементы, write перезаписывает повторы в исходном массиве.
int removeDuplicates(int a[], int n) {
    if (n == 0) {
        return 0;
    }
    int write = 1;
    for (int read = 1; read < n; read++) {
        if (a[read] != a[write - 1]) {
            a[write] = a[read];
            write++;
        }
    }
    return write;
}

// Задача 8
// Соединяем существующие узлы по возрастанию за O(n + m).
Node* mergeLists(Node* a, Node* b) {
    Node dummy{0, nullptr};
    Node* tail = &dummy;
    while (a != nullptr && b != nullptr) {
        if (a->value <= b->value) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != nullptr) {
        tail->next = a;
    } else {
        tail->next = b;
    }
    return dummy.next;
}

int main() {
    cout << "Задача 1. Разворот списка: ";
    int a1[] = {1, 2, 3, 4};
    Node* list1 = createList(a1, 4);
    list1 = reverseList(list1);
    printList(list1);
    deleteList(list1);

    cout << "Задача 2. Середина списка: ";
    int a2[] = {3, 8, 9, 6, 11, 16, 17};
    Node* list2 = createList(a2, 7);
    Node* mid = middleNode(list2);
    if (mid != nullptr) {
        cout << mid->value << '\n';
    } else {
        cout << "Список пуст\n";
    }
    deleteList(list2);

    cout << "Задача 3. Удаление числа 3: ";
    int a3[] = {3, 1, 3, 2, 3, 4};
    Node* list3 = createList(a3, 6);
    list3 = removeValue(list3, 3);
    printList(list3);
    deleteList(list3);

    cout << "Задача 4. Строка является подпоследовательностью: ";
    cout << (isSubsequence("abd", "uabqd") ? "Да" : "Нет") << '\n';

    cout << "Задача 5. Пара с суммой 25 существует: ";
    int a5[] = {3, 8, 9, 11, 16, 18, 19, 21};
    cout << (hasPair(a5, 8, 25) ? "Да" : "Нет") << '\n';

    cout << "Задача 6. Слово является палиндромом: ";
    cout << (isPalindrome("level") ? "Да" : "Нет") << '\n';

    cout << "Задача 7. Массив без повторений: ";
    int a7[] = {1, 1, 2, 2, 2, 4, 5, 5};
    int newSize = removeDuplicates(a7, 8);
    printArray(a7, newSize);

    cout << "Задача 8. Объединённый список: ";
    int a8[] = {3, 6, 8};
    int b8[] = {4, 7, 9, 11};
    Node* first = createList(a8, 3);
    Node* second = createList(b8, 4);
    Node* merged = mergeLists(first, second);
    printList(merged);
    deleteList(merged);
    return 0;
}
