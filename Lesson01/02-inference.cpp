//
// Created by Ignorant on 2024/3/7.
//
#include <iostream>
using namespace std;

// 10.struct
struct Data {
    int a;
    double b;
    char c;
};

void print(const Data &data) {
    cout << "Data:{a: " << data.a << ", b: " << data.b << ", c: " << data.c << "}" << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

Data func1(Data data[], int length) {
    int max = data[0].a;
    int maxIndex = 0;
    for (int i = 0; i < length; i++) {
        if (max < data[i].a) {
            max = data[i].a;
            maxIndex = i;
        }
    }
    return data[maxIndex];
}

Data &func2(Data data[], int length) {
    int max = data[0].a;
    int maxIndex = 0;
    for (int i = 0; i < length; i++) {
        if (max < data[i].a) {
            max = data[i].a;
            maxIndex = i;
        }
    }
    return data[maxIndex];
}

int main() {
    int x;
    int &y = x;
    y = 10;
    cout << x << endl;
    
    Data data = {1, 2.2, '3'};
    print(data);
    
    int a = 0;
    int b = 1;
    cout << a << ", " << b << endl;
    swap(a, b);
    cout << a << ", " << b << endl;
    
    Data data1[4] = {
            {1, 0},
            {2, 0},
            {3, 0},
            {4, 0},
    };
    Data temp = func1(data1, 4);
    temp.a++;
    cout << data1[3].a << endl;
    func2(data1, 4).a++;
    cout << data1[3].a << endl;
    return 0;
}
