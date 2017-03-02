/*开始自己写的问题答案，弱爆了
*首先l1和l2不一定全部有值，其次l1和l2不一定长度都相等，
*对于最后要输出的新值完全可以用new来创建
*/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3;
        ListNode *l4;
        ListNode *l5;
        l3 -> val = (l1->val+l2->val)%10;
        l3 -> next = l4;
        l4 -> val = (l1->next->val + l2->next->val + (l1->val+l2->val)/10)%10;
        l4 -> next = l5;
        l5 -> val = (l1->next->next->val + l2->next->next->val + (l1->next->val + l2->next->val + (l1->val+l2->val)/10)/10)%10;
        l5 -> next = NULL;
        return l3;
    }
};
