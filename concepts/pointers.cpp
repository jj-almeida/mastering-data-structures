#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main() {
    int *p;

    // C way
    // p = (int *)malloc(5*sizeof(int));

    // C++ way
    p = new int[5];

    p[0] = 10;
    p[1] = 15;
    p[2] = 14;
    p[3] = 21;
    p[4] = 31;

    for (int i = 0; i < 5; i++)
	cout<<p[i]<<endl;

    // C way
    free(p);

    // C++ way
    delete [ ] p;

    return 0;
}
