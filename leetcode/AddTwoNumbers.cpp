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
            ListNode* result  = NULL;
            ListNode* curNode = result;
            ListNode* tmp     = NULL;
            int nCarryOver    = 0;
            int nVal          = 0;
            while(l1 && l2)
            {
                 if((nVal = (l1->val + l2->val + nCarryOver)) >= 10)
                 {
                     nCarryOver = 1;
                     nVal -= 10;
                 }
                 else
                 {
                     nCarryOver = 0;
                 }
                 
                 if(curNode == NULL)
                 {
                     result = curNode = new ListNode(nVal);
                 }
                 else
                 {
                     //tmp = new ListNode(nVal + nCarryOver);
                     curNode->next = new ListNode(nVal);
                     curNode       = curNode->next;
                 }
                 l1 = l1->next;
                 l2 = l2->next;
            }
            
            while(l1)
            {
                 if((nVal = (l1->val  + nCarryOver)) >= 10)
                 {
                     nCarryOver = 1;
                     nVal -= 10;
                 }
                 else
                 {
                     nCarryOver = 0;
                 }
                 
                 curNode->next = new ListNode(nVal);
                 curNode       = curNode->next;
                  l1           = l1->next;
                 
            }
            
            while(l2)
            {
                 if((nVal = (l2->val  + nCarryOver)) >= 10)
                 {
                     nCarryOver = 1;
                     nVal -= 10;
                 }
                 else
                 {
                     nCarryOver = 0;
                 }
                 
                 curNode->next = new ListNode(nVal);
                 curNode       = curNode->next;
                  l2           = l2->next;
            }
            
            if(l1==NULL && l2==NULL &&nCarryOver==1)
            {
                curNode->next = new ListNode(nCarryOver);
            }
            
            return  result;
    }
};

