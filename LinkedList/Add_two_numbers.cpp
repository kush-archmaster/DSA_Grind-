#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int k)
    {
        val = k;
        next = NULL;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *sum = NULL, //& final linkedlist
        *prev = NULL,
             *temp = NULL;
    int carry = 0; //& the carry part while adding if value goes beyond 10

    while (l1 != NULL || l2 != NULL)
    {
        int num1 = (l1 != NULL) ? l1->val : 0; //& num from linked list1
        int num2 = (l2 != NULL) ? l2->val : 0; //& num from linked list2
        int sumTotal = num1 + num2 + carry;
        carry = (sumTotal > 9) ? 1 : 0; //& if sum>9 then carry will be 1 to next node

        temp = new ListNode(sumTotal % 10); //& creating a new node for the final linked list

        //& if its the first node for the final list
        if (prev == NULL)
        {
            sum = temp;
            prev = sum;
        }
        else
        {
            prev->next = temp;
            prev = prev->next;
        }

        //& if anyone of them becomes null then dont traverse that list anymore
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    //* if at last the value of carry =1, then a new node will be created */
    if (carry == 1)
        prev->next = new ListNode(1);

    return sum; //& head of the final linked list
}

int main(int argc, char *argv[])
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    ListNode *sum = addTwoNumbers(l1, l2);

    while (sum != NULL)
    {
        cout << sum->val << " ";
        sum = sum->next;
    }

    return EXIT_SUCCESS;
}