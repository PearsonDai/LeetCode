92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：


输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
示例 2：

输入：head = [5], left = 1, right = 1
输出：[5]
 

提示：

链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

进阶： 你可以使用一趟扫描完成反转吗？

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int cnt=1;
        ListNode* first,*firstPrev,*second,*secondNext;
        ListNode* curr=head;
        ListNode* prev=nullptr;
        while(cnt!=left){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        firstPrev=prev;
        first=curr;
        prev=nullptr;
        while(curr&&cnt<right){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        second=curr;
        secondNext=curr->next;
        second->next=prev;
        if(left!=1){
            firstPrev->next=second;
        }
        else{
            firstPrev=second;
        }
        first->next=secondNext;
        return (left==1)?firstPrev:head;
    }
};