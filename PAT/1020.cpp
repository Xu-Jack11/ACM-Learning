#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    vector<int> postorder(n),inorder(n),levelorder(n);
    for(int i=0;i<n;i++)
        cin>>postorder[i];
    for(int i=0;i<n;i++)
        cin>>inorder[i];
    // build the tree from postorder and inorder
    struct Node {
        int val;
        Node *left, *right;
        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    function<Node*(int,int,int,int)> build = [&](int il, int ir, int pl, int pr) -> Node* {
        if (il > ir) return nullptr;
        int rootVal = postorder[pr];
        Node* root = new Node(rootVal);
        int idx = find(inorder.begin() + il, inorder.begin() + ir + 1, rootVal) - inorder.begin();
        int leftSize = idx - il;
        root->left  = build(il, idx - 1,         pl,       pl + leftSize - 1);
        root->right = build(idx + 1, ir, pl + leftSize, pr - 1);
        return root;
    };

    Node* root = build(0, n - 1, 0, n - 1);

    // traverse the tree in level order
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        Node* u = q.front(); q.pop();
        levelorder[cnt++] = u->val;
        if (u->left)  q.push(u->left);
        if (u->right) q.push(u->right);
    }

    // output
    for (int i = 0; i < n; i++) {
        cout << levelorder[i] << (i + 1 < n ? ' ' : '\n');
    }
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
