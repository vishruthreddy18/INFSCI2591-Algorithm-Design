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
void inorder(struct Node *p);
void convertToMirror(Node* root);

struct Node *root = NULL;

void Treecreate()  
{
    queue <Node *> q;
    struct Node *tmp, *newnode;
    cout << "Enter the size of the array: ";
    int n;
    cin >> n;
    int l = n;
    vector<string> arr;
    cout << "Enter the nodes of the tree: ";
    string x;

    while(n >= 0)
    {
        cin >> x;
        if(x == "null")
            x = "-1";
        arr.push_back(x);
        n--;
    }
    cout << "Input array: \n";
    for(int i = 0; i < l; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // cout << "Enter root value: ";
    // cin>>x;
    root = new Node;
    root -> data = stoi(arr[0]);
    root->left = root->right = NULL;
    q.push(root);
    int j = 0;
    while(!q.empty() || j < l){
        tmp = q.front();
        q.pop();
        // cout<<"Enter left child of "<<tmp->data<<": ";
        // cin>>x;
        if(arr[++j]!="null"){
            newnode = new Node;
            newnode -> data = stoi(arr[j]);
            newnode->left = newnode->right = NULL;
            tmp->left = newnode;
            q.push(newnode);
        }
        // cout<<"Enter right child of "<<tmp->data<<": ";
        // cin>>x;
        if(arr[++j]!="null"){
            newnode = new Node;
            newnode -> data = stoi(arr[j]);
            newnode->left = newnode->right = NULL;
            tmp->right = newnode;
            q.push(newnode);
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
 
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void convertToMirror(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    convertToMirror(root->left);
 
    convertToMirror(root->right);
 
    swap(root->left, root->right);
}

int main()
{
    Treecreate();
    cout << "\nInput: ";
    printLevelOrder(root);
    cout << "\nOutput: ";

    convertToMirror(root);
    printLevelOrder(root);
    cout << "\n";
	
    return 0;
}