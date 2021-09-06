61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

示例 1：


输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：


输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return nullptr;
        if(k==0) return head;
        int cnt=0;
        ListNode* node=head;
        while(node){
            cnt++;
            node=node->next;
        }
        k=k%cnt;
        if(k==0) return head;
        node=head;
        for(int i=1;i<cnt-k;i++){
            node=node->next;
        }
        ListNode* newHead=node->next;
        node->next=nullptr;
        node=newHead;
        while(node->next){
            node=node->next;
        }
        node->next=head;
        return newHead;
    }
};