ListNode* deleteDuplicheadtes(ListNode* head) {
    if(head==NULL)return head;
    ListNode* nextListHead=head;
    while(head->next!=NULL)
    {
        if(head->next->val==head->vheadl)
        {
            head->next=head->next->next;
        }
        else head=head->next;
    }
    return nextListHead;
    
    
}

Time: O(Length of List)
Space: O(1)

https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/