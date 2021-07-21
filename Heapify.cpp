#include <iostream>
using namespace std;
void Heapify(int A[],int n)
{
    int i=(n-1),j,temp;
    
    
    for(i=(n-1);i>0;i--)
    {
        j=2*i;
        while(j<=(n-1))
        {
            if((j+1)<n)
            {
                if(A[j]<A[j+1])
                j=j+1;
            }
            
            if(A[i]<A[j])
            {
                temp=A[j];
                A[j]=A[i];
                A[i]=temp;
                i=j;
                j=2*i;
            }
            else{
                break;
            }
        }
    }
}

int main()
{
    int A[]={0,2,4,6,1,9,7,12,10,3};
    int l=sizeof(A)/sizeof(int);
    Heapify(A,l);
    for(int i=1;i<l;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}