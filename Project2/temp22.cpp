#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

void printLevelOrder(Node* root);
void printCurrentLevel(Node* root, int level);
int height(Node* node);
void Treecreate();
void convertToMirror(Node* root);

struct Node *root = NULL;

void Treecreate()  
{
    queue <Node *> q;
    struct Node *tmp, *newnode;

    vector<string> arr;

    string x;
    cout << "Enter root value: ";
    cin>>x;
    root = new Node;
    root -> data = stoi(x);
    root->left = root->right = NULL;
    q.push(root);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        cout<<"Enter left child of "<<tmp->data<<": ";
        cin>>x;
        if(x!="null"){
            newnode = new Node;
            newnode -> data = stoi(x);
            newnode->left = newnode->right = NULL;
            tmp->left = newnode;
            q.push(newnode);
        }

        else
        {
            newnode = new Node;
            newnode -> data = -1;
            newnode->left = newnode->right = NULL;
            tmp->left = newnode;
            //q.push(newnode);
        }
        cout<<"Enter right child of "<<tmp->data<<": ";
        cin>>x;
        if(x!="null"){
            newnode = new Node;
            newnode -> data = stoi(x);
            newnode->left = newnode->right = NULL;
            tmp->right = newnode;
            q.push(newnode);
        }

        else
        {
            newnode = new Node;
            newnode -> data = -1;
            newnode->left = newnode->right = NULL;
            tmp->left = newnode;
            //q.push(newnode);
        }
    }
}

void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
    {
        if(root->data == -1)
            cout << "null ";
        else
            cout << root->data << " ";
    }
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
            return (lheight + 1);

        else
            return (rheight + 1);

    }
}

void convertToMirror(Node* root)
{
    if (root == nullptr)
        return;
 
    convertToMirror(root->left);
    convertToMirror(root->right);
    swap(root->left, root->right);
}

int main()
{
    Treecreate();
    cout << "\nInput: ";
    //printLevelOrder(root);
    cout << "\n";

    convertToMirror(root);
    cout << "Output: ";
    printLevelOrder(root);
    cout << " 10\n";
	
    return 0;
}