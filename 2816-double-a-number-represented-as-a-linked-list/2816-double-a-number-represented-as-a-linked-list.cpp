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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(curr){
            ListNode* next=curr->next;
            curr->next = prev;
            prev= curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode* head1 = reverse(head);
        
        ListNode* node = head1;
        int carry = 0;
        ListNode* prev;
        while(node){
            int value = (node->val)*2 + carry;
            int help1 = value%10;
            node->val = help1;
            carry = value/10;
            
            prev= node;
            
            node = node->next;
        
        }
        
        if(carry){
            ListNode* newone = new ListNode(carry);
            prev->next = newone;
            newone->next = NULL;
        }
        
        ListNode* head2= reverse(head1);
        
        return head2;
    }
};