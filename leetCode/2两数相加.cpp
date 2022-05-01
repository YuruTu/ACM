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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        queue<int> result;
        bool flag = false;/// ÊÇ·ñ½øÎ»
        while ((nullptr != l1) || (nullptr != l2)) {
            int val1, val2;
            if (nullptr == l1) {
                val1 = 0;
            }
            else {
                val1 = l1->val;
            }
            if (nullptr == l2) {
                val2 = 0;
            }
            else {
                val2 = l2->val;
            }
            int temp = val1 + val2;
            if (flag)
                ++temp;
            if (temp > 9) {
                flag = true;
                result.push(temp - 10);
            }
            else {
                flag = false;
                result.push(temp);
            }
            if (nullptr != l1)
                l1 = l1->next;
            if (nullptr != l2)
                l2 = l2->next;
        }
        if (flag) {
            result.push(1);
        }
        ListNode* head = new ListNode;
        head->val = result.front();
        result.pop();
        ListNode* cur = head;
        while (!result.empty()) {
            cur->next = new ListNode;
            cur = cur->next;
            cur->val = result.front();
            result.pop();
        }

        return head;
    }
};