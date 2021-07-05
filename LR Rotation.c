#include <iostream>
using namespace std;


struct Node{
    Node *lchild;
    int data;
    int height;  //Which will help to find balancing factor easily
    Node *rchild;
};
Node *root=NULL;

int NodeHeight(Node *p)
{
    int hl= p && p->lchild ?(p->lchild)->height:0;
    int hr=p && p->rchild ?(p->rchild)->height:0;    //hr is height of right subtree so we need to focus on right child 
    
    return hl>hr?(hl+1):(hr+1);  //That will be the height of node
}


int Balancefactor(Node *p)
{
    int hl= p && p->lchild ?(p->lchild)->height:0;
    int hr=p && p->rchild ?(p->rchild)->height:0;   
    return (hl-hr);  //That will be the height of node
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
Node *LRRotate(Node *p)
    {
        Node *q=p->lchild;
        Node *r=q->rchild;
        
        q->right=r->lchild;
        p->left=r->rchild;
        r->lchild=q;
        r->rchild=p;
        
        
        p->height=NodeHeight(p);
        q->height=NodeHeight(q);
        r->height=NodeHeight(r);
        
        if(p==root)
        root=r;
        
        return r;
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

Node *LLRotate(Node *p)
{
    Node *q=p->lchild;
    Node *r=q->rchild;
    q->rchild=p;
    p->lchild=r;
    p->height=NodeHeight(p);
    q->height=NodeHeight(q);
    if(r!=NULL)
    r->height=NodeHeight(r);
    
    if(root==p)
    root=q;
    return q;
    
    //This is an observed formulas you just can recreate it 
}
Node * Rinsert(Node *p,int key)  //Inserting in an AVL is similar to the inserting in BST only diffrence is we have to balance the imbalanced node if found
{
    Node *t;
    if(p==NULL)
    {
        t=new Node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;  //Height is starting from 1
        return t;
    }
    if(p->data<key)
    {
        p->rchild=Rinsert(p->rchild,key);
    }
    else if(p->data>key)
    {
        p->lchild=Rinsert(p->lchild,key);
    }
    
    p->height=NodeHeight(p);
    
    
   
    if(Balancefactor(p)==2 && Balancefactor(p->lchild)==1)
    {
        return LLRotate(p);  //Giving the imbalanced node for balancing it by rotaTION
    }
    
    
    
    return p;
}


int main()
{
    root=Rinsert(root,8);
    Rinsert(root,5);
    
    Rinsert(root,3);   //So when we insert like this it will became LL imbalanced so LL Rotation
    cout<<endl;

    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
}