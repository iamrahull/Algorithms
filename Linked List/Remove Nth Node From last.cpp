
ListNode* Solution::removeNthFromEnd(ListNode* head, int Nth) {

    if(head==NULL) return head;

    ListNode *fastPointer=head, *nextListHead=NULL;
    
    while(Nth-- && fastPointer!=NULL)
    {
        fastPointer=fastPointer->next;
        
    }

    // If Nth is Greater than Length of List delete the first Element.
    if(fastPointer==NULL) return head->next;

    nextListHead=head;

    while(fastPointer->next!=NULL)
    {
        head=head->next;
        fastPointer=fastPointer->next;
    }

    if(head==fastPointer) return head->next; // delete First Element
    head->next=head->next->next;

    return nextListHead;
    
}
Time : O(Length of the list)
Space : O(1)

https://www.interviewbit.com/problems/merge-two-sorted-lists/