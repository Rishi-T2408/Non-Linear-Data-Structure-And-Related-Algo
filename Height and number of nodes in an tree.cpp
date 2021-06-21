/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Finding number of nodes and height stating from one
#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
struct Node{
    Node *lchild;
    int data;
    Node *rchild;
};
class Queue{
private:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};
 
Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}
 
Queue::~Queue() {
    delete [] Q;
}
 
bool Queue::isEmpty() {
    if (front == rear){
        return true;
    }
    return false;
}
 
bool Queue::isFull() {
    if (rear == size-1){
        return true;
    }
    return false;
}
 
void Queue::enqueue(Node* x) {
    if (isFull()){
        cout << "Queue Overflow" << endl;
    } else {
        rear++;
        Q[rear] = x;
    }
}
 
Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()){
        cout << "Queue Underflow" << endl;
    } else {
        front++;
        x = Q[front];
    }
    return x;
}
 
Node* root = new Node;
 
void Create()
{
    Node *p,*t;
    int x;
    Queue q(100);
    cout<<"Enter root node value: "<<endl;
    cin>>x;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);
    while(!(q.isEmpty()))
    {
        p=q.dequeue();
        cout<<"Enter the value of left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter the value of right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
    
}

int count(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int Height(Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=Height(p->lchild);
        y=Height(p->rchild);
        if(x>y)
        return (x+1);
        else
        return (y+1);
    }
    return 0;
}

int main()
{
    cout<<"Creating Binary tree"<<endl;
    Create();
    cout<<"Number of Nodes in an tree are "<<count(root)<<endl;
    cout<<"Height of tree are "<<Height(root)<<' ';
    return 0;
}