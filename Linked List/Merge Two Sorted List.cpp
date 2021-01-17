
ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    if(A==NULL) return B;
    if(B==NULL) return A;
    
    ListNode* C, head;
    
    if(A->val<=B->val)
    {
        C=A;
        A=A->next;
    }
    else
    {
        C=B;
        B=B->next;
    }

    head=C;
    
    while(A!=NULL && B!=NULL)
    {
        if(A->val<=B->val)
        {
            C->next=A;
            A=A->next;
        }
        else
        {
            C->next=B;
            B=B->next;
        }
        
        C=C->next;
    }
    
    if(A!=NULL)C->next=A;
    if(B!=NULL)C->next=B;
    
    return head;
}


Time : O(Sum of Length of Both lists)
Space : O(1)

https://www.interviewbit.com/problems/merge-two-sorted-lists/