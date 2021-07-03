Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]


struct ListNode* reverseList(struct ListNode* head){
     struct ListNode *cur=head;
     struct ListNode *prev=NULL;
     struct ListNode *next=NULL;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;

}
