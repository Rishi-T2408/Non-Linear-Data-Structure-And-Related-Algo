#include <iostream>
using namespace std;
void Insert(int A[],int n)
{
    int temp,i=n;
    temp=A[n];
    while(i>1 && temp>A[i/2]) 
    {
        A[i]=A[i/2];
        i=i/2;
    }
    A[i]=temp;
}


int* CreateHeap(int A[],int l)
{
  
    for(int i=2;i<l;i++)
    {
        Insert(A,i);  
    }
    
    return A;
}

void Delete(int A[],int n)
{
    int i=1,j,x,temp;
    x=A[i];
    j=2*i;
    A[i]=A[n];
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
    A[n]=x; 
}
void HeapSort(int H[],int l)
{
    
    H=CreateHeap(H,l);
    int n=(l-1);
    while(n>0)
    {
        Delete(H,n);
        n--;
    }
    
}


int main()
{
    int *A;
    int length;
    cout<<"Enter the length of the array "<<endl;    
    cin>>length;
    A=new int[length+1];
    cout<<"Enter all the elements of the array "<<endl;
    A[0]=0;  
    for(int i=1;i<(length+1);i++)
    {
        cin>>A[i];   
    }
    cout<<"After sorting the array in heap sort "<<endl;
    HeapSort(A,length);  
    for(int i=1;i<(length+1);i++)
    {
        cout<<A[i]<<" "; 
    }
    return 0;
}
