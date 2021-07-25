21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]

迭代法，设置一个新的节点head，依次串联其元素。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode();
        ListNode *prev=head;
        while(l1!=nullptr&&l2!=nullptr){
            if(l1->val<l2->val){
                prev->next=l1;
                l1=l1->next;
            }
            else{
                prev->next=l2;
                l2=l2->next;
            }
            prev=prev->next;
        }
        prev->next=(l1==nullptr)?l2:l1;
        return head->next;
    }
};