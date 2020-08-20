class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *curr=head;
        ListNode *prev=NULL;
        ListNode *next=NULL;
        while(curr->next!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        curr->next=prev;
        return curr;
    }
};