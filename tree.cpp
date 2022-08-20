#include <bits/stdc++.h>
using namespace std;
// implementation
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = nullptr;
    }
};

// traversal

// inorder

void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

// height of a binary tree;

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// print at distance k from the root

void printKDist(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->key << " ";
    }
    printKDist(root->left, k - 1);
    printKDist(root->right, k - 1);
}

// level order traversal

void printLevel(Node *root)
{
    queue<Node *> q{};
    q.push(root);

    while (!q.empty())
    {
        int temp = q.size();
        for (int i{}; i < temp; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        cout << endl;
    }
}

// sizeof binary tree
int getSize(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + getSize(root->left) + getSize(root->right);
}

// maximum in binary tree
int getMax(Node *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    return max({root->key, getMax(root->left), getMax(root->right)});
}

// left view of binary tree

int maxLevel = 0;
void printLeft(Node *root, int level)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level + 1);
    printLeft(root->right, level + 1);
}
void printLeftView(Node *root)
{
    printLeft(root, 1);
}

// children sum property
bool isCSum(Node *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool flag = (root->key == (root->left == NULL) ? 0 : root->left->key + (root->right == NULL) ? 0
                                                                                                 : root->right->key);

    return (flag && isCSum(root->left) && isCSum(root->right));
}

// check for balanced sub tree
int isBalanced(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int a = isBalanced(root->left) int b = isBalanced(root->right) if (a == -1 || b == -1) return -1;

    if (abs(temp) <= 1)
        return 1 + max(a, b);

    return -1;
}

// binary tree to doublylinked list
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
Node *BTToDLL(Node *root)
{
    if (root == nullptr)
    {
        return root;
    }
    static Node *prev{NULL};
    Node *head = BTToDLL(root->left);
    if (prev == nullptr)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

// cosntruct tree from inorder and preorder
int preIndex = 0;
Node *cTree(int in[], int pre[], int is, int ie)
{
    if (is <= ie)
    {
        Node *head = new Node(pre[preIndex]);
        int ind{};
        for (int i{is}; i <= ie; i++)
        {
            if (in[i] == pre[preIndex])
                ;
            {
                ind = i;
                break;
            }
        }
        preIndex++;

        head->left = cTree(in, pre, is, ind - 1);
        head->right = cTree(in, pre, ind + 1, ie);
        return head;
    }
    return nullptr;
}

// print spiral

void printSpiral(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s1;
    stack<Node *> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            cout << temp->key << " ";

            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            cout << temp->key << " ";

            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}

// my code for spiral print
void printSpiral(Node *root)
{
    int level{1};
    deque<Node *> dq{};

    dq.push_back(root);

    while (!dq.empty())
    {
        int temp = dq.size();
        if (level % 2 == 1)
        {
            while (temp--)
            {
                Node *ad = dq.back();
                dq.pop_back();
                cout << ad->data << " ";
                if (ad->left != nullptr)
                    dq.push_front(ad->left);
                if (ad->right != nullptr)
                    dq.push_front(ad->right);
            }
        }
        else
        {
            while (temp--)
            {
                Node *ad = dq.back();
                dq.pop_front();
                cout << ad->data << " ";
                if (ad->right != nullptr)
                    dq.push_back(ad->right);
                if (ad->left != nullptr)
                    dq.push_back(ad->left);
            }
        }
    }
}

// diameter of a tree
int res{};
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    res = max(res, 1 + lh + rh);
    return 1 + max(rh, lh);
}
// Lowest common ancistor of two nodes in a tree

// basic method, pass a vector and get the path of both the nodes and then compare them .

// efficient method
Node *lca(Node *root, int n1, int n2)
{

    if (root == nullptr)
    {
        return root;
    }

    if (root->key == n1 || root->key == n2)
    {
        return root;
    }

    Node *left = lca(root -= > left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left != nullptr && right != nullptr)
    {
        return root;
    }
    else
        return (left != nullptr) ? left : right;
}

// Burn a binary tree from leaf
int res{};
int burnTime(Node *root, int leaf, int &dist)
{

    if (root == nullptr)
    {
        return 0;
    }
    if (root->key == leaf)
    {
        dist = 0;
        return 1;
    }
    int ld = -1;
    int rd = -1;
    lh = burnTime(root->left, leaf, ld);
    rh = burnTime(root->right, leaf, rd);

    if (ld != -1)
    {
        dist = ld + 1;
        res = max(res, dist + rh);
    }
    else if (rd != -1)
    {
        dist = rd + 1;
        res = max(res, dist + lh);
    }
    return 1 + max(lh, rh);
}

// count the nodes in a complete binary tree

int countNode(Node *root)
{
    Node *temp = root;
    int lh = 0;
    int rh = 0;
    while (temp->left != nullptr)
    {
        temp = temp->left;
        lh++;
    }
    temp = root;
    while (temp->right != nullptr)
    {
        temp = temp->right;
        rh++;
    }

    if (lh == rh)
    {
        return pow(2, lh + 1) - 1;
    }
    else
    {
        return 1 + countNode(root->left) + countNode(root->right);
    }
}

// serialization of binary tree
const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        arr.push_back(EMPTY);
        return;
    }

    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

// deserialize
Node *deSerialize(vector<int> &arr, int &index)
{
    if (index == arr.size())
    {
        return nullptr;
    }
    if (arr[index] == -1)
    {
        return nullptr;
    }
    Node *head = new Node(arr[index]);
    index++;
    head->left = deSerialize(arr, index);
    head->right = deSerialize(arr, index);

    return head;
}

// iterative inorder traversal
void iterativeIOT(Node *root)
{
    stack<Node *> s{};
    Node *curr = root;
    while (curr != null || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}

void iterativePOT(Node *root)
{
    stack<Node *> s{};
    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->key << " ";
        if (temp->right != nullptr)
            s.push(temp->right);
        if (temp->left != nullptr)
            s.push(temp->left);
    }
}

void iterativePTO(Node *root)
{
    stack<int> s{};

    s.push(root);
    Node *curr = root;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != nullptr)
        {
            cout << curr->key << " ";

            if (curr->right != nullptr)
            {
                s.push(curr->right);
            }
            curr = curr->left;
        }
        if (s.empty() == false)
        {
            curr = s.top();
            s.pop();
        }
    }
}