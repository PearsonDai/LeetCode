2. 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum,carry=0;
        ListNode *res=new ListNode(-1);
        ListNode *head=res;
        while(l1||l2){
            ListNode *node=new ListNode();
            if(l1==nullptr){
                sum=l2->val+carry;
                l2=l2->next;
            }
            else if(l2==nullptr){
                sum=l1->val+carry;
                l1=l1->next;
            }
            else{
                sum=l1->val+l2->val+carry;
                l1=l1->next;
                l2=l2->next;
            }
            node->val=sum%10;
            carry=sum/10;
            res->next=node;
            res=res->next;
        }
        if(carry==1){
            res->next=new ListNode(1);
        }
        return head->next;
    }
};
/*图一乐的基本方法，但是必然会溢出
class Solution {
public:
    int list2num(ListNode* L){
        int res=0;
        int pow=1;
        while(L){
            res+=(L->val)*pow;
            pow*=10;
            L=L->next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1=list2num(l1);
        int num2=list2num(l2);
        int sum=num1+num2;
        ListNode *ret=new ListNode(-1);
        ListNode *head=ret;
        while(sum){
            ListNode *node=new ListNode(sum%10);
            ret->next=node;
            ret=ret->next;
            sum/=10;
        }
        return head->next;
    }
};
*/