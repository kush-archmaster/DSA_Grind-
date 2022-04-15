#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    // ^ ListNode *curr = head, *prevFirst = NULL; //^prev to mark the new head
    // ^ bool isFirstPass = true;

    // ^ if u want to reverse the nodes < k also
    // ^         while(curr!=NULL)
    // ^         {
    // ^             ListNode *first = curr,*prev = NULL ;
    // ^             int count = 0;

    // ^             while(curr!=NULL && count<k)
    // ^             {
    // ^                 ListNode *next = curr->next;
    // ^                 curr->next = prev;
    // ^                 prev = curr;
    // ^                 curr = next;
    // ^                 count++;
    // ^             }

    // ^                  if(isFirstPass)
    // ^                 {
    // ^                     head=prev;
    // ^                     isFirstPass = false;
    // ^                 }
    // ^                 else
    // ^                      prevFirst->next = prev;

    // ^             prevFirst = first;
    // ^         }
    // ^         return head;

    //* Method 2 - as required that if num of nodes left < k , then as it is
    ListNode *cursor = head;
    //* to check if the number of nodes are greater than K atleast, then only we will swap
    for (int i = 0; i < k; i++)
    {
        if (cursor == NULL)
            return head;
        cursor = cursor->next;
    }

    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *nxt = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }

    //& 1-> 2-> 3 ===> 3->2->1 head is 1
    head->next = reverseKGroup(curr, k); //^ recursive call for reversing next group
    return prev;
}

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(6);
    l1->next->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next->next = new ListNode(10);

    l1 = reverseKGroup(l1, 3);
    while (l1 != NULL)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    return EXIT_SUCCESS;
}