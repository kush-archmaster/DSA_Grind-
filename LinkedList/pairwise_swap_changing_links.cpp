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

ListNode *swapPairs(ListNode *head)
{
    //& base case when no.of nodes < 2
    if (head == NULL || head->next == NULL)
        return head;

    //& for first two nodes since head will be updated after reversing
    ListNode *prev = head, *curr = head->next->next;
    head = head->next; //& second element will be the new head
    head->next = prev;

    //& for rest of the intermediate nodes
    while (curr != NULL && curr->next != NULL)
    {
        ListNode *next = curr->next->next;
        prev->next = curr->next;
        prev = curr;
        curr->next->next = curr;
        curr = next;
    }

    //& for odd number of nodes we need to attach the last node
    prev->next = curr;

    return head;
}

/*

*  1 2 3 4

*  prev = 1, head = 2
*  2 1

*/

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    l1->next->next->next->next->next = new ListNode(6);
    l1->next->next->next->next->next->next = new ListNode(9);

    l1 = swapPairs(l1);
    while (l1 != NULL)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }

    return EXIT_SUCCESS;
}