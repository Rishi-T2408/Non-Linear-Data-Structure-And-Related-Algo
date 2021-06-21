/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};
struct Nodes {
    Node* data;
    Nodes* next;
};

class Stack {
private:
    Nodes* head = NULL;
    Nodes* last = NULL;
public:
    void push(Node* p)
    {
        if (head == NULL)
        {
            Nodes* t = new Nodes;
            t->data = p;
            head = t;
            last = t;
        }
        else {
            Nodes* t = new Nodes;
            t->data = p;
            last->next = t;
            last = t;
        }
    }

    Node* pop()
    {

        Nodes* p = head;
        Nodes* r = NULL;
        Node* x;

        while (p != last)
        {
            r = p;
            p = p->next;
            

        }
        
        last = r;
        if (p == head)
        {
            head = NULL;
        }
        x = p->data;
        delete p;
        return x;
    }
    int isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else {
            return 0;
        }
    }
};
class Queue {
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
    Q = new Node * [size];
}

Queue::~Queue() {
    delete[] Q;
}

bool Queue::isEmpty() {
    if (front == rear) {
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if (rear == size - 1) {
        return true;
    }
    return false;
}

void Queue::enqueue(Node* x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    }
    else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    }
    else {
        front++;
        x = Q[front];
    }
    return x;
}

Node* root = new Node;

void Create()
{
    Node* p, * t;
    int x;
    Queue q(100);
    cout << "Enter root node value: " << endl;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!(q.isEmpty()))
    {
        p = q.dequeue();
        cout << "Enter the value of left child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter the value of right child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }

}

void Postorder(Node* t)   //This one is important as well as difficult lit bit
{
    Stack st;
    long int temp;
    while (t != NULL || !(st.isEmpty()))
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->lchild;
        }
        else {

            temp = int(st.pop());
            if (temp > 0)
            {
                st.push((Node *)-temp);  //We are pushing this to have to print it after going to right child
                t = ((Node*)temp)->rchild;
            }
            else {
                temp = -temp;
                cout<<((Node*)temp)->data<<" ";
                t = NULL;
            }
        }
    }
}

int main()
{
    cout << "Creating Binary tree" << endl;
    Create();
    cout << endl;
    cout << "Displaying in Postorder" << endl;
    Postorder(root);
    return 0;
}
