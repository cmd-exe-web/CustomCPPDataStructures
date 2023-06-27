#include <iostream>
#include <cstring>
#include "Vector.h"
#include "Array.h"

using namespace std;

template<typename T>
void Print(const Vector<T>& vec){
    for(int i = 0; i < vec.Size(); i++){
        cout << vec[i] << " ";
    }
    
    cout << "\n----------------------------\n";
}

int main()
{
    Vector<int> vec;
    
    vec.Push_Back(2);
    vec.Push_Back(2);
    vec.Push_Back(2);
    vec.Push_Back(2);
    vec.Push_Back(2);

    cout << vec.Size() << endl;
    Print(vec);

    vec.Clear();
    cout << vec.Size() << endl;
    Print(vec);

    
    vec.Emplace_Back(3);
    vec.Emplace_Back(2);
    vec.Emplace_Back(1);
    vec.Emplace_Back(5);
    vec.Emplace_Back(7);
    vec.Emplace_Back(4);
    vec.Emplace_Back(8);
    cout << vec.Size() << endl;
    Print(vec);

    cout << "element at index 3 is: " << vec[3] << endl;

    vec[3] = 100;

    cout << "after changing\n";
    cout << "element at index 3 is: " << vec[3] << endl;

}