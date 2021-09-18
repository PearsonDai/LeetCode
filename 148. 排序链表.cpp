148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        int len=0;
        ListNode* temp=head;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        ListNode* dummy=new ListNode(0,head);
        for(int sublen=1;sublen<len;sublen<<=1){
            ListNode* prev=dummy,* curr=dummy->next;
            while(curr!=nullptr){
                ListNode* head1=curr;
                for(int i=1;i<sublen&&curr->next!=nullptr;i++){
                    curr=curr->next;
                }
                ListNode* head2=curr->next;
                curr->next=nullptr;
                curr=head2;
                for(int i=1;i<sublen&&curr!=nullptr&&curr->next!=nullptr;i++){
                    curr=curr->next;
                }
                ListNode* next=nullptr;
                if(curr!=nullptr){
                    next=curr->next;
                    curr->next=nullptr;
                }
                ListNode* merged=merge(head1,head2);
                prev->next=merged;
                while(prev->next!=nullptr){
                    prev=prev->next;
                }
                curr=next;
            }
        }
        return dummy->next;      
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy=new ListNode();
        ListNode* node=dummy;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<l2->val){
                node->next=l1;
                l1=l1->next;
            }
            else{
                node->next=l2;
                l2=l2->next;
            }
            node=node->next;
        }
        node->next=(l1==nullptr)?l2:l1;
        return dummy->next;
    }
};