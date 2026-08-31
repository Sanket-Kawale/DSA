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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return {-1,-1};
        }

        ListNode* curr = head->next;
        ListNode* forward = curr->next;
        ListNode* prev = head;
        ListNode* temp = NULL;
        vector<int> ans;
        int index = 1;

        while(curr && curr->next){
            index++; 

            if(curr->val > forward->val && curr->val > prev->val){
                ans.push_back(index);
            }
            if(curr->val < forward->val && curr->val < prev->val){
                ans.push_back(index);
            }
            prev = curr;
            curr = forward;
            forward = forward->next; 
        }
        
        sort(ans.begin(), ans.end());

        if(ans.size() < 2){
            return {-1, -1};
        }
        int mini = INT_MAX;
        int maxi = 0;
        

        for(int i=0; i<ans.size()-1; i++){
            if((ans[i+1] - ans[i]) < mini){
                mini = ans[i+1] - ans[i];
            }
        }
        maxi = ans[ans.size()-1] - ans[0];
        return {mini, maxi};
    } 
};