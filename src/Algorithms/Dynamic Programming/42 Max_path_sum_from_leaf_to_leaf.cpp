class Solution {
private:
int res;

int Solve(Node* root) {
    if (root == NULL)
        return 0;

    int l = Solve(root->left);
    int r = Solve(root->right);

    int temp;
    if (root->left && root->right) {
        res = max(res, l + r + root->data);
        temp = root->data + max(l, r);
    }
    else if (root->left)
        temp = root->data + l;
    else if (root->right)
        temp = root->data + r;
    else
        temp = root->data;
}

    return temp;
}

int maxPathSum(Node* root)
{
    // code here
    res = INT_MIN;
    Solve(root);
    return res;
}
