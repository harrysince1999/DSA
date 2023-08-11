//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node* add(Node* l1, Node* l2)
    {
        int carry = 0;
        Node* ans = new Node(-1);
        Node* temp = ans;
        while(l1 && l2)
        {
            int sum = l1->data + l2->data + carry;
            carry = sum/10;
            sum = sum%10;
            
            temp->next = new Node(sum);
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = l1->data+ carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new Node(sum);
            temp=temp->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = l2->data+ carry;
            carry = sum/10;
            sum = sum%10;
            temp->next = new Node(sum);
            temp=temp->next;
            l2 = l2->next;
        }
        if(carry)
        {
            temp->next = new Node(carry);
            temp = temp->next;
            carry = 0;
        }
        return ans->next;
    }
    Node* addOne(Node *head) 
    {
        Node* a = new Node(1);
        head = reverse(head);
        Node* ans = add(head,a);
        ans = reverse(ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends