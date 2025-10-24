#include <iostream>
#include <vector>
using namespace std;
bool isReflexive(const vector<vector<bool>>& matrix);
bool isAntireflexive(const vector<vector<bool>>& matrix);
bool isSymmetric(const vector<vector<bool>>& matrix);
bool isAntisymmetric(const vector<vector<bool>>& matrix);
bool isAsymmetric(const vector<vector<bool>>& matrix);
bool isTransitive(const vector<vector<bool>>& matrix);
bool isConnected(const vector<vector<bool>>& matrix);
void printMatrix(const vector<vector<bool>>& matrix);

void PartialOrder(bool antisymmetric,bool transitive,bool reflexive,bool antireflexive, bool connected){
    bool a1 = antireflexive && antisymmetric && transitive && connected;
    bool a2 = antireflexive && antisymmetric && transitive;
    bool a3 = reflexive && antisymmetric && transitive && connected;
    bool a4 = reflexive && antisymmetric && transitive;
    cout << "Отношение строгого полного порядка: " << (a1 ? "ДА" : "НЕТ") << endl;
    cout << "Отношение строгого частичного порядка: " << (a2 ? "ДА" : "НЕТ") << endl;
    cout << "Отношение нестрогого полного порядка: " << (a3 ? "ДА" : "НЕТ") << endl;
    cout << "Отношение нестрогого частичного порядка: " << (a4 ? "ДА" : "НЕТ") << endl;
}

int main() {
    vector<vector<bool>> matrix = {
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1}
    };
    cout << "Исследуемая матрица 6x6:" << endl;
    printMatrix(matrix);
    cout << endl;

    bool reflexive = isReflexive(matrix);
    bool antireflexive = isAntireflexive(matrix);
    bool symmetric = isSymmetric(matrix);
    bool antisymmetric = isAntisymmetric(matrix);
    bool asymmetric = isAsymmetric(matrix);
    bool transitive = isTransitive(matrix);
    bool connected = isConnected(matrix);

    cout << "Результаты анализа:" << endl;
    cout << "Рефлексивность: " << (reflexive ? "ДА" : "НЕТ") << endl;
    cout << "Антирефлексивность: " << (antireflexive ? "ДА" : "НЕТ") << endl;
    cout << "Симметричность: " << (symmetric ? "ДА" : "НЕТ") << endl;
    cout << "Антисимметричность: " << (antisymmetric ? "ДА" : "НЕТ") << endl;
    cout << "Асимметричность: " << (asymmetric ? "ДА" : "НЕТ") << endl;
    cout << "Транзитивность: " << (transitive ? "ДА" : "НЕТ") << endl;
    cout << "Связность: " << (connected ? "ДА" : "НЕТ") << endl;
    cout << endl;

    bool isEquivalence = reflexive && symmetric && transitive;
    cout << "Типы отношений:" << endl;
    cout << "Отношение эквивалентности: " << (isEquivalence ? "ДА" : "НЕТ") << endl;
    PartialOrder(antisymmetric, transitive, reflexive, antireflexive,connected);
    return 0;
}


bool isReflexive(const vector<vector<bool>>& matrix) {
    for(int i=0;i< matrix.size();i++){
        if (matrix[i][i]==0){
            return false;
        }
    }
    return true; 
}

bool isAntireflexive(const vector<vector<bool>>& matrix) {
    for(int i=0;i< matrix.size();i++){
        if (matrix[i][i]==1){
            return false;
        }
    }
    return true; 
}

bool isSymmetric(const vector<vector<bool>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isAntisymmetric(const vector<vector<bool>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (matrix[i][j] && matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isAsymmetric(const vector<vector<bool>>& matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) { 
            if (matrix[i][j] && matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool isTransitive(const vector<vector<bool>>& matrix) {
    int n = matrix.size();
    vector<vector<bool>> R2(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < n; j++) {  
            for (int k = 0; k < n; k++) {
                if (matrix[i][k] && matrix[k][j]) {
                    R2[i][j] = true;
                }
            }  
        }  
    }

    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (R2[i][j] && !matrix[i][j]) {
            return false;
        }
    }
}
    return true;

}

bool isConnected(const vector<vector<bool>>& matrix){
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) { 
            if (!matrix[i][j]&&!matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(const vector<vector<bool>>& matrix) {
    for (auto row : matrix) {
        for (bool element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

