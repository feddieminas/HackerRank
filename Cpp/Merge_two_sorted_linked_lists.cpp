//
//  https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists
//
//  Merge_two_sorted_linked_lists.cpp
//  HacckerrankCpp
//

/*
Solution. Fully accepted
 
Ex. first testcase of testcase 0
 
while (headA && headB)
1<2 q.(A)
3<2 q.(B)
3<4 q.(A)
5<4 q.(B)
5<7 q.(A)
6<7 q.(A)
exit
1-2-3-4-5-6
A-B-A-B-A-A
 
while (headA) exit
while (headB) q.(B)
1-2-3-4-5-6-7
A-B-A-B-A-A-B
 
linkedlist
*/


#include <queue> // 0 1 2 3 4
                 // 0 front() and pop()
                 // 4 back()
                 // push() insert at the end of queue (left to right)

/*
 Merge two sorted lists A and B as one linked list
 Node is defined as
 struct Node
 {
 int data;
 struct Node *next;
 }
 */

Node* MergeLists(Node *headA, Node* headB)
{
    //if only a single linked list in input
    if (!headA) return headB;
    if (!headB) return headA;
    
    queue<Node *> q;
    
    //merge and order
    while (headA && headB) {
        if (headA->data < headB->data) {
            q.push(headA);
            headA = headA->next;
        } else {
            q.push(headB);
            headB = headB->next;
        }
    }
    
    //elements left to link from above
    while (headA) {
        q.push(headA);
        headA = headA->next;
    }
    while (headB) {
        q.push(headB);
        headB = headB->next;
    }
    
    //the linked list from queue
    Node *head = q.front();
    head->next = NULL;
    q.pop();
    
    Node *last = head;
    while (!q.empty()) {
        last->next = q.front();
        last = last->next;
        last->next = NULL;
        q.pop();
    }
    
    return head;
}