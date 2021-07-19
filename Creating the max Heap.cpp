/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
void Insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];
    while(i>1 && temp>A[i/2])  //We are creating max heap here
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}
int * CreateHeap()
{
    int A[]={0,1,3,2,5,10,4,6,8,12};   //I will insert all the elements present in the array to the heap
    //The 0th ndex is 0 so that we can ignore it and count it from 1st index only
    int lenght=sizeof(A)/sizeof(int);
    for(int i=2;i<lenght;i++)
    {
        Insert(A,i);   //We assume 1 element is already present in the heap and we will insert from 3
    }
    
    cout<<"After creating the heap the heap array storage will be "<<endl;
    for(int i=1;i<lenght;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int *H;
    cout<<"We will now create an heap"<<endl;
    CreateHeap();
    

    return 0;
}
