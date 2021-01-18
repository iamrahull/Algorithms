 ListNode * partition(ListNode * OriginalList, int B) {

     ListNode * smallerListHead = NULL, * smallerList = NULL, * biggerList = NULL, * biggerListHead = NULL;

     while (OriginalList != NULL) {
         if (OriginalList -> val < B) {
             if (smallerListHead == NULL) {
                 smallerList = OriginalList;
                 smallerListHead = OriginalList;
             } else {
                 smallerList -> next = OriginalList;
                 smallerList = OriginalList;

             }
         } else {
             if (biggerListHead == NULL) {
                 biggerListHead = OriginalList;
                 biggerList = OriginalList;
             } else {
                 biggerList -> next = OriginalList;
                 biggerList = OriginalList;
             }
         }
         OriginalList = OriginalList -> next;
     }

     if (smallerListHead == NULL) smallerListHead = biggerListHead;
     else smallerList -> next = biggerListHead;
     if (biggerListHead != NULL) biggerList -> next = NULL;

     return smallerListHead;

 }

 Time : O(length of List)
 Space : O(1)


 https://leetcode.com/problems/partition-list/