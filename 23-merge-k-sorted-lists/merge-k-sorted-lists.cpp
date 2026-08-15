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
    struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // '>' creates a min-heap (smallest value on top)
     }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(auto l:lists){
            if(l){
                pq.push(l);
            }
        }

        ListNode* ans = new ListNode();
        ListNode* dummy = ans;
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr->next) pq.push(curr->next);
            dummy->next = curr;
            dummy = dummy->next;
        }
        return ans->next;
    }
};