#include <iostream>
#include <stdlib.h>
#include <time.h>

int y;
int x;

int main() {
    std::srand(time(NULL));

    std::cout << "Input length of rows -> ";
    bool b = true;
    while (b) {
        std::cin >> y;
        if (std::cin.fail() || y <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again -> ";
        }
        else {
            b = false;
        }
    }

    b = true;

    std::cout << "Input length of columns -> ";
    while (b) {
        std::cin >> x;
        if (std::cin.fail() || x <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please try again -> ";
        }
        else {
            b = false;
        }
    }

    int** arr = new int* [y]; // Создание динамической матрицы

    for (int i = 0; i < y; i++) {
        arr[i] = new int[x];
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            arr[i][j] = std::rand() % 10; // Заполнение динамической матрицы
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }

    std::cout << '\n';
    std::cout << '\n';

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            std::cout << arr[i][j] << '\t';
        }
        std::cout << '\n';
    }

    // Седловые точки
    for (int i = 0; i < y; i++) {
        int minInRow = arr[i][0];
        int colIndex = 0;

        // Находим минимум в текущей строке
        for (int j = 1; j < x; j++) {
            if (arr[i][j] < minInRow) {
                minInRow = arr[i][j];
                colIndex = j;
            }
        }

        bool isSaddlePoint = true;
        // Проверяем, является ли минимум в строке максимумом в столбце
        for (int k = 0; k < y; k++) {
            if (arr[k][colIndex] > minInRow) {
                isSaddlePoint = false;
                break;
            }
        }

        // Если элемент оказался седловой точкой, выводим его
        if (isSaddlePoint) {
            std::cout << "Saddle point found at matrix[" << i << "][" << colIndex << "]: " << minInRow << std::endl;
        }
    }

    for (int i = 0; i < y; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
