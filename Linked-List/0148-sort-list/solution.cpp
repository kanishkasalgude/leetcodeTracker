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
    ListNode *findMiddle(ListNode* head){
        ListNode *front = head->next;
        ListNode *back = head;
        while(front != NULL && front->next != NULL){
            back = back->next;
            front = front->next->next;
        }

        return back;
    }

    ListNode *merge2List(ListNode* l1, ListNode *l2){
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                temp->next = l1;
                temp = l1;
                l1 = l1->next;
            }
            else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
            }
        }

        if(l1) temp->next = l1;
        else temp->next = l2;

        return dummy->next;
    }


    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *mid = findMiddle(head);
        ListNode *righthead = mid->next;
        mid->next = NULL;
        ListNode *lefthead = head;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge2List(lefthead, righthead);
    }
};
