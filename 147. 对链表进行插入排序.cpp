147. 对链表进行插入排序
对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

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
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        ListNode* dummy=new ListNode(0,head);
        ListNode* lastSorted=head;
        ListNode* curr=head->next;
        while(curr!=nullptr){
            if(lastSorted->val<curr->val){
                lastSorted=lastSorted->next;
                curr=curr->next;
            }
            else{
                ListNode* prev=dummy;
                while(prev->next->val<curr->val){
                    prev=prev->next;
                }
                lastSorted->next=curr->next;
                curr->next=prev->next;
                prev->next=curr;
                curr=lastSorted->next;
            }
        }
        return dummy->next;
    }
};