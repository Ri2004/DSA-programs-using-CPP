#include<iostream>
using namespace std;
#define EMPTY_BST -1
#define INSERTION_NOT_POSSIBLE 1

class Node
{
    public:
        int data;
        Node *left, *right;
};

class BST
{
    Node *root;

    protected:
        void preorderrec(Node *);
        void inorderrec(Node *);
        void postorderrec(Node *);

    public:
        BST();
        bool isEmpty();
        void insertElementInBST(int);
        void preorder();
        void inorder();
        void postorder();
        Node* searchElement(int);
};

BST::BST()
{
    root = nullptr;
}

bool BST::isEmpty()
{
    return root == nullptr;
}

void BST::insertElementInBST(int item)
{
    Node *n = new Node, *ptr;
    n->data = item;
    n->left = n->right = nullptr;
    ptr = root;

    if(isEmpty())
        root = n;
    else
    {
        while(ptr->data != n->data)
        {
            if(n->data < ptr->data)
            {
                if(ptr->left == nullptr)
                    ptr->left = n;
                else
                    ptr = ptr->left;
            }
            else 
            {
                if(n->data > ptr->data)
                {
                    if(ptr->right == nullptr)
                        ptr->right = n;
                    else
                        ptr = ptr->right;
                }
            }
        }
        if(ptr->data == n->data)
            delete n;
    }
}

void BST::preorder()
{
    preorderrec(root);
}

void BST::preorderrec(Node* root)
{
    if(root)
    {
        cout << root->data << " ";
        preorderrec(root->left);
        preorderrec(root->right);
    }
}

void BST::postorder()
{
    postorderrec(root);
}

void BST::postorderrec(Node* root)
{
    if(root)
    {
        postorderrec(root->left);
        postorderrec(root->right);
        cout << root->data << " ";
    }
}

void BST::inorder()
{
    inorderrec(root);
}

void BST::inorderrec(Node* root)
{
    if(root)
    {
        inorderrec(root->left);
        cout << root->data << " ";
        inorderrec(root->right);
    }
}

Node* BST::searchElement(int item)
{
    Node *ptr;

    if(isEmpty())
        return nullptr;
    else
    {
        ptr = root;

        while(ptr->data != item)
        {
            if(item < ptr->data)
            {
                if(ptr->left != nullptr)
                {
                    ptr = ptr->left;

                    if(ptr->data == item)
                        return ptr;
                }
                else
                    return nullptr;
            }

            else if(item > ptr->data)
            {
                if(ptr->right != nullptr)
                {
                    ptr = ptr->right;

                    if(ptr->data == item)
                        return ptr;
                }
                else
                    return nullptr;
            }
        }
        if(ptr->data == item)
            return ptr;
    }
    return nullptr;
}

int main()
{
    BST t1;
    Node *f;

    t1.insertElementInBST(20);
    t1.insertElementInBST(10);
    t1.insertElementInBST(30);
    t1.insertElementInBST(5);
    t1.insertElementInBST(25);
    t1.insertElementInBST(22);
    t1.insertElementInBST(42);

    f = t1.searchElement(80);

    if(f)
        cout << f->data << " found" << endl;
    else
        cout << "Item Not Found" << endl;

    cout << "Inorder Traversal Of Binary Search Tree is:" << endl;
    t1.inorder();

    cout << endl
         << "Preorder Traversal Of Binary Search Tree is:" << endl;
    t1.preorder();

    cout << endl
         << "Postorder Traversal Of Binary Search Tree is:" << endl;
    t1.postorder();

    return 0;
}