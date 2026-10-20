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
        if(head == NULL || head->next == NULL) return head;
        if(k == 0) return head;
        int length = 1;
        ListNode *tail = head;
        while(tail->next != NULL){
            length++;
            tail = tail->next;
        }
        if(k % length == 0) return head;
        k = k % length;
        ListNode *temp = head;
        int cnt = 1;
        while(cnt < (length - k)){
            temp = temp->next;
            cnt++;
        }
        tail->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
