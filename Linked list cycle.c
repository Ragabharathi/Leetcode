
Input: head = [3,2,0,-4], pos = 1
Output: true



bool hasCycle(struct ListNode *head) {
    if(head==NULL){return false;}
    struct ListNode *fast=head;
    struct ListNode *slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){return true;}
    }
    return false; 
}
