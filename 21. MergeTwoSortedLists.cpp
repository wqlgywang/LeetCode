/*Merge two sorted linked lists and return it as a new list. 
*The new list should be made by splicing together the nodes of the first two lists.*/

/*by myself,but has fault:

*Input:
*[2][1]
*Output:
*[1]
*Expected:
*[1,2]*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        ListNode *head,*p;
        if(l1==NULL && l2==NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l2->val < l1->val){
            head=l2;
            l2 = l2->next;
        }
        else{
            head = l1;
            l1 = l1->next;
        }
        p = head->next;
        while(l1!=NULL && l2!=NULL){
            if(l2->val<=l1->val){
                p = l2;
                l2 = l2->next;
                p = p->next;    
            }
            else{
                p = l1;
                l1 = l1->next;
                p = p->next;
            }
        }
        while(l1!=NULL){
            p = l1;
            l1 = l1->next;
            p = p -> next;
        }
        while(l2!=NULL){
            p = l2;
            l2 = l2->next;
            p = p ->next;
        }
        return head;
    }
};
/*a little change:结构体赋值的时候要先pre->next=l1,
*然后才能pre=pre->next*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=NULL,*p=NULL;
        if(l1==NULL && l2==NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l2->val <= l1->val){
            head=l2;
            l2 = l2->next;
        }
        else{
            head = l1;
            l1 = l1->next;
        }
        p = head;
        while(l1!=NULL && l2!=NULL){
            
            if(l2->val<=l1->val){
                p->next = l2;
                l2 = l2->next;
               
            }
            else{
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }
        if(l2==NULL){
            while(l1!=NULL){
                
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
        }
        if(l1==NULL){
            while(l2!=NULL){
                
                p->next = l2;
                l2 = l2->next;
                p = p ->next;
            }
        }
        return head;
    }
};
