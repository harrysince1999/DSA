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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        for(auto i: lists)
        {
            ListNode* x = i;
            while(x)
            {
                temp->next = x;
                temp= temp->next;
                x= x->next;
            }
        }
        head= head->next;
        
        ListNode* i=head;
        ListNode* j=head;
        while(i)
        {
            j= head;
            while(j)
            {
                if(i->val<j->val)
                    swap(i->val,j->val);
                j=j->next;
            }
            i=i->next;
        }
        
        return head;
    }
};