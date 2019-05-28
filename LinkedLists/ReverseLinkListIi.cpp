ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if (A == NULL || B == C) return A;
    ListNode *head = A;
    ListNode *prev = NULL;
    ListNode *first = NULL, *second=NULL;
    
    int i=0;
    ListNode *p = A;
    
    while (p != NULL){
        i++;
        
        if (i == B-1){
            prev = p;
        }
        
        if (i == B){
            first = p;
        }
        
        if (i == C){
            second = p->next;
            p->next = NULL;
        }
        
        p = p->next;
    }
    
    ListNode *temp1 = first;
    ListNode *temp2 = temp1->next;
    temp1->next = second;
    
    while (temp2 != NULL && temp1 != NULL){
        ListNode *temp3 = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
    }
    
    if (prev != NULL){
        prev->next = temp1;
    }
    else{
        return temp1;
    }
    
    return head;
}
