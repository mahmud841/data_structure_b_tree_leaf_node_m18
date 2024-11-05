#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *inputTree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1.ber kore ana
        Node *parent = q.front();
        q.pop();

        // 2.sob kaj korte hobe
        int l, r;
        cin >> l >> r;
        Node *newLeft;
        Node *newRight;
        if (l == -1)
            newLeft = NULL;
        else
            newLeft = new Node(l);
        if (r == -1)
            newRight = NULL;
        else
            newRight = new Node(r);

        parent->left = newLeft;
        parent->right = newRight;
        // 3. children input push kore ante hobe
        if (parent->left)
            q.push(parent->left);
        if (parent->right)
            q.push(parent->right);
    }
    return root;
}

int count_leaf(Node *root)
{
    if (root == NULL)
        return 0;
   if(root->left==NULL && root->right==NULL)
   {
    return 1;
   }
   else{
    int l= count_leaf(root->left);
    int r= count_leaf(root->right);
    return l+r;
   }
}

int main()
{
    Node *root = inputTree();
    cout << count_leaf(root) << endl;
    return 0;
}