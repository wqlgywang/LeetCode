/*
*Given a linked list, remove the nth node from the end of list and return its head.
*For example,
*   Given linked list: 1->2->3->4->5, and n = 2.
*
*   After removing the second node from the end, the linked list becomes 1->2->3->5.
*Note:
*Given n will always be valid.
*Try to do this in one pass. 
*/
//own solution:要注意如何去头去尾
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N=0;
        int m =1;
        ListNode* temp;
        ListNode* l;
        ListNode* temp1;
        temp =temp1= head;
        while(temp){
            N++;
            temp = temp->next;
        }
        int i = N-n+1;
        while(head){
            if(i == 1){head = head->next;return head;}
            else if(i<0||i>N){return NULL;}
            else if(i==N){
                l=head->next;
                while(l->next){
                    head=head->next;
                    l=l->next;
                }
                head->next=NULL;
                return temp1;
            }
            else{
                if(m+1==i){
                    l=head->next;
                    head->next = l->next;
                    return temp1;
                }
                head=head->next;
                m++;
            }
        }
        return NULL;
    }
};

//双指针思想
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
            return NULL;
            
        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 0; i < n - 1; i++)
            q = q->next;
            
        while(q->next)
        {
            pPre = p;
            p = p->next;
            q = q->next;
        }
        
        if (pPre == NULL)
        {
            head = p->next;
            delete p;
        }
        else
        {
            pPre->next = p->next;
            delete p;
        }
        
        return head;
    }
};
