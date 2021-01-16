#include<iostream>

using namespace std;

struct Rectangle {
    int lenght;
    int breadth;
    char x;
};

int main() {
    struct Rectangle r1 = {10, 5};

    r1.lenght = 15;
    r1.breadth = 7;

    cout<<r1.lenght<<endl;
    cout<<r1.breadth<<endl;

    return 0;

}
