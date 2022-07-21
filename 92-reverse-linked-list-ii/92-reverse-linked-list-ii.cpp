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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<int>st;
        ListNode* curr= head;
        ListNode* pre= head;
        
        for(int i=0;i<left-1; i++){
            curr=curr->next;
            pre=pre->next;
        }
        for(int i=0;i<= right-left; i++){
            st.push(curr->val);
            curr=curr->next;
        }
        for(int i=0;i<= right-left; i++){
            pre->val=st.top();
            st.pop();
            pre=pre->next;
        }
        return head;
    }
};