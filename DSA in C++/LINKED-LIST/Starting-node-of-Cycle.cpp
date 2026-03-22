#include <bits/stdc++.h>
using namespace std;

/* Definition for singly-linked list */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // start of cycle
            }
        }
        return NULL;
    }
};

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        cout << -1;
        return 0;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int pos;   // index where cycle starts
    cin >> pos;

    vector<ListNode*> nodes;

    // create nodes
    for(int i = 0; i < n; i++)
        nodes.push_back(new ListNode(arr[i]));

    // connect nodes linearly
    for(int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];

    // create cycle if pos != -1
    if(pos != -1)
        nodes[n - 1]->next = nodes[pos];

    Solution obj;
    ListNode* result = obj.detectCycle(nodes[0]);

    if(result)
        cout << result->val;   // print starting node value
    else
        cout << -1;

    return 0;
}