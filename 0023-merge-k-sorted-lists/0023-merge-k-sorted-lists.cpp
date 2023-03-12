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
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* h1 = a;
        ListNode* h2 = b;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(h1 && h2)
        {
            if(h1->val<h2->val){
                temp->next = h1;
                h1= h1->next;
            }
                
            else{
                temp->next = h2;
                h2=h2->next;
            }
                
            temp=temp->next;
        }
        if(h1!=NULL)
            temp->next= h1;
        
        if(h2!=NULL)
            temp->next = h2;
        
        return ans->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size()-1;i++)
            lists[i+1]= merge(lists[i],lists[i+1]);
    
        return lists[lists.size()-1];
    }
};