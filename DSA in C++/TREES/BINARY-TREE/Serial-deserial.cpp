#include <bits/stdc++.h>
using namespace std;

/* Tree Node */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

/* Codec Class */
class Codec {
public:

    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        string res="";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();

            if(x==NULL)
            {
                res += "#,";
            }
            else
            {
                res += to_string(x->val) + ",";
                q.push(x->left);
                q.push(x->right);
            }
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;

        stringstream ss(data);
        string s;

        getline(ss,s,',');
        TreeNode* root = new TreeNode(stoi(s));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* x = q.front();
            q.pop();

            // LEFT
            if(!getline(ss,s,',')) break;
            if(s != "#")
            {
                x->left = new TreeNode(stoi(s));
                q.push(x->left);
            }

            // RIGHT
            if(!getline(ss,s,',')) break;
            if(s != "#")
            {
                x->right = new TreeNode(stoi(s));
                q.push(x->right);
            }
        }
        return root;
    }
};

/* Build Tree from Level Order Input */
TreeNode* buildTree(string input) {
    if(input.size() == 0) return NULL;

    stringstream ss(input);
    string s;

    getline(ss, s, ',');
    if(s == "#") return NULL;

    TreeNode* root = new TreeNode(stoi(s));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // LEFT
        if(!getline(ss, s, ',')) break;
        if(s != "#") {
            curr->left = new TreeNode(stoi(s));
            q.push(curr->left);
        }

        // RIGHT
        if(!getline(ss, s, ',')) break;
        if(s != "#") {
            curr->right = new TreeNode(stoi(s));
            q.push(curr->right);
        }
    }
    return root;
}

/* Print Level Order */
void printLevel(TreeNode* root) {
    if(!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* x = q.front();
        q.pop();

        if(x == NULL) {
            cout << "# ";
            continue;
        }

        cout << x->val << " ";
        q.push(x->left);
        q.push(x->right);
    }
}

/* MAIN */
int main() {
    Codec ser, deser;

    cout << "Enter tree in level order (use # for NULL, comma separated):\n";

    string input;
    cin >> input;

    // Build tree
    TreeNode* root = buildTree(input);

    // Serialize
    string serialized = ser.serialize(root);
    cout << "\nSerialized: " << serialized << endl;

    // Deserialize
    TreeNode* newRoot = deser.deserialize(serialized);

    // Print tree
    cout << "\nTree after Deserialization (level order): ";
    printLevel(newRoot);

    return 0;
}