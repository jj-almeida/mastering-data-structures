#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Rectangle {
    int lenght;
    int breadth;
};

struct Rectangle * fun() {
    struct Rectangle *p;

    //p = new Rectangle;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->lenght = 15;
    p->breadth = 7;

    return p;
}

int main() {
    struct Rectangle *ptr = fun();

    cout<<"Lenght"<<ptr->lenght<<endl<<"Breadth"<<ptr->breadth<<endl;
    return 0;
}
