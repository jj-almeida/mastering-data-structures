#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Rectangle {
    int lenght;
    int breadth;
};

int main() {

    struct Rectangle *p;
    // p = new Rectangle;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->lenght = 15;
    p->breadth=7;

    cout<<p->lenght<<endl;
    cout<<p->breadth<<endl;

    return 0;
}
