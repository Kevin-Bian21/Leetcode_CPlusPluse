#include "merge_two_sorted_lists.h"
#include <iostream>
using namespace std;

ListNode* CMergeTwoSortedLists::mergeTwoLists(ListNode* list1, ListNode* list2) {
	if (list1 == nullptr)
		return list2;
	if (list2 == nullptr)
		return list1;
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	while (list1 && list2) {
		if (list1->val < list2->val) {
			cur->next = list1;
			list1 = list1->next;
		}
		else {
			cur->next = list2;
			list2 = list2->next;
		}
		cur = cur->next;
	}
	while (list1) {
		cur->next = list1;
		cur = cur->next;
		list1 = list1->next;
	}
	while (list2) {
		cur->next = list2;
		cur = cur->next;
		list2 = list2->next;
	}
	return head->next;

}

ListNode* CMergeTwoSortedLists::mergeTwoListsRecursion(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr) {
		return l2;
	}
	else if (l2 == nullptr) {
		return l1;
	}
	else if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

int main() {
	ListNode* list1 = new ListNode(1);
	ListNode* list2 = new ListNode(2);
	int i = 12;
	ListNode* p = list1;
	ListNode* q = list2;
	while (i < 10) {
		p->next = new ListNode(++i);
		q->next = new ListNode(++i);
		p = p->next;
		q = q->next;
	}

	CMergeTwoSortedLists obj;
	ListNode * res = obj.mergeTwoLists(list1, list2);
	while (res) {
		std::cout << res->val << "   ";
		res = res->next;
	}
	return 0;
}