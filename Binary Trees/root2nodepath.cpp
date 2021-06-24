#include <bits/stdc++.h>
using namespace std;

vector<int> *r2np(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == data)
    {
        vector<int> *res = new vector<int>();
        res.push_back(root->data);
        return res;
    }

    vector<int> *res = new vector<int>();
    res = r2np(root->left, data);
    if (res != NULL)
    {
        res.push_back(root->data);
        retrun res;
    }

    vector<int> *res = new vector<int>();
    res = r2np(root->right, data);
    if (res != NULL)
    {
        res.push_back(root->data);
        retrun res;
    }
    else
    {
        return NULL;
    }
}