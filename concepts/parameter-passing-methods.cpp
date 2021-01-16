#include<iostream>

using namespace std;

void swap(int *x, int *y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int num1 = 10;
    int num2 = 15;

    swap(&num1, &num2);

    cout<<"First number "<<num1<<endl;
    cout<<"Second number "<<num2<<endl;

    return 0;
}
