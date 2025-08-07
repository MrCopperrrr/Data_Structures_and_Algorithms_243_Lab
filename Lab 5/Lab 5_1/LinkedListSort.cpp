#include "LinkedListSort.h"
#include <utility>

// Helper to split the list for merge sort
static ListNode* getMiddle(ListNode* head) {
    if (!head) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge two sorted lists
static ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Merge Sort for Linked List
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* mid = getMiddle(head);
    ListNode* right = mid->next;
    mid->next = nullptr;
    ListNode* left = head;
    left = mergeSortList(left);
    right = mergeSortList(right);
    return merge(left, right);
}

// Partition for Quick Sort
static std::pair<ListNode*, ListNode*> partition(ListNode* head, int pivot) {
    ListNode leftDummy(0), rightDummy(0);
    ListNode* left = &leftDummy;
    ListNode* right = &rightDummy;
    ListNode* curr = head;
    while (curr) {
        if (curr->val < pivot) {
            left->next = curr;
            left = left->next;
        } else {
            right->next = curr;
            right = right->next;
        }
        curr = curr->next;
    }
    left->next = nullptr;
    right->next = nullptr;
    return {leftDummy.next, rightDummy.next};
}

// Quick Sort for Linked List
ListNode* quickSortList(ListNode* head) {
    if (!head || !head->next) return head;
    int pivot = head->val;
    ListNode* curr = head->next;
    ListNode* left = nullptr;
    ListNode* right = nullptr;
    ListNode* leftTail = nullptr;
    ListNode* rightTail = nullptr;
    // Partition
    while (curr) {
        ListNode* next = curr->next;
        if (curr->val < pivot) {
            curr->next = left;
            left = curr;
        } else {
            curr->next = right;
            right = curr;
        }
        curr = next;
    }
    left = quickSortList(left);
    right = quickSortList(right);
    // Concatenate
    ListNode* newHead = left ? left : head;
    if (left) {
        leftTail = left;
        while (leftTail->next) leftTail = leftTail->next;
        leftTail->next = head;
    }
    head->next = right;
    return newHead;
}
