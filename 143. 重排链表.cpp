143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

 L0 → L1 → … → Ln-1 → Ln 
请将其重新排列后变为：

L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。


示例 1:

输入: head = [1,2,3,4]
输出: [1,4,2,3]
示例 2:

输入: head = [1,2,3,4,5]
输出: [1,5,2,4,3]

提示：

链表的长度范围为 [1, 5 * 104]
1 <= node.val <= 1000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        ListNode* head2=mid->next;
        mid->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=head2;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head2=prev;
        ListNode* l1=head;
        ListNode* l2=head2;
        while(l1!=nullptr&&l2!=nullptr){
            ListNode* l1_next=l1->next;
            ListNode* l2_next=l2->next;
            l1->next=l2;
            l1=l1_next;
            l2->next=l1;
            l2=l2_next;
        }
    }
};