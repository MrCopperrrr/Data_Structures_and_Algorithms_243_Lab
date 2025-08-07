#ifndef LINKEDLIST_SORT_H
#define LINKEDLIST_SORT_H

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeSortList(ListNode* head);
ListNode* quickSortList(ListNode* head);

#endif // LINKEDLIST_SORT_H
