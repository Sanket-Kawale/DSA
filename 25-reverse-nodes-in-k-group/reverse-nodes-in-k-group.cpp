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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        int count = 0;
        ListNode* curr = head;
        while(curr && count != k){
            curr = curr->next;
            count++;
        }

        if(count == k){
            curr = reverseKGroup(curr, k);

            while(count > 0){
                ListNode* temp = head->next;
                head->next = curr;
                curr = head;
                head = temp;
                count--;
            }
            head = curr;
        }
        return head;
    }
};