234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：

输入：head = [1,2,2,1]
输出：true
示例 2：

输入：head = [1,2]
输出：false

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
    bool isPalindrome(ListNode* head) {
        ListNode* dummy=new ListNode(0,head);
        ListNode* slow=dummy,*fast=dummy;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prehalfHead=dummy->next;
        ListNode* posthalfHead=slow->next;
        slow->next=nullptr;
        ListNode* reversedPost=reverseList(posthalfHead);
        bool res=cmp2Lists(prehalfHead,reversedPost);
        slow->next=reverseList(reversedPost);
        return res;
    }
    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    bool cmp2Lists(ListNode* head1,ListNode* head2){
        while(head2!=nullptr){
            if(head1->val!=head2->val){
                return false;
            }
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
};