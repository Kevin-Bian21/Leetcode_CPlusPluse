#include "add_two_numbers.h"
#include <iostream>
using namespace std;

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* temp = nullptr;
    ListNode* head = nullptr;
    int carry = 0;
    int gw = 0;
    while (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val + carry;
        gw = sum % 10;
        if (head == nullptr) {
            head = new ListNode(gw);
            temp = head;
        }
        else {
            ListNode* p = new ListNode(gw);
            temp->next = p;
            temp = temp->next;
        }
        if (sum > 0) {
            carry = sum / 10;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != nullptr) {
        int sum = l1->val + carry;
        gw = sum % 10;
        if (sum > 0) {
            carry = sum / 10;
        }
        temp->next = new ListNode(gw);
        temp = temp->next;
        l1 = l1->next;
    }
    while (l2 != nullptr) {
        int sum = l2->val + carry;
        gw = sum % 10;
        if (sum > 0) {
            carry = sum / 10;
        }
        temp->next = new ListNode(gw);
        temp = temp->next;
        l2 = l2->next;
    }
    if (carry > 0) {
        temp->next = new ListNode(carry);
        temp = temp->next;
    }
    return head;
}
//·´×ªÁ´±í
ListNode* Solution::reverse(ListNode* l) {
    ListNode *pre = nullptr;
    ListNode *curr = l;
    ListNode *temp = nullptr;
    while (curr != nullptr) {
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    return pre;
}

int main() {
    // L1 5->4->3->2->1
    ListNode *L1 = new ListNode(5);
    int i = 5;
    ListNode *temp = L1;
    while (--i) {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    ListNode* L2 = new ListNode(5);
    int j = 5;
    ListNode* p = L2;
    while (--j) {
        p->next = new ListNode(j);
        p = p->next;
    }
    Solution s;
    ListNode* rL1 = s.reverse(L1);
    ListNode * ll = s.addTwoNumbers(rL1, L2);
    while (ll != nullptr) {
        cout << ll->val << "      " ;
        ll = ll->next;
    }
    return 0;
}

