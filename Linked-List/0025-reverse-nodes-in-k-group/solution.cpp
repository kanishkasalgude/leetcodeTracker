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
    ListNode *findknode(ListNode *temp, int k){
        k -= 1;
        while(temp != NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode *reversePart(ListNode *temp){
        if(temp == NULL || temp->next == NULL) return temp;
        ListNode *prev = NULL;
        ListNode *curr = temp;
        ListNode *nextNode = temp->next;
        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prevnode = NULL;
        ListNode *nextNode = NULL;
        while(temp != NULL){
            ListNode *knode = findknode(temp, k);
            if(knode == NULL) 
            {
                if(prevnode) prevnode->next = temp;
                break;
            }else{
                nextNode = knode->next;
                knode->next = NULL;
                reversePart(temp);
                if(temp == head){
                    head = knode;
                }else{
                    prevnode->next = knode;
                }
            }
            prevnode = temp;
            temp = nextNode;
        }
        return head;
    }
};
