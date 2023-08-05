#pragma once

// Define ListNode
struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {};
	ListNode(int val) : val(val), next(nullptr) {};
	ListNode(int val, ListNode* next) : val(val), next(next) {};
};
class CMergeTwoSortedLists
{
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);  //µü´ú·¨
	ListNode* mergeTwoListsRecursion(ListNode* l1, ListNode* l2);  //µÝ¹é·¨
};

