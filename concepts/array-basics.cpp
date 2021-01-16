#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int n;

    cout<<"Enter size"<<endl;
    cin>>n;
    
    int A[n];

    A[1] = 2;

    for (int x: A) {
	cout<<x<<endl;
    }

    return 0;
}
