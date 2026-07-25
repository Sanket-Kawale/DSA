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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)      return head;

        ListNode* temp = head;
        ListNode* curr = head;
        int n = 1;
        ListNode* dummy = NULL;

        while(temp->next){
            temp=temp->next;
            n++;
        }
        k = k%n;
        if(k==n)            return head;
        int i = n-k;
        while(--i){
            curr = curr->next;
        }
        temp->next = head;
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};