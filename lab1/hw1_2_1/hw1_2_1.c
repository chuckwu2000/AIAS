/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* 
    error encount:
        error1: forget to malloc memory to pointer
        error2: handle empty case error
 */
   
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode* now = (struct ListNode*)malloc(sizeof(struct ListNode));
    //Store link list's header pointer in head
    struct ListNode* head = now;
    
    //For empty list1 or list2
    if(list1 == NULL)
    {
        return list2;
    }
    if(list2 == NULL)
    {
        return list1;
    }
    
    //Keep going through list1 and list2 until either of them can't go on
    while(list1 != NULL && list2 != NULL)
    {
        //Create tmp as a new node
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        
        if(list1->val <= list2->val)
        {
            //Update tmp as current list1, and list1 go to next one
            tmp->val = list1->val;
            tmp->next = NULL;
            list1 = list1->next;
        }
        else
        {
            //Update tmp as current list2, and list2 go to next one
            tmp->val = list2->val;
            tmp->next = NULL;
            list2 = list2->next;
        }
        //Insert tmp behind now node, and now go to next one
        now->next = tmp;
        now = tmp;
    }
    
    //Insert all of the remainder node in list1 behind now node
    while(list1 != NULL)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = list1->val;
        tmp->next = NULL;
        list1 = list1->next;
        now->next = tmp;
        now = tmp;
    }
    
    //Insert all of the remainder node in list2 behind now node
    while(list2 != NULL)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = list2->val;
        tmp->next = NULL;
        list2 = list2->next;
        now->next = tmp;
        now = tmp;
    }
    return head->next;
}
