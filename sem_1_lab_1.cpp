#include <iostream>
#include <vector>
using namespace std;
int Max(int a, int b){
    if (a > b) return a;
    return b;
}
void Do_undirected(int matrix[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i>j){
                if(matrix[i][j]!=0 || matrix[j][i]!=0){
                  int max = Max(matrix[i][j], matrix[j][i]);
                  matrix[i][j] = max;
                  matrix[j][i] = max;
                }
            }
        }
    }
}
void Multiplicator(int matrix[10][10]) {
    bool flag = true;
    int reachability [10][10];
    int copyMatrix [10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            copyMatrix[i][j] = matrix[i][j];
            reachability[i][j]= matrix[i][j];

        }
        reachability[i][i] = 1;
    }
    for(int m = 0; m < 9 && flag;m++){
        bool changed = false;
        int result[10][10] = {0};
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                for(int k = 0; k < 10; k++) {
                    result[i][j] += matrix[i][k] * copyMatrix[k][j];
                }
            }
        }
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                if(copyMatrix[i][j]!= result[i][j]) changed = true;
                copyMatrix[i][j] = result[i][j]; 
            }
        }
        if (changed) {
            flag = true;
            for(int i = 0; i < 10; i++) {
                for(int j = 0; j < 10; j++) {
                    reachability[i][j] = reachability[i][j]|| copyMatrix[i][j];
                }
            }   
        }
        else flag = false;
    }
    cout<<"Матрица достижимости: "<<endl;
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout<<reachability[i][j]<<" ";
        }
        cout<<endl;
    } 
}
void InDeepOrder(int matrix[10][10], int x, int arr[10]){
    arr[x]=-1;
    cout<<"Вершина номер "<<x<<" ";
    for(int i=0;i<10;i++){
        if (matrix[x][i]!=0 && arr[i] != -1) {
            InDeepOrder(matrix, i, arr);
        }
    }
}
void InDeep(int matrix[10][10], int arr[10]){
    int k = 1;
    for(int i=0;i<10;i++){
        arr[i] = 0;
    }
    for(int i=0;i<10;i++){
        
        if (arr[i]!=-1) {
            cout<<"Компонента связности номер "<<k<<":"<<endl;
            k+=1;
            InDeepOrder(matrix, i, arr);
            cout<<endl;
        } 
    }
}

void Print(int matrix[10][10]){
    cout<<"Matrix: "<< endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Reachability(int matrix[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(matrix[i][j]!=0) matrix[i][j] = 1;
        }
    }
    Multiplicator(matrix);

}
int main(){
//     int matrix[10][10] = {
//     {0,1,0,0,1,0,0,0,0,0},
//     {1,0,1,0,0,0,0,0,0,0},
//     {0,1,0,1,0,0,0,0,0,0},
//     {0,0,1,0,1,0,0,0,0,0},
//     {1,0,0,1,0,0,0,0,0,0},
//     {0,0,0,0,0,0,0,0,0,0},  // 5 изолирована
//     {0,0,0,0,0,0,0,0,0,0},
//     {0,0,0,0,0,0,0,0,0,0},
//     {0,0,0,0,0,0,0,0,0,0},
//     {0,0,0,0,0,0,0,0,0,0}
// };
//     int matrix[10][10] = {
//     {0,0,0,0,0,1,0,0,0,0},
//     {0,0,0,0,1,0,0,0,1,0},
//     {0,0,0,0,0,0,1,1,0,0},
//     {0,0,0,0,0,0,0,1,0,1},
//     {0,1,0,0,0,0,0,0,0,0},
//     {1,0,0,0,0,0,1,0,0,0},
//     {0,0,1,0,0,1,0,0,1,1},
//     {0,0,1,1,0,0,0,0,0,0},
//     {0,1,0,0,0,0,1,0,0,0},
//     {0,0,0,1,0,0,1,0,0,0}
// };
// int matrix[10][10] = {
//     {0,0,0,0,0,0,1,1,1,0},
//     {0,0,0,0,0,1,0,0,0,1},
//     {0,0,0,1,0,0,0,0,0,1},
//     {0,0,1,0,1,0,0,0,0,0},
//     {0,0,0,1,0,1,0,0,0,0},
//     {0,1,0,0,1,0,0,0,0,0},
//     {1,0,0,0,0,0,0,1,1,0},
//     {1,0,0,0,0,0,1,0,1,0},
//     {1,0,0,0,0,0,1,1,0,0},
//     {0,1,1,0,0,0,0,0,0,0}
// };
// int matrix[10][10] = {
//     {0,0,0,0,0,0,0,0,1,0},
//     {0,0,1,0,0,1,0,0,0,0},
//     {0,1,0,0,0,1,0,0,0,0},
//     {0,0,0,0,1,0,0,0,0,0},
//     {0,0,0,1,0,0,0,1,0,0},
//     {0,1,1,0,0,0,0,0,1,0},
//     {0,0,0,0,0,0,0,0,0,0},
//     {0,0,0,0,1,0,0,0,0,0},
//     {1,0,0,0,0,1,0,0,0,1},
//     {0,0,0,0,0,0,0,0,1,0}
// };
int matrix[10][10] = {
    {0,0,0,1,0,0,0,0,1,0},
    {0,0,0,0,0,1,0,0,0,1},
    {0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0},
    {0,0,1,0,0,0,0,1,0,0},
    {0,1,0,0,0,0,0,0,0,1},
    {0,0,0,1,0,0,0,0,1,0},
    {0,0,0,0,1,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0},
    {0,1,0,0,0,1,0,0,0,0}
};

    Do_undirected(matrix);
    Print(matrix);
    int arr[10];
    InDeep(matrix, arr);
    Reachability(matrix);
    return 0;
}