#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>    
#include <functional> 
using namespace std;
class set
{
    vector <int> a;
    
public:
    void manual() {
        while (a.size()<10) {
            int f;
            cout << "Введите число которое хотите добавить в множество :";

            cin >> f;
            del(f);
        }
    };
    void random(function<bool(int)> func=nullptr){
        while (a.size()<10) {
            int f;
            
            f=-50+rand()%101;
            if(func==nullptr||(func(f))){
                del(f);
            }
            
        }
    }
    void term() {
        int k;
        cout<<"Выберите условия для заполнения множества рандомными числами,где"<<endl
        <<"1:Четные числа"<<endl<<"2:Нечетные числа"<<endl<<"3:Положительные числа(включая 0)"<<endl<<"4:Отрицательные числа"<<endl<<"5:Числа, кратные n (введите число)"<<endl;
        cin>>k;
        switch (k)
        {
        case 1:
            random([](int x){return x%2==0;});
            break;
        case 2:
            random([](int x){return x%2!=0;});
            break;
        case 3:
            random([](int x){return x>=0;});
            break;
        case 4:
            random([](int x){return x<0;});
            break;
        case 5:
            int n;
            cout<<"Чиcло n:"<<endl;
            cin>>n;
            random([n](int x){return x%n==0;});
            break;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
    };
    void del(int f) {
        bool fl=true;
        for (int i = 0; i < a.size(); i++) {
            if (f == a[i]) {
                fl = false;
            }

        }
        if (fl) {
            a.push_back(f);
        }
        cout << "  Множество: ";
        print();
    }
    void print() {
        for (int i = 0; i <a.size() ; i++) {
            cout << a[i]<<" ";
        }
        cout << endl;
    }
    friend set operator+(const set&,const set&);
    friend set operator^(const set&,const set&);
    friend set operator/(const set&,const set&);
    friend set operator%(const set&,const set&);
    set operator~(){
        set temp;
        for(int i=-50;i<51;i++){
            bool exists = false;
            for(int j:a){
                if(j==i){
                    exists=true;
                    break;
                }
            }
            if (!exists){
                temp.a.push_back(i);
            }
        }
        return temp;
    }
};
set operator+(const set& aa,const set& bb){
    set temp=aa;
    for (int item : bb.a) {
        bool exists = false;
        for (int existing_item : aa.a) {
            if (item == existing_item) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp.a.push_back(item);
        }
    }
    
    return temp;
}
set operator^(const set& aa,const set& bb){
    set temp;
    for (int item : bb.a) {
        bool exists = false;
        for (int existing_item : aa.a) {
            if (item == existing_item) {
                exists = true;
                break;
            }
        }
        if (exists) {
            temp.a.push_back(item);
        }
    }
    return temp;
}
set operator/(const set& aa,const set& bb){
    set temp;
    for (int item : aa.a) {
        bool exists = false;
        for (int existing_item : bb.a) {
            if (item == existing_item) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            temp.a.push_back(item);
        }
    }
    
    return temp;
}
set operator%(const set& aa,const set& bb){
    set temp;
    temp=(aa/bb)+(bb/aa);
    return temp;
    
}  
int main()
{
    srand(time(NULL));
    set a1;
    a1.manual();
    a1.print();

    set a2;
    a2.random();
    a2.print();

    set a3;
    a3.term();
    a3.print();

    cout<<"a2+a3:"<<endl;
    (a2+a3).print();

    cout<<"a1^a3:"<<endl;
    (a1^a3).print();

    cout<<"a3/a1:"<<endl;
    (a3/a1).print();

    cout<<"a3%a1:"<<endl;
    (a3%a1).print();

    cout<<"~a3:"<<endl;
    (~a3).print();

    cout << "((A1 + A2) / (A2 ^ A3)) % (~A3) = ";
    (((a1 + a2) / (a2 ^ a3)) % (~a3)).print();
    
}