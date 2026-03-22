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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                return true;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        cout << "false";
        return 0;
    }

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int pos;   // position where cycle starts
    cin >> pos;

    vector<ListNode*> nodes;

    // create nodes
    for(int i = 0; i < n; i++)
        nodes.push_back(new ListNode(arr[i]));

    // link nodes
    for(int i = 0; i < n - 1; i++)
        nodes[i]->next = nodes[i + 1];

    // create cycle if pos != -1
    if(pos != -1)
        nodes[n - 1]->next = nodes[pos];

    Solution obj;
    bool result = obj.hasCycle(nodes[0]);

    if(result)
        cout << "true";
    else
        cout << "false";

    return 0;
}