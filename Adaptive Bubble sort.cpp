class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int A[], int n)
    {
        // Your code here  
        int flag=0;  //Making it adaptive 
        int temp;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<(n-i-1);j++)
            {
                if(A[j]>A[j+1])
                {
                    temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;   //If there is no swaps in any of the passes then array is already sorted we need to sort 
                    flag=1;
                }
                
            }
            if(flag==0)
                break;
            
        }
    }
};
