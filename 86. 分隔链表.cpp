86. 分隔链表
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

示例 1：


输入：head = [1,4,3,2,5,2], x = 3
输出：[1,2,2,4,3,5]
示例 2：

输入：head = [2,1], x = 2
输出：[1,2]
 

提示：

链表中节点的数目在范围 [0, 200] 内
-100 <= Node.val <= 100
-200 <= x <= 200

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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr) return nullptr;
        ListNode* dummy=new ListNode(0,head);
        ListNode* curr=head,*prev=dummy;
        bool flag=false;
        ListNode* targetNode;
        while(curr){
            if(flag==false){
                if(curr->val>=x){
                    flag=true;
                    targetNode=prev;
                }
                curr=curr->next;
                prev=prev->next;
            }
            else{
                if(curr->val<x){
                    ListNode* temp=curr;
                    prev->next=curr->next;
                    curr=curr->next;
                    temp->next=targetNode->next;
                    targetNode->next=temp;
                    targetNode=targetNode->next;
                }
                else{
                    curr=curr->next;
                    prev=prev->next;
                }
            }
        }
        return dummy->next;
    }
};