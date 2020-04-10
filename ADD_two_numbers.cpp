/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and 
return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/
//code snippet

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
        
        int i1,i2;
        int sum = l1->val + l2->val;
        int carry;
       
        if(sum>9){
            sum = sum%10;
            carry = 1;
        }
        else
            carry =0;
        
        ListNode *q = new ListNode(sum);
        
        l1 = l1->next;
        l2 = l2->next;
        
        ListNode *p1 = q, *p2;
        
        while(l1!=NULL || l2!=NULL){
            
            if(l2 == NULL)
                i2 = 0;
            else
                i2 = l2->val;
            
            if(l1==NULL)
                i1 = 0;
            else
                i1 = l1->val;
            
            sum = i1 + i2 + carry;
            
            if(sum>9){
                sum = sum%10;
                carry = 1;
             }
             else
                carry =0;
            
            p2 = new ListNode(sum);
            p1->next = p2;
            p1 = p2;
            
            if(l1 != NULL)
                l1 = l1->next;
            if(l2 !=NULL)
                l2 = l2->next;
            
        }
        
        if(carry ==  1){
            p2 = new ListNode(1);
            p1->next = p2;
            p2->next = NULL;
        }
        else
            p1->next = NULL;
        
        return q;   
    }
};
