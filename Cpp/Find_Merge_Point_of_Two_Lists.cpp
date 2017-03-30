//
//  https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists
//
//  Find_Merge_Point_of_Two_Lists.cpp
//  HacckerrankCpp
//

/*
 Solution. Fully accepted
*/


/*
 Find merge point of two linked lists
 Node is defined as
 struct Node
 {
 int data;
 Node* next;
 }
 */


#include <stack> // 0 1 2 3 4
                 // 4 top() and pop()
                 // push() insert at the end of stack (left to right)

int FindMergeNode(Node *headA, Node *headB)
{
    stack<Node*> A, B;
    Node *pA=headA, *pB=headB; //redeclare node pointer parameters
    
    while (pA) {
        A.push(pA);
        pA=pA->next;
    }
    
    while (pB) {
        B.push(pB);
        pB=pB->next;
    }
    
    int last=0;
    while (!A.empty() && !B.empty()) {
        if(A.top()->data==B.top()->data) {
            last=A.top()->data; //first store merge point(s) then pop()
            A.pop();
            B.pop();
        }
        else
            return last;
    }
    
    return 0;
}

