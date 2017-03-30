//
//  https://www.hackerrank.com/challenges/tree-level-order-traversal
//
//  Tree_Level_Order_Traversal.cpp
//  HacckerrankCpp
//

/*
 Solution. Fully accepted
 */


/*
 struct node
 {
 int data;
 node* left;
 node* right;
 }*/


#include <queue> // 0 1 2 3 4
                 // 0 front() and pop()
                 // 4 back()
                 // push() insert at the end of queue (left to right)

using namespace std;

void LevelOrder(node * root)
{
    if(root==NULL)
        return;
    
    queue<node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        node* cur=q.front();
        q.pop();
        cout<<cur->data<<" ";
        if(cur->left!=NULL)
            q.push(cur->left);
        if(cur->right!=NULL)
            q.push(cur->right);
    }
}

