剑指 Offer 25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：

0 <= 链表长度 <= 1000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* dummy=new ListNode(0);
        ListNode* node=dummy;
        while(l1&&l2){
            if(l1->val<=l2->val){
                node->next=l1;
                l1=l1->next;
            }
            else{
                node->next=l2;
                l2=l2->next;
            }
            node=node->next;
        }
        if(l1==nullptr) node->next=l2;
        else node->next=l1;
        return dummy->next;
    }
};