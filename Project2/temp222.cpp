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
vector<string> final;

void Treecreate()  
{
    queue <Node *> q;
    struct Node *tmp, *newnode;

    vector<string> arr;
    int nc = 0, c = 0, n;
    string x;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the values of the array: \n";
    for(int i = 0; i < n; i++)
    {
        cin >> x;

        if(x == "null")
        {
            arr.push_back("-1");
            nc++;
        }

        else
        {
            arr.push_back(x);
            c++;
        }
    }

    while(nc != c + 1)
    {
        arr.push_back("null");
        nc++;
    }

    root = new Node;
    root -> data = stoi(arr[0]);
    root->left = root->right = NULL;
    q.push(root);
    int i = 1;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(arr[i]!="null"){
            newnode = new Node;
            newnode -> data = stoi(arr[i++]);
            newnode->left = newnode->right = NULL;
            tmp->left = newnode;
            q.push(newnode);
        }

        if(arr[i]!="null"){
            newnode = new Node;
            newnode -> data = stoi(arr[i++]);
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
        if(root->data == -1)
        {
            cout << "null ";
            final.push_back("null");
        }
        else
        {
            cout << root->data << " ";
            string t = to_string(root->data);
            final.push_back(t);
        }
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

void checkMirrorImage()
{
    int n;
    cout << "Enter the size of the second array: ";
    cin >> n;
    vector<string> second;

    cout << "Enter the values of the array: \n";

    for(int i = 0; i < n; i++)
    {
        string x;
        cin >> x;
        second.push_back(x);
    }

    for(int i = 0, j = final.size() / 2; j < final.size(); i++, j++)
    {
        if(second[i] != final[j])
        {
            cout << "Not mirror image";
            return;
        }
    }

    cout << "Mirror image\n";
	
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

    // **** Uncomment the next statement for 2B solution please **** //

    //checkMirrorImage();

    
    return 0;
}