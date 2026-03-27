#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;
const int N = 6;
void PrintMatrix(int matrix[N][N], const string& title) {
    cout << title << ":" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void Shimbell(int original[N][N], int steps, const string& mode) {
    int current[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            current[i][j] = original[i][j];
        }
    }
    cout << "Пути длины 1 (исходная матрица):" << endl;
    PrintMatrix(current, "Шаг 1");
    for (int step = 2; step <= steps; step++) {
        int result[N][N] = {0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    int res;
                    if (current[i][k] == 0 || original[k][j]==0){
                        res = 0;
                    }
                    else{
                        res = current[i][k] + original[k][j];
                    }
                    if (mode == "max") {
                        if (res > result[i][j]) {
                            result[i][j] = res;
                        }
                    } else {
                        if (result[i][j]==0 || res < result[i][j]&& res!=0) {
                            result[i][j] = res;
                        } 
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                current[i][j] = result[i][j];
            }
        }
        cout << "Пути длины " << step << ":" << endl;
        PrintMatrix(current, "Шаг " + to_string(step));
    }
    cout << "РЕЗУЛЬТАТ (пути длины " << steps << "):" << endl;
    PrintMatrix(current, "Финальная матрица");
}

int main() {
    // int matrix[N][N] = {
    //     {0, 2, 3, 4, 0, 0},
    //     {2, 0, 0, 0, 2, 5},
    //     {3, 0, 0, 0, 3, 0},
    //     {4, 0, 0, 0, 6, 0},
    //     {0, 2, 3, 6, 0, 1},
    //     {0, 5, 0, 0, 1, 0}
    // };
    int matrix[N][N] = {
        {0, 1, 0, 3, 0, 0},
        {1, 0, 5, 0, 2, 0},
        {0, 5, 0, 0, 0, 3},
        {6, 0, 0, 0, 0, 0},
        {0, 2, 0, 0, 0, 4},
        {0, 0, 1, 0, 4, 0}
    };
    // int matrix[N][N] = {
    //     {0, 0, 0, 3, 0, 0},
    //     {1, 0, 0, 0, 2, 0},
    //     {0, 0, 0, 0, 0, 0},
    //     {6, 0, 0, 0, 0, 0},
    //     {0, 2, 0, 0, 0, 0},
    //     {0, 0, 0, 0, 4, 0}
    // };
    // int matrix[N][N] = {
    //     {0, 2, 0, 6, 0, 0},
    //     {0, 0, 3, 0, 2, 0},
    //     {4, 0, 0, 0, 0, 1},
    //     {0, 0, 5, 0, 0, 0},
    //     {0, 6, 0, 2, 0, 0},
    //     {8, 0, 0, 0, 4, 0}
    // };
    cout << "Исходная матрица смежности (6x6):" << endl;
    PrintMatrix(matrix, "Исходная матрица");
    string mode;
    cout << "Введите направление поиска (min или max): ";
    cin >> mode;
    if (mode != "min" && mode != "max") {
        cout << "Ошибка: введите min или max" << endl;
        return 1;
    }
    int steps;
    cout << "Введите количество переходов (положительное целое число): ";
    cin >> steps;
    if (steps <= 0) {
        cout << "Ошибка: количество переходов должно быть положительным" << endl;
        return 1;
    }
    Shimbell(matrix, steps, mode);
    return 0;
}