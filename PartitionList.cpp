/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *lessHead = NULL, *moreHead = NULL, *temp;
        temp = head;
        ListNode *lessTemp = lessHead;
        ListNode *moreTemp = moreHead;
        int lessFlag = 0, moreFlag = 0;
        while(temp!=NULL)
        {
            ListNode *newNode = new ListNode(temp->val);
            if(temp->val < x)
            {
                if(!lessFlag)
                {
                    lessHead = newNode;
                    lessTemp = newNode;
                    lessFlag = 1;
                }
                else
                {
                    lessTemp->next = newNode;
                    lessTemp = lessTemp->next;
                }
            }
            else
            {
                if(!moreFlag)
                {
                    moreTemp = newNode;
                    moreHead = newNode;
                    moreFlag = 1;
                }
                else
                {
                    moreTemp->next = newNode;
                    moreTemp = moreTemp->next;
                }
            }
            temp = temp->next;
        }
        
        if(lessHead!=NULL)
        {            
            lessTemp->next = moreHead;            
            return lessHead;
        }
        return moreHead;
        
    }
};