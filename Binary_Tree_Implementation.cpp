// Almost Complete Binary Tree Implementation

#include<iostream>
using namespace std;

class Node
{
    public:
        int data, lcount, rcount;
        Node *left, *right;
};

class ACBT          // ACBT stands for Almost Complete Binary Tree
{
    Node *root;
    public:
        ACBT();
        Node *insertElementInBinaryTree(Node *, int);
        Node *createNode(Node *, int);
        void preorder();
        void preorderrec(Node *);
        void inorder();
        void inorderrec(Node *);
        void postorder();
        void postorderrec(Node *);
        void createTree();
        int check(int);
        bool isEmpty();
        
};

ACBT::ACBT()
{
    root = nullptr;
}

bool ACBT::isEmpty()
{
    return root == nullptr;
}

Node* ACBT::createNode(Node* n, int item)
{
    n = new Node;
    n->data = item;
    n->left = n->right = nullptr;
    n->lcount = n->rcount = 0;

    return n;
}

Node* ACBT::insertElementInBinaryTree(Node* n, int item)
{
    if(isEmpty())
        root = createNode(root, item);
    
    else if(root->lcount == root->rcount)
    {
        root->left = insertElementInBinaryTree(root->left, item);
        root->lcount += 1;
    }

    else if(root->rcount < root->lcount)
    {
        if(check(root->lcount))
        {
            root->right = insertElementInBinaryTree(root->right, item);
            root->rcount += 1;
        }
        else
        {
            root->left = insertElementInBinaryTree(root->left, item);
            root->lcount += 1;
        }
    }
}

int ACBT::check(int count)
{
    count += 1;

    while(count%2 == 0)
        count /= 2;
    
    if(count == 1)
        return 1;
    else
        return 0;
}

void ACBT::preorder()
{
    preorderrec(root);
}

void ACBT::preorderrec(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        preorderrec(root->left);
        preorderrec(root->right);
    }
}

void ACBT::inorder()
{
    inorderrec(root);
}

void ACBT::inorderrec(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        inorderrec(root->left);
        inorderrec(root->right);
    }
}

void ACBT::postorder()
{
    postorderrec(root);
}

void ACBT::postorderrec(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        postorderrec(root->left);
        postorderrec(root->right);
    }
}

void ACBT::createTree()
{
    insertElementInBinaryTree(root, 20);
}

int main()
{
    ACBT bt1;

    bt1.createTree();
    cout << "Preorder Traversal Of Tree is: " << endl;
    bt1.preorder();
    return 0;
}