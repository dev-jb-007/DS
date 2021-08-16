//
//  main.cpp
//  BST
//
//  Created by Dev Patel on 12/08/21.
//

#include <iostream>
#include<limits.h>
using namespace std;
#include "../Header.h"
template <class T>
TreeNode<T>* binarySearch(TreeNode<T> *t,int data){
    while(t)
    {
        if(t->val==data)
        {
            return t;
        }
        else if(t->val<data){
            t=t->right;
        }
        else{
            t=t->left;
        }
    }
    return NULL;
}
template <class T>
void InsertInBinaryTree(TreeNode<T> *t,int data){
    TreeNode<T> *q;
    while(t)
    {
        q=t;
        if(t->val==data)
        {
            return;
        }
        else if(t->val<data){
            t=t->right;
        }
        else{
            t=t->left;
        }
    }
    t=new TreeNode<T>;
    t->val=data;
    t->left=NULL;
    t->right=NULL;
    if(q->val>data)
    {
        q->left=t;
    }
    else{
        q->right=t;
    }
}
template <class T>
TreeNode<T>* RecursiveInsert(TreeNode<T> *t,int data)
{
    if(t==NULL)
    {
        TreeNode<T> *q=new TreeNode<T>;
        q=new TreeNode<T>;
        q->val=data;
        q->left=q->right=NULL;
        return q;
    }
    if(t->val>data)
    {
        t->left=RecursiveInsert(t->left,data);
    }
    else if(t->val<data)
    {
        t->right=RecursiveInsert(t->right,data);
    }
    return t;
}
template <class T>
int height(TreeNode<T> *t){
    int x,y;
    if(t)
    {
        x=height(t->left);
        y=height(t->right);
        if(x>y)
        {
            return x+1;
        }
        else{
            return y+1;
        }
    }
    return 0;
}
template <class T>
TreeNode<T> *InPre(TreeNode<T> *p)
{
    while(p&&p->right)
    {
        p=p->right;
    }
    return p;
}
template <class T>
TreeNode <T>* Delete(TreeNode<T> *t,int data)
{
    if(!t)
    {
        return NULL;
    }
    if(!t->left&&!t->right)
    {
        delete(t);
        return NULL;
    }
    if(data<t->val)
    {
        t=Delete(t->left,data);
    }
    else if(data>t->val)
    {
        t=Delete(t->right, data);
    }
    else{
        if(height(t->left)>height(t->right))
        {
            TreeNode<T> *q;
            q=InPre(t->left);
            t->val=q->val;
            t->left=Delete(t->left,q->val);
        }
        else{
            TreeNode<T> *q;
            q=InPre(t->right);
            t->val=q->val;
            t->right=Delete(t->right,q->val);
        }
    }
    return t;
}
template <class T>
TreeNode<T>* createBST(TreeNode<T> *root,int n,int A[])
{
    Stack<TreeNode<T>*> s;
    root=new TreeNode<T>;
    int i=0;
    root->val=A[i++];
    root->left=root->right=NULL;
    TreeNode<T> *p=root;
    while(i<n)
    {
        if(p->val>A[i])
        {
            TreeNode<T> *t=new TreeNode<T>;
            t->val=A[i++];
            t->left=t->right=NULL;
            p->left=t;
            s.push(p);
            p=t;
        }
        else if(p->val<A[i]&&A[i]<(s.empty()?INT_MAX:s.top()->val))
        {
            TreeNode<T> *t=new TreeNode<T>;
            t->val=A[i++];
            t->left=t->right=NULL;
            p->right=t;
            p=t;
        }
        else{
            p=s.top();
            s.pop();
        }
    }
    return root;
}
int main(int argc, const char * argv[]) {
    int A[7]={10,20,30,40,50,60,70};
    Tree<int> t;
    t.root=createBST(t.root, 7, A);
    t.LeverOrder(t.root);
    return 0;
}
