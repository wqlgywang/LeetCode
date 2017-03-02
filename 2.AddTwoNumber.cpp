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
/*
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
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*correct answer*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        int valres = (l1->val+l2->val)%10; 
        int carry = (l1->val+l2->val)/10;
        ListNode *start = new ListNode(valres);
        ListNode *tail = start;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            valres = (l1->val+l2->val+carry)%10;
            carry = (l1->val+l2->val+carry)/10;
            ListNode *temp = new ListNode(valres);
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
            l2 = l2->next;
        }
        /*whether while has excute order*/
        while(l1){
            valres = (l1->val+carry)%10;
            carry = (l1->val+carry)/10;
            ListNode *temp = new ListNode(valres);
            tail->next = temp;
            tail = temp;
            l1 = l1->next;
        }
        while(l2){
            valres = (l2->val+carry)%10;
            carry = (l2->val+carry)/10;
            ListNode *temp = new ListNode(valres);
            tail->next = temp;
            tail = temp;
            l2 = l2->next;
        }
        if(!l1 && !l2 && carry){
            ListNode *temp = new ListNode(carry);
            tail->next = temp;
        }
        return start;
    }
};
