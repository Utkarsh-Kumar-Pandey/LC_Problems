//My approach
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenstore = even;
        ListNode* oddstore = odd;

        while (even != NULL && even->next != NULL) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenstore;
        return oddstore;
    }
};
