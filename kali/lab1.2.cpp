#include <iostream>
#include <format>

using namespace std;

int main() {
    int mp = 1;
    int num;

    cout << "+- ЛР № 1 -------------------+\n";
    cout << "│  Группа: 6111              |\n";
    cout << "│   Автор: Борисик Мирон     │\n";
    cout << "│ Вариант: 2                 │\n";
    cout << "+----------------------------+\n";

    cout << "\nВведите числа (для завершения введите 0): \n";
    int count = 0;
    while (true) {
        cin >> num;
        if (num == 0) break;
        mp *= num;
        count++;
    }

    cout << format("+- Ответ ---------------------------------+\n");
    cout << format("│ Количество элементов: {:<11}       │\n", count);
    cout << format("│   Произведение чисел: {:<11}       │\n", mp);
    cout << format("+-----------------------------------------+\n");
    
    return 0;
}
