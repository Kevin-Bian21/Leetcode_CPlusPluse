#include "remove_nth_node_from_end_of_list.h"

#include <iostream>
using namespace std;

ListNode* CRemoveNthNodeFromEndOfList::removeNthFromEnd(ListNode* head, int n) {
    ListNode* first = head;
    ListNode* second = head;
    if (head->next == nullptr) {
        return head->next;
    }
    while (second->next != nullptr) {
        while (n > 0) {
            second = second->next;
            n--;
            if (second== nullptr) {  //说明删除的是头节点
                head = head->next;
                return head;
            }
        }
        if (second->next != nullptr) {
            first = first->next;
            second = second->next;
        }
    }
    if (first->next) {
        first->next = first->next->next;
    }
    return head;
}

int main() {
	ListNode* head = new ListNode(1);
	ListNode* temp = head;
	int i = 2;
	while (i <= 3) {
		temp->next = new ListNode(i);
		temp = temp->next;
		i++;
	}
	CRemoveNthNodeFromEndOfList obj;
	ListNode *res = obj.removeNthFromEnd(head, 3);
	while (res) {
		cout << res->val << " ";
		res = res->next;
	}
	return 0;
}
