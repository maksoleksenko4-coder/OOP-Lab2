#include <iostream>
#include "Bitstring.h"
#include <Windows.h>

using namespace std;

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bitstring b1, b2;
    int choice;
    int shift_n;

    cout << "Ініціалізація першого рядка (b1)" << endl;
    b1.Read();

    cout << "\nІніціалізація другого рядка (b2) за замовчуванням (через Init)" << endl;
    
    b2.Init(0xAAAAAAAA, 0xFFFFFFFF);

    do {
        cout << "\nМеню" << endl;
        cout << "Рядок 1 (b1): "; b1.Display();
        cout << "Рядок 2 (b2): "; b2.Display();
        cout << "1. Операція AND (b1 & b2)\n";
        cout << "2. Операція OR (b1 | b2)\n";
        cout << "3. Операція XOR (b1 ^ b2)\n";
        cout << "4. Операція NOT для b1 (~b1)\n";
        cout << "5. Зсув вліво для b1\n";
        cout << "6. Зсув вправо для b1\n";
        cout << "0. Вийти з програми\n";
        cout << "Оберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Результат AND: ";
            b1.And(b2).Display();
            break;
        case 2:
            cout << "Результат OR:  ";
            b1.Or(b2).Display();
            break;
        case 3:
            cout << "Результат XOR: ";
            b1.Xor(b2).Display();
            break;
        case 4:
            cout << "Результат NOT: ";
            b1.Not().Display();
            break;
        case 5:
            cout << "На скільки бітів зсунути вліво? ";
            cin >> shift_n;
            cout << "Результат зсуву: ";
            b1.shiftleft(shift_n).Display();
            break;
        case 6:
            cout << "На скільки бітів зсунути вправо? ";
            cin >> shift_n;
            cout << "Результат зсуву: ";
            b1.shiftright(shift_n).Display();
            break;
        case 0:
            cout << "Вихід...\n";
            break;
        default:
            cout << "Невірний вибір! Спробуйте ще раз.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}