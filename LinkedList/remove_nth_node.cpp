#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
};

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == NULL)
        return NULL;

    //& calculating the length of LL
    int length_of_ll = 0;
    ListNode *curr = head;
    while (curr)
    {
        length_of_ll++;
        curr = curr->next;
    }

    //& if the length of linked list is same as n
    if (n == length_of_ll)
    {
        ListNode *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // for general scenario
    ListNode *slow = head, *fast = head, *temp = NULL;

    for (int count = 0; count < n; count++)
        if (fast != NULL)
            fast = fast->next;

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // we are the pointer before the node to be removed
    temp = slow->next;
    slow->next = slow->next->next;
    delete (temp);

    return head;
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

    l1 = removeNthFromEnd(l1, 2); //& removing 4th element from end i.e 6

    while (l1 != NULL)
    {
        cout << l1->val << " ";
        l1 = l1->next;
    }
    return EXIT_SUCCESS;
}