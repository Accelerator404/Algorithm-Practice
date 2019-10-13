/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* thisPtr = new ListNode(0);
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2 != NULL){
            thisPtr->val = l2->val;
            thisPtr->next = addTwoNumbers(NULL,l2->next);
        }
        else if(l1 != NULL && l2 == NULL){
            thisPtr->val = l1->val;
            thisPtr->next = addTwoNumbers(l1->next,NULL);
        }
        else{
            int exceed = (l1->val+l2->val)/10;
            thisPtr->val = (l1->val+l2->val)%10;
            thisPtr->next = addTwoNumbers(l1->next,l2->next);
            if(exceed > 0){
                ListNode* token = new ListNode(exceed);
                thisPtr->next = addTwoNumbers(thisPtr->next,token);
            }
        }
        return thisPtr;
    }
};
