#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int Max(int a, int b){
    if (a > b) return a;
    return b;
}
int Min(int a, int b){
    if (a < b) return a;
    return b;
}
struct vec{
    int i;
    int j;
    int weight;
    vec(int I,int J,int Weight): i(I), j(J), weight(Weight){}
};
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
void Print(int matrix[10][10]){
    cout<<"Matrix: "<< endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<< matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Prim(int matrix[10][10], bool arr[10]){
    for(int i=0;i<10;i++) arr[i] = false;
    arr[0] = true;
    int weight = 0;
    int ii;
    int jj;
    for(int g=0;g<9;g++){
        int mini = INT_MAX;
        for(int i = 0; i<10;i++){
            if(arr[i]){
                for(int j=0;j<10;j++){
                    if(matrix[i][j]<mini &&  matrix[i][j] > 0 && !arr[j]) {
                        mini = matrix[i][j];
                        ii = i;
                        jj = j;
                    }  
                }
            }
        }
        arr[jj] = true;
        cout<<"Ребро: "<<ii<<" "<<jj<<" его вес = "<<mini<<endl;
        weight+=mini;
    }
    cout<<"общий вес "<<weight<<endl;
}
void Kraskal(int matrix[10][10], int arr[10], vector<vec> edge){
    for(int i=0;i<10;i++) arr[i] = 0;
    int weight = 0;
    int ii;
    int jj;
    int k = 0;
    int steepWeight = 0;
    for(int g=0;g<9;g++){
        int index_to_remove;
        for(int i=0;i<edge.size();i++){
            if(arr[edge[i].i]==0 || arr[edge[i].j]==0 || arr[edge[i].i] != arr[edge[i].j]){
                steepWeight = edge[i].weight;
                ii =edge[i].i;
                jj = edge[i].j;
                index_to_remove = i;
                break;
            }
        }
        edge.erase(edge.begin() + index_to_remove);
        cout<<"Ребро: "<<ii<<" "<<jj<<" его вес = "<<steepWeight<<endl;
        if(arr[ii]==0 && arr[jj] ==0){
            k+=1;
            arr[ii] = k;
            arr[jj] = k;
        }
        else if(arr[ii] == 0) {
            arr[ii] = arr[jj];
        }
        else if(arr[jj] == 0) {
            arr[jj] = arr[ii];
        }
        else if(arr[ii] != arr[jj]) {
            int oldComp = arr[jj];
            int newComp = arr[ii];
            for(int i = 0; i < 10; i++) {
                if(arr[i] == oldComp) {
                    arr[i] = newComp;
                }
            }
        }
        weight+=steepWeight;
    }
    cout<<"общий вес "<<weight<<endl;
}
void createSortedVector(int matrix[10][10], vector<vec>& a){
    for(int i=0;i<10;i++){
        for(int j=0;j<i;j++){
            if(matrix[i][j]!=0){
                vec v(i,j,matrix[i][j]);
                a.push_back(v);
            }
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=i;j<a.size();j++){
            if(a[j].weight<a[i].weight){
                vec v = a[j];
                a[j] =a[i];
                a[i] = v;
            }
        }
    }
}
int main() {
    // int matrix[10][10] = {
    //     {0, 2, 0, 0, 3, 0, 0, 0, 0, 4},
    //     {2, 0, 5, 0, 0, 0, 0, 0, 0, 0},
    //     {0, 5, 0, 1, 0, 6, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 0, 0, 7, 0, 0, 0},
    //     {3, 0, 0, 0, 0, 8, 0, 9, 0, 0},
    //     {0, 0, 6, 0, 8, 0, 0, 0, 10, 0},
    //     {0, 0, 0, 7, 0, 0, 0, 11, 0, 12},
    //     {0, 0, 0, 0, 9, 0, 11, 0, 13, 0},
    //     {0, 0, 0, 0, 0, 10, 0, 13, 0, 14},
    //     {4, 0, 0, 0, 0, 0, 12, 0, 14, 0}
    // };
    // int matrix[10][10] = {
    //     {0, 0, 0, 7, 8, 6, 3, 0, 0, 0},
    //     {0, 0, 0, 4, 2, 1, 0, 3, 9, 1},
    //     {0, 0, 0, 5, 9, 0, 6, 8, 5, 0},
    //     {7, 4, 5, 0, 0, 0, 6, 0, 0, 9},
    //     {8, 2, 9, 0, 0, 0, 0, 4, 5, 0},
    //     {6, 1, 0, 0, 0, 0, 3, 0, 7, 0},
    //     {3, 0, 6, 6, 0, 3, 0, 0, 3, 0},
    //     {0, 3, 8, 0, 4, 0, 0, 0, 4, 5},
    //     {0, 9, 5, 0, 5, 7, 3, 4, 0, 8},
    //     {0, 1, 0, 9, 0, 0, 0, 5, 8, 0}
    // };
    // int matrix[10][10] = {
    //     {0, 1, 0, 3, 0, 0, 0, 0, 0, 0},
    //     {1, 0, 5, 0, 2, 0, 0, 4, 0, 2},
    //     {0, 5, 0, 0, 0, 1, 0, 0, 0, 3},
    //     {3, 0, 0, 0, 0, 0, 0, 5, 3, 0},
    //     {0, 2, 0, 0, 0, 4, 0, 0, 0, 0},
    //     {0, 0, 1, 0, 4, 0, 4, 0, 0, 5},
    //     {0, 0, 0, 0, 0, 4, 0, 2, 0, 0},
    //     {0, 4, 0, 5, 0, 0, 2, 0, 1, 0},
    //     {0, 0, 0, 3, 0, 0, 0, 1, 0, 0},
    //     {0, 2, 3, 0, 0, 5, 0, 0, 0, 0}
    // };
    // int matrix[10][10] = {
    //     {0, 3, 4, 2, 0, 0, 0, 0, 0, 0},
    //     {3, 0, 0, 0, 3, 0, 0, 0, 0, 0},
    //     {4, 0, 0, 0, 6, 0, 0, 0, 0, 0},
    //     {2, 0, 0, 0, 3, 10, 0, 0, 0, 0},
    //     {0, 3, 6, 3, 0, 10, 8, 7, 0, 0},
    //     {0, 0, 0, 10, 10, 0, 6, 0, 2, 0},
    //     {0, 0, 0, 0, 8, 6, 0, 0, 0, 4},
    //     {0, 0, 0, 0, 7, 0, 0, 0, 6, 3},
    //     {0, 0, 0, 0, 0, 2, 0, 6, 0, 5},
    //     {0, 0, 0, 0, 0, 0, 4, 3, 5, 0}
    // };
    int matrix[10][10] = {
        {0, 2, 3, 4, 0, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 2, 5, 0, 0, 0, 0},
        {3, 0, 0, 0, 3, 0, 0, 0, 0, 0},
        {4, 0, 0, 0, 6, 0, 0, 0, 0, 0},
        {0, 2, 3, 6, 0, 1, 8, 7, 0, 0},
        {0, 5, 0, 0, 1, 0, 6, 0, 12, 0},
        {0, 0, 0, 0, 8, 6, 0, 0, 0, 4},
        {0, 0, 0, 0, 7, 0, 0, 0, 6, 3},
        {0, 0, 0, 0, 0, 12, 0, 6, 0, 11},
        {0, 0, 0, 0, 0, 0, 4, 3, 11, 0}
    };
    Do_undirected(matrix);
    Print(matrix);
    cout<<endl;
    bool arr[10];
    cout<<" Прим:"<<endl;
    Prim(matrix,arr);

    vector<vec> edge;
    createSortedVector(matrix,edge);
    int arr1[10];
    cout<<" Краскал:"<<endl;
    Kraskal(matrix,arr1, edge);
    return 0;
}