445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例1：

输入：l1 = [7,2,4,3], l2 = [5,6,4]
输出：[7,8,0,7]
示例2：

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[8,0,7]
示例3：

输入：l1 = [0], l2 = [0]
输出：[0]
 

提示：

链表的长度范围为 [1, 100]
0 <= node.val <= 9
输入数据保证链表代表的数字无前导 0
 

进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

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
        stack<int> stk1;
        stack<int> stk2;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        while(node1){
            stk1.push(node1->val);
            node1 = node1->next;
        }
        while(node2){
            stk2.push(node2->val);
            node2 = node2->next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* prev = nullptr;
        int carry = 0, num = 0, x = 0, y =0;
        while(!stk1.empty() || !stk2.empty() || carry!= 0){
            if(!stk1.empty()){
                x = stk1.top();
                stk1.pop();
            }
            if(!stk2.empty()){
                y = stk2.top();
                stk2.pop();
            }
            num = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            ListNode* node = new ListNode(num, prev);
            dummy->next = node;
            prev = node;
            x = 0;
            y = 0;
        }
        return dummy->next;
    }
};