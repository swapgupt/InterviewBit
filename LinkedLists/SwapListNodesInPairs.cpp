ListNode* Solution::swapPairs(ListNode* A) {
    if (A == NULL || A->next == NULL) return A;
    
    ListNode* node = A;
    ListNode* prev = NULL;
    ListNode* head = A->next;
    
    while (node != NULL && node->next != NULL){
        if (prev != NULL){
            prev->next = node->next;
        }
        
        ListNode* temp = node->next->next;
        node->next->next = node;
        prev = node;
        node = temp;
    }
    
    prev->next = node;
    
    return head;
}