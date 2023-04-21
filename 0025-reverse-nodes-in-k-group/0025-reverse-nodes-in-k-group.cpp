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
    int findLen(ListNode* head)
    {
        int l=0;
        while(head)
        {
            l++;
            head=head->next;
        }
        return l;
    }
    ListNode* solve(ListNode* head, int l, int k){
        if(head==NULL || l<k)   return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count = 0;
        while(curr!=NULL && count<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            count++;
            
            l--;
        }
        
        if(head!=NULL)
            head->next = reverseKGroup(next,k);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int l = findLen(head);
        return solve(head,l,k);
    }
};