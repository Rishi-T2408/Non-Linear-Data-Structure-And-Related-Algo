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

void Preorder(Node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(Node *p)
{
    if(p!=NULL)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Postorder(Node *p)
{
    if(p!=NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}


Node * RSearch(Node *t,int key)  //Recursive searching in Binary search tree
{
    if(t==NULL)  //Unsuccesful search
    return NULL;
    
    if(t->data==key)
    return t;
    
    else if(t->data>key)
    {
        return RSearch(t->lchild,key);
    }
    else
    {
        return RSearch(t->rchild,key);
    }
}

Node *Search(Node *t,int key)
{
    while(t!=NULL)
    {
        if(t->data==key)
        {
            return t;
        }
        else if(t->data<key)
        {
            t=t->rchild;
        }
        else{
            t=t->lchild;
        }
    }
    
    return NULL; //Unsuccesful search
}
int main()
{
    cout<<"Creating Binary tree"<<endl;
    Create();
    char ch;
    int x;
    do{
    cout<<"Enter the value you want to search"<<endl;
    cin>>x;
    Node *c=Search(root,x);
    
    if(c==NULL)
    cout<<"Unsuccesful search"<<endl;
    else{
        cout<<"Succesful search"<<endl;
    }
    cout<<"Enter Y/N"<<endl;
    cin>>ch;
    
    }while(ch=='Y'|| ch=='y');
    return 0;
}