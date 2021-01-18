ListNode* addTwoNumbers(ListNode* firstNumber, ListNode* secondNumber) {
        
        if(firstNumber==NULL) return secondNumber;
        if(secondNumber==NULL) return firstNumber;
        
        ListNode* thirdNumberHead=NULL, *thirdNumberIterator;
         
        int carry=0;
        
        while(firstNumber!=NULL && secondNumber!=NULL)
        {
            firstNumber->val+=carry + secondNumber->val;
            carry=firstNumber->val / 10;
            firstNumber->val%=10;
            if(thirdNumberHead==NULL)
            {
            	thirdNumberHead=firstNumber;
            	thirdNumberIterator=thirdNumberHead;
            }
            else
            {
            	thirdNumberIterator->next=firstNumber;
            	thirdNumberIterator=firstNumber;
            }

            firstNumber=firstNumber->next;
            secondNumber=secondNumber->next;
        }

        while(firstNumber!=NULL)
        {
        	firstNumber->val+=carry;
        	carry=firstNumber->val/10;
        	firstNumber->val%=10;
        	thirdNumberIterator->next=firstNumber;
        	thirdNumberIterator=firstNumber;
        	firstNumber=firstNumber->next;
        }
        
        firstNumber=secondNumber;
        while(firstNumber!=NULL)
        {
        	firstNumber->val+=carry;
        	carry=firstNumber->val/10;
        	firstNumber->val%=10;
        	thirdNumberIterator->next=firstNumber;
        	thirdNumberIterator=firstNumber;
        	firstNumber=firstNumber->next;
        }

       
        
        while(carry)
        {
        	ListNode* tempNode= new ListNode(carry%10);
        	thirdNumberIterator->next=tempNode;
        	thirdNumberIterator=tempNode;
        	carry/=10;
        }
        
        return thirdNumberHead;
        
        
        
        
        
        
    }